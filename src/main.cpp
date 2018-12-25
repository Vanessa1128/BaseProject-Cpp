#include <stdio.h>
#include <stdlib.h>
#include "main.h"

///////////////////////////////////////////////
///		    junk�����|�����ӡ����ͽY��������		  	 ///
/*
���ѣ��@�e������朽Y���� Lindked List ���p��ѭ�h��
���磺 a <-> b <-> c <-> d ����a��dδ����a->prev �� a �Լ���d->next �� NULL
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
///		    *ӛ��* ���@�e��ǰ����һ�� ����ʽ		  	 ///
landlord* landlordBuild(); // ���|�Y�ώ쌧��
house* houseBuild(); // �����Y�ώ쌧��
house* generate_hou(); // �a�����ӹ��c(node)
landlord* generate_lan(); // �a�����|���c(node)
int printHouse(house*, landlord*); // ӡ�����Ӵ��С��x��鿴�YӍ
int houseFilter(house*, landlord*); // ݔ��l�� & �Y�x����

///////////////////////////////////////////////

int main(){
    //show�x��


	//switch���� ����������
	//1.login
	//2.create account
	//3.quit
	//4.���ܴa


    return 0;
}

///////////////////////////////////////////////
/// ����ʽ��		    �a�����ӹ��c(node)		  	 ///
house* generate_hou(){
    house *item = NULL;
    item = (house*)malloc(sizeof(house));
    item->next = NULL;
    item->prev = NULL;

    return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ����ʽ��		    �a�����|���c(node)		  	 ///
landlord* generate_lan(){
    landlord *item = NULL;
    item = (landlord*)malloc(sizeof(landlord));
    item->next = NULL;
    item->prev = NULL;

    return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ����ʽ��		    ӡ�����Ӵ��С��x��鿴�YӍ		  	 ///
int printHouse(house *head_hou, landlord *head_lan){ /* �����������᣺ӡ�����Ӵ��С��x��鿴�YӍ */

    char name[15];
    int num;
    house *current_hou;
    landlord *current_lan;

    /* ӡ�����Ӵ��� */
    printf("||> ��������x�񣬷��ϗl���ķ����У� \n");
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

    /* �鿴���ӵ�Ԕ���YӍ */
    printf("||> Ոݔ�뷿�|����&��̖�Բ鿴Ԕ���YӍ(ex. \"Joe 0\"). \n|>> ");
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

    printf("||>���x��ķ��ӣ�\n");
    printf("|====================================================================\n");
    printf("||>> Landlord Infomation: \n |> Name: %-15s Star: %-2d Number of house: %-2d \n |> Contact1: %-30s \n |> Contact2: %-30s\n",
           current_lan->LandlordName, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);

    printf("||>> House Infomation: \n |> Area:%-7g Rent:%-7g OtherCost:%-7g \n |> Address:%-30s \n |> PeopleNumber:%-2d Network:%-13s RoomType:%-10s Pet:%-5s \n |> Facilities:%-100s\n",
            current_hou->Area,
            current_hou->Rent,          current_hou->OtherCost,  current_hou->Address,
            current_hou->PeopleNumber,  current_hou->Network,    current_hou->RoomType,
            current_hou->Pet,           current_hou->Facilities);
    printf("|====================================================================\n");

    /* �Ƿ����ºY�x�Д� */
    int state = 0;
    printf("||> �Ƿ����ºY�x���ӣ�0����2���� (ex. \"2\") \n|>> ");
    scanf("%d", &state);
    fflush(stdin);
    while(state != 0 && state != 2){
        printf("||> �Ƿ����ºY�x���ӣ�0����2���� (ex. \"0\") \n|>> ");
        scanf("%d", &state);
        fflush(stdin);
    }
    return state;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ����ʽ��		    ݔ��l�� & �Y�x����		  	 ///
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

    printf("\n||> �gӭ�M���ҷ���ϵ�y�� <|\n");
    printf("||> Ո��Ҫ��ݔ��Y�x�l�� <|\n");
    printf("||> ���пɺY�x�l����ƺ�������⡢��ס�˔����W·Ʒ�|���׷�/�ŷ����ɷ��B��.\n");
    printf("|=======================================================================\n");

    printf("||> �Y�xƺ�����ǣ�1����0 \n|>> "); // �Y�x������
    scanf("%d", &filter[0]);
    if(filter[0]){
        printf("||> Ոݔ�빠��(ex. \"10 20\")(��<��): \n|>> ");
        scanf("%lf %lf", &filter0_a, &filter0_b);
        fflush(stdin);
        /* �ж�ݔ����Ч */
        while(filter0_a<0 || filter0_b<0 || filter0_a>=filter0_b){
            printf("||> Ոݔ�����_�Ĺ���(ex. \"10 20\")(��<��): \n|>> ");
            scanf("%lf %lf", &filter0_a, &filter0_b);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->Area<filter0_a || current_hou->Area>filter0_b){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // ��һ���c����
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // ����ĩβ
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // �����_�^
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // �������g
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
    printf("||> �Y�x���⣿�ǣ�1����0 \n|>> "); // �Y�x������
    scanf("%d", &filter[1]);
    if(filter[1]){
        printf("||> Ոݔ�빠��(ex. \"3000 4000\")(��<��): \n|>> ");
        scanf("%lf %lf", &filter1_a, &filter1_b);
        fflush(stdin);
        /* �ж�ݔ����Ч */
        while(filter1_a<0 || filter1_b<0 || filter1_a>=filter1_b){
            printf("||> Ոݔ�����_�Ĺ���(ex. \"3000 4000\")(��<��): \n|>> ");
            scanf("%lf %lf", &filter1_a, &filter1_b);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->Rent<filter1_a || current_hou->Rent>filter1_b){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // ��һ���c����
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // ����ĩβ
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // �����_�^
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // �������g
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
    printf("||> �Y�x��ס�˔����ǣ�1����0 \n||> "); // �Y�x������
    scanf("%d", &filter[2]);
    if(filter[2]){
        printf("||> Ոݔ�빠��(ex. \"1 1\")(��<=��): \n|>> ");
        scanf("%d %d", &filter2_a, &filter2_b);
        fflush(stdin);
        /* �ж�ݔ����Ч */
        while(filter2_a<=0 || filter2_b<=0 || filter2_a>filter2_b){
            printf("||> Ոݔ�����_�Ĺ���(ex. \"1 1\")(��<=��): \n|>> ");
            scanf("%d %d", &filter2_a, &filter2_b);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->PeopleNumber<filter2_a || current_hou->PeopleNumber>filter2_b){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // ��һ���c����
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // ����ĩβ
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // �����_�^
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // �������g
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
    printf("||> �Y�x�W·Ʒ�|���ǣ�1����0 \n|>> "); // �Y�x�����x
    scanf("%d", &filter[3]);
    if(filter[3]){
        printf("||> �o�W·��No���оW·,20M��20M���оW·,60M��60M���оW·,100M��100M(ex. \"20M\") \n|>> ");
        scanf("%s", filter3);
        fflush(stdin);
        /* �ж�ݔ����Ч */
        while(strcasecmp(filter3, "No") && strcasecmp(filter3, "20M") && strcasecmp(filter3, "60M") && strcasecmp(filter3, "100M") ){
            printf("||> Ոݔ�����_��ָ��(ex. \"No\") \n|>> ");
            scanf("%s", filter3);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if( strncasecmp(current_hou->Network, filter3, 2) ){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // ��һ���c����
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // ����ĩβ
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // �����_�^
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // �������g
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
    printf("||> �Y�x�׷�/�ŷ����ǣ�1����0 \n|>> "); // �Y�x���p�x
    scanf("%d", &filter[4]);
    if(filter[4]){
        printf("||> �׷���Suite���ŷ���Share(ex. \"Suite\") \n|>> ");
        scanf("%s", filter4);
        /* �ж�ݔ����Ч */
        while(strcasecmp(filter4, "Suite") && strcasecmp(filter4, "Share") ){
            printf("||> Ոݔ�����_��ָ��(ex. \"Suite\") \n|>> ");
            scanf("%s", filter4);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if(current_hou->RoomType[1] != filter4[1]){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // ��һ���c����
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // ����ĩβ
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // �����_�^
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // �������g
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
    printf("||> �Y�x�ɷ��B�����ǣ�1����0 \n|>> "); // �Y�x���p�x
    scanf("%d", &filter[5]);
    if(filter[5]){
        printf("||> ���B���Yes�������B���No(ex. \"No\") \n|>> ");
        scanf("%s", filter5);
        /* �ж�ݔ����Ч */
        while(strcasecmp(filter5, "Yes") && strcasecmp(filter5, "No") ){
            printf("||> Ոݔ�����_��ָ��(ex. \"No\") \n|>> ");
            scanf("%s", filter5);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_hou = head_hou;
        while(current_hou != NULL){

            if( strncasecmp(current_hou->Pet, filter5, 2) ){
                tempNode = current_hou;
                if(current_hou == head_hou && current_hou->next == NULL){ // ��һ���c����
                    head_hou = NULL; current_hou = NULL;
                } else if(current_hou->next == NULL){ // ����ĩβ
                    current_hou = current_hou->prev;
                    current_hou->next = NULL;
                    current_hou = NULL;
                } else if(current_hou == head_hou){ // �����_�^
                    head_hou = head_hou->next;
                    head_hou->prev = head_hou;
                    current_hou = head_hou;
                } else{ // �������g
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

    /* if �]�з��� */
    if(head_hou == NULL) {
        printf("||> �o����Ҫ��ķ��ӣ� <| \n");
        printf("||> �����M��ϵ�y�Y�x�� <| \n");
        return 2; // �����M��ϵ�y�Y�x
    }
    /* if �з��� */
    else {
        int state = printHouse(head_hou, head_lan); // ӡ�����ϗl�����ӡ��x��鿴�YӍ
        return state;
    }

}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ����ʽ��		    LandlordDatabase.txt�n�� ���|�Y�ώ쌧��		  	 ///

landlord* landlordBuild(){

    FILE *landlordFile;
    landlordFile = fopen("LandlordDatabase.txt", "r");
    if(landlordFile == NULL) {printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
    landlord *head_lan = NULL, *current_lan = NULL, *temp1;

    // ���}��λ̎�� structure
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
    // �h������һ�����N node
    current_lan = current_lan->prev;
    temp1 = current_lan->next;
    current_lan->next = NULL;
    free(temp1);

    // �yԇӡ�� landlord link list
    current_lan=head_lan;
    printf("\n�yԇӡ����\n");
    while(current_lan!=NULL){
        printf("%-15s %-2d %-2d %-2d %-30s %-30s\n", current_lan->LandlordName, current_lan->UserNumber, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);
        current_lan=current_lan->next;
    } printf("\n���Ϝyԇӡ��\n");

    // �P�ļ�
    fclose(landlordFile);

    /* �؂��ѽ����õ� head ���c */
    return head_lan;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ����ʽ��		    HouseDatabase.txt�n�� �����Y�ώ쌧��		  	 ///

house* houseBuild(){

    FILE *houseFile;
    houseFile = fopen("HouseDatabase.txt", "r");
    if(houseFile == NULL) {printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
    house *head_hou = NULL, *current_hou = NULL, *temp;

    // ���}��λ̎�� structure
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
    // �h������һ�����N node
    current_hou = current_hou->prev;
    temp = current_hou->next;
    current_hou->next = NULL;
    free(temp);

    // �yԇӡ�� house link list
    current_hou=head_hou;
    printf("\n�yԇӡ����\n");
    while(current_hou!=NULL){
        printf("%-5s %2d %-7g %-7g %-7g %-30s %-2d %-13s %-10s %-5s %-100s\n",
            current_hou->LandlordName,  current_hou->Number,     current_hou->Area,
            current_hou->Rent,          current_hou->OtherCost,  current_hou->Address,
            current_hou->PeopleNumber,  current_hou->Network,    current_hou->RoomType,
            current_hou->Pet,           current_hou->Facilities);
        current_hou = current_hou->next;
    } printf("\n���Ϝyԇӡ��\n");

    // �P�ļ�
    fclose(houseFile);

    /* �؂��ѽ����õ� head ���c */
    return head_hou;
}
///////////////////////////////////////////////

///////////////////////////////////////////////

///		    ����ʽ		  	 ///

///////////////////////////////////////////////
