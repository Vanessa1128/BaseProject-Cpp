#include <stdio.h>
#include <stdlib.h>
#include "main.h"

///////////////////////////////////////////////
///		    junk、房東、房子、房客結構的宣告		  	 ///
/*
提醒：這裡建構的鏈結串列 Lindked List 是雙向不循環的
比如： a <-> b <-> c <-> d ，但a、d未串聯，a->prev 是 a 自己，d->next 是 NULL
*/
typedef struct{
    char junk1[30]; char junk2[30]; char junk3[30];
    char junk4[30]; char junk5[30]; char junk6[30];
    char junk7[30]; char junk8[30]; char junk9[30];
    char junk10[30]; char junk11[30];
} Junk;

typedef struct landlordStruct{
    char LandlordName[15]; // name: 15 char max
    int UserNumber;
    int Star; // range: 1 - 10
    int NumberOfHouse;
    char Contact1[30];
    char Contact2[30];

    struct landlordStruct *next, *prev;
} landlord;

typedef struct houseStruct{
    char LandlordName[15]; // name: 15 char max
    int Number; // number of landlord's house
    double Area;
    double Rent;
    double OtherCost;
    char Address[50]; // address: 50 char max
    int PeopleNumber; // people allowed to live in
    char Network[15]; // provide or not, 20/60/100M
    char RoomType[15]; // Share_Room or Suite
    char Pet[5]; // Yes or No
    char Facilities[100]; // facilities: 100 char max

    struct houseStruct *next, *prev;
} house;

///////////////////////////////////////////////


///////////////////////////////////////////////
///		    *記得* 在這裡提前宣告一下 副程式		  	 ///
landlord* landlordBuild(); // 房東資料庫導入
house* houseBuild(); // 房子資料庫導入
house* generate_hou(); // 產生房子節點(node)
landlord* generate_lan(); // 產生房東節點(node)
int printHouse(house*, landlord*); // 印出房子串列、選擇查看資訊
int houseFilter(house*, landlord*); // 輸入條件 & 篩選房子

///////////////////////////////////////////////

int main(){
    //show選單


	//switch寫法 對應各功能
	//1.login
	//2.create account
	//3.quit
	//4.改密碼


    return 0;
}

///////////////////////////////////////////////
/// 副程式：		    產生房子節點(node)		  	 ///
house* generate_hou(){
    house *item = NULL;
    item = (house*)malloc(sizeof(house));
    item->next = NULL;
    item->prev = NULL;

    return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 副程式：		    產生房東節點(node)		  	 ///
landlord* generate_lan(){
    landlord *item = NULL;
    item = (landlord*)malloc(sizeof(landlord));
    item->next = NULL;
    item->prev = NULL;

    return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 副程式：		    印出房子串列、選擇查看資訊		  	 ///
int printHouse(house *head_hou, landlord *head_lan){ /* 搜索到房子後：印出房子串列、選擇查看資訊 */

    char name[15];
    int num;
    house *current_hou;
    landlord *current_lan;

    /* 印出房子串列 */
    printf("||> 根據你的選擇，符合條件的房子有： \n");
    printf("|--------------------------------------------------------------------\n");
    current_hou = head_hou;
    while(current_hou != NULL){
        printf("||> Landlord:%-15s Number:%2d \n |> Area:%-7g Rent:%-7g OtherCost:%-7g \n |> Address:%-30s \n |> PeopleNumber:%-2d Network:%-13s RoomType:%-10s Pet:%-5s \n |> Facilities:%-100s\n",
            current_hou->LandlordName,  current_hou->Number,     current_hou->Area,
            current_hou->Rent,          current_hou->OtherCost,  current_hou->Address,
            current_hou->PeopleNumber,  current_hou->Network,    current_hou->RoomType,
            current_hou->Pet,           current_hou->Facilities);
        printf("|--------------------------------------------------------------------\n");
        current_hou = current_hou->next;
    }

    /* 查看房子的詳細資訊 */
    printf("||> 請輸入房東名字&序號以查看詳細資訊(ex. \"Joe 0\"). \n|>> ");
    scanf("%s %d", name, &num);
    current_lan = head_lan;
    while(current_lan != NULL){
        if(strcasecmp(current_lan->LandlordName, name) == 0) break;
        current_lan = current_lan->next;
    }
    current_hou = head_hou;
    while(current_hou != NULL){
        if(strcasecmp(current_hou->LandlordName, name)==0 && current_hou->Number==num) break;
        current_hou = current_hou->next;
    }

    printf("||>你選擇的房子：\n");
    printf("|====================================================================\n");
    printf("||>> Landlord Infomation: \n |> Name: %-15s Star: %-2d Number of house: %-2d \n |> Contact1: %-30s \n |> Contact2: %-30s\n",
           current_lan->LandlordName, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);

    printf("||>> House Infomation: \n |> Area:%-7g Rent:%-7g OtherCost:%-7g \n |> Address:%-30s \n |> PeopleNumber:%-2d Network:%-13s RoomType:%-10s Pet:%-5s \n |> Facilities:%-100s\n",
            current_hou->Area,
            current_hou->Rent,          current_hou->OtherCost,  current_hou->Address,
            current_hou->PeopleNumber,  current_hou->Network,    current_hou->RoomType,
            current_hou->Pet,           current_hou->Facilities);
    printf("|====================================================================\n");

    /* 是否重新篩選判斷 */
    int state = 0;
    printf("||> 是否重新篩選房子？0：否；2：是 (ex. \"2\") \n|>> ");
    scanf("%d", &state);
    fflush(stdin);
    while(state != 0 && state != 2){
        printf("||> 是否重新篩選房子？0：否；2：是 (ex. \"0\") \n|>> ");
        scanf("%d", &state);
        fflush(stdin);
    }
    return state;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 副程式：		    輸入條件 & 篩選房子		  	 ///
int houseFilter(house *head_hou, landlord *head_lan){
    house *current_hou;
    house *tempNode;
    int cnt;
    int filter[6];
    double filter0_a, filter0_b, filter1_a, filter1_b;
    int filter2_a, filter2_b;
    char filter3[5];
    char filter4[6];
    char filter5[5];
    for(cnt = 0; cnt < 6; cnt++) filter[cnt] = 0;

    printf("\n||> 歡迎進入找房子系統！ <|\n");
    printf("||> 請按要求輸入篩選條件 <|\n");
    printf("||> 所有可篩選條件：坪數、房租、入住人數、網路品質、套房/雅房、可否養寵.\n");
    printf("|=======================================================================\n");

    printf("||> 篩選坪數？是：1；否：0 \n|>> "); // 篩選：範圍
    scanf("%d", &filter[0]);
    if(filter[0]){
        printf("||> 請輸入範圍(ex. \"10 20\")(左<右): \n|>> ");
        scanf("%lf %lf", &filter0_a, &filter0_b);
        fflush(stdin);
        /* 判定輸入有效 */
        while(filter0_a<0 || filter0_b<0 || filter0_a>=filter0_b){
            printf("||> 請輸入正確的範圍(ex. \"10 20\")(左<右): \n|>> ");
            scanf("%lf %lf", &filter0_a, &filter0_b);
            fflush(stdin);
        }
        /* 刪除不符合要求的node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->Area<filter0_a || current_hou->Area>filter0_b){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // 單一節點串列
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // 串列末尾
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // 串列開頭
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // 串列中間
                    current_hou = current_hou->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_hou = current_hou->next;
                }
                free(tempNode);
            }
            else current_hou = current_hou->next;
        }
    }

    printf("|===============================\n");
    printf("||> 篩選房租？是：1；否：0 \n|>> "); // 篩選：範圍
    scanf("%d", &filter[1]);
    if(filter[1]){
        printf("||> 請輸入範圍(ex. \"3000 4000\")(左<右): \n|>> ");
        scanf("%lf %lf", &filter1_a, &filter1_b);
        fflush(stdin);
        /* 判定輸入有效 */
        while(filter1_a<0 || filter1_b<0 || filter1_a>=filter1_b){
            printf("||> 請輸入正確的範圍(ex. \"3000 4000\")(左<右): \n|>> ");
            scanf("%lf %lf", &filter1_a, &filter1_b);
            fflush(stdin);
        }
        /* 刪除不符合要求的node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->Rent<filter1_a || current_hou->Rent>filter1_b){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // 單一節點串列
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // 串列末尾
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // 串列開頭
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // 串列中間
                    current_hou = current_hou->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_hou = current_hou->next;
                }
                free(tempNode);
            }
            else current_hou = current_hou->next;
        }
    }

    printf("|===============================\n");
    printf("||> 篩選入住人數？是：1；否：0 \n||> "); // 篩選：範圍
    scanf("%d", &filter[2]);
    if(filter[2]){
        printf("||> 請輸入範圍(ex. \"1 1\")(左<=右): \n|>> ");
        scanf("%d %d", &filter2_a, &filter2_b);
        fflush(stdin);
        /* 判定輸入有效 */
        while(filter2_a<=0 || filter2_b<=0 || filter2_a>filter2_b){
            printf("||> 請輸入正確的範圍(ex. \"1 1\")(左<=右): \n|>> ");
            scanf("%d %d", &filter2_a, &filter2_b);
            fflush(stdin);
        }
        /* 刪除不符合要求的node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->PeopleNumber<filter2_a || current_hou->PeopleNumber>filter2_b){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // 單一節點串列
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // 串列末尾
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // 串列開頭
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // 串列中間
                    current_hou = current_hou->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_hou = current_hou->next;
                }
                free(tempNode);
            }
            else current_hou = current_hou->next;
        }
    }

    printf("|===============================\n");
    printf("||> 篩選網路品質？是：1；否：0 \n|>> "); // 篩選：多選
    scanf("%d", &filter[3]);
    if(filter[3]){
        printf("||> 無網路：No；有網路,20M：20M；有網路,60M：60M；有網路,100M：100M(ex. \"20M\") \n|>> ");
        scanf("%s", filter3);
        fflush(stdin);
        /* 判定輸入有效 */
        while(strcasecmp(filter3, "No") && strcasecmp(filter3, "20M") && strcasecmp(filter3, "60M") && strcasecmp(filter3, "100M") ){
            printf("||> 請輸入正確的指令(ex. \"No\") \n|>> ");
            scanf("%s", filter3);
            fflush(stdin);
        }
        /* 刪除不符合要求的node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if( strncasecmp(current_hou->Network, filter3, 2) ){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // 單一節點串列
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // 串列末尾
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // 串列開頭
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // 串列中間
                    current_hou = current_hou->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_hou = current_hou->next;
                }
                free(tempNode);
            }
            else current_hou = current_hou->next;
        }
    }

    printf("|===============================\n");
    printf("||> 篩選套房/雅房？是：1；否：0 \n|>> "); // 篩選：雙選
    scanf("%d", &filter[4]);
    if(filter[4]){
        printf("||> 套房：Suite；雅房：Share(ex. \"Suite\") \n|>> ");
        scanf("%s", filter4);
        /* 判定輸入有效 */
        while(strcasecmp(filter4, "Suite") && strcasecmp(filter4, "Share") ){
            printf("||> 請輸入正確的指令(ex. \"Suite\") \n|>> ");
            scanf("%s", filter4);
            fflush(stdin);
        }
        /* 刪除不符合要求的node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->RoomType[1] != filter4[1]){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // 單一節點串列
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // 串列末尾
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // 串列開頭
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // 串列中間
                    current_hou = current_hou->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_hou = current_hou->next;
                }
                free(tempNode);
            }
            else current_hou = current_hou->next;
        }
    }

    printf("|===============================\n");
    printf("||> 篩選可否養寵？是：1；否：0 \n|>> "); // 篩選：雙選
    scanf("%d", &filter[5]);
    if(filter[5]){
        printf("||> 可養寵物：Yes；不可養寵物：No(ex. \"No\") \n|>> ");
        scanf("%s", filter5);
        /* 判定輸入有效 */
        while(strcasecmp(filter5, "Yes") && strcasecmp(filter5, "No") ){
            printf("||> 請輸入正確的指令(ex. \"No\") \n|>> ");
            scanf("%s", filter5);
            fflush(stdin);
        }
        /* 刪除不符合要求的node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if( strncasecmp(current_hou->Pet, filter5, 2) ){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // 單一節點串列
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // 串列末尾
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // 串列開頭
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // 串列中間
                    current_hou = current_hou->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_hou = current_hou->next;
                }
                free(tempNode);
            }
            else current_hou = current_hou->next;
        }
    }

    printf("|===============================\n");

    /* if 沒有房子 */
    if(head_hou == NULL) {
        printf("||> 無符合要求的房子！ <| \n");
        printf("||> 重新進入系統篩選。 <| \n");
        return 2; // 重新進入系統篩選
    }
    /* if 有房子 */
    else {
        int state = printHouse(head_hou, head_lan); // 印出符合條件房子、選擇查看資訊
        return state;
    }

}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 副程式：		    LandlordDatabase.txt檔案 房東資料庫導入		  	 ///

landlord* landlordBuild(){

    FILE *landlordFile;
    landlordFile = fopen("LandlordDatabase.txt", "r");
    if(landlordFile == NULL) {printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
    landlord *head_lan = NULL, *current_lan = NULL, *temp1;

    // 標題欄位處理 structure
    Junk junk;
    fscanf(landlordFile, "%s %s %s %s %s %s", junk.junk1, junk.junk2, junk.junk3, junk.junk4, junk.junk5, junk.junk6);

    head_lan = generate_lan();
    head_lan->prev = head_lan;
    current_lan = head_lan;
    while(fscanf(landlordFile, "%s %d %d %d %s %s\n", current_lan->LandlordName, &current_lan->UserNumber,
                 &current_lan->Star, &current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2) == 6){

        current_lan->next = generate_lan();
        current_lan->next->prev = current_lan;
        current_lan = current_lan->next;
    }
    // 刪除最後一個多餘 node
    current_lan = current_lan->prev;
    temp1 = current_lan->next;
    current_lan->next = NULL;
    free(temp1);

    // 測試印出 landlord link list
    current_lan=head_lan;
    printf("\n測試印出：\n");
    while(current_lan!=NULL){
        printf("%-15s %-2d %-2d %-2d %-30s %-30s\n", current_lan->LandlordName, current_lan->UserNumber, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);
        current_lan=current_lan->next;
    } printf("\n以上測試印出\n");

    // 關文件
    fclose(landlordFile);

    /* 回傳已建立好的 head 節點 */
    return head_lan;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 副程式：		    HouseDatabase.txt檔案 房子資料庫導入		  	 ///

house* houseBuild(){

    FILE *houseFile;
    houseFile = fopen("HouseDatabase.txt", "r");
    if(houseFile == NULL) {printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
    house *head_hou = NULL, *current_hou = NULL, *temp;

    // 標題欄位處理 structure
    Junk junk;
    fscanf(houseFile, "%s %s %s %s %s %s %s %s %s %s %s", junk.junk1, junk.junk2, junk.junk3,
           junk.junk4, junk.junk5, junk.junk6, junk.junk7, junk.junk8, junk.junk9, junk.junk10, junk.junk11);

    head_hou = generate_hou();
    head_hou->prev = head_hou;
    current_hou = head_hou;
    while(fscanf(houseFile, "%s %d %lf %lf %lf %s %d %s %s %s %s\n",
                 current_hou->LandlordName,   &current_hou->Number,     &current_hou->Area,
                 &current_hou->Rent,          &current_hou->OtherCost,  current_hou->Address,
                 &current_hou->PeopleNumber,  current_hou->Network,     current_hou->RoomType,
                 current_hou->Pet,            current_hou->Facilities) == 11){

        current_hou->next = generate_hou();
        current_hou->next->prev = current_hou;
        current_hou = current_hou->next;
    }
    // 刪除最後一個多餘 node
    current_hou = current_hou->prev;
    temp = current_hou->next;
    current_hou->next = NULL;
    free(temp);

    // 測試印出 house link list
    current_hou=head_hou;
    printf("\n測試印出：\n");
    while(current_hou!=NULL){
        printf("%-5s %2d %-7g %-7g %-7g %-30s %-2d %-13s %-10s %-5s %-100s\n",
            current_hou->LandlordName,  current_hou->Number,     current_hou->Area,
            current_hou->Rent,          current_hou->OtherCost,  current_hou->Address,
            current_hou->PeopleNumber,  current_hou->Network,    current_hou->RoomType,
            current_hou->Pet,           current_hou->Facilities);
        current_hou = current_hou->next;
    } printf("\n以上測試印出\n");

    // 關文件
    fclose(houseFile);

    /* 回傳已建立好的 head 節點 */
    return head_hou;
}
///////////////////////////////////////////////

///////////////////////////////////////////////

///		    副程式		  	 ///

///////////////////////////////////////////////
