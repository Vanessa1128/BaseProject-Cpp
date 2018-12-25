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

typedef struct roomerStruct{
    char RoomerName[15]; // name: 15 char max
    int UserNumber;
    int Star; // range: 1 - 10
    char Gender[10]; // gender: 10 char max
    int SleepTime;
    char School[40]; // school name: 40 char max
    char Nationality[20]; // country name: 20 char max
    char Habit[20]; // habit: 20 char max
    char Disease[20]; // disease: 20 char max

    struct roomerStruct *next, *prev;
} roomer;

///////////////////////////////////////////////


///////////////////////////////////////////////
///		    *ӛ��* ���@�e��ǰ����һ�� ����ʽ		  	 ///

// ���ø���ʽ
landlord* landlordBuild(); // ���|�Y�ώ쌧��
house* houseBuild(); // �����Y�ώ쌧��
roomer* roomerBuild(); // �����Y�ώ쌧��

// �ҷ���ϵ�y����ʽ
void findHouse(); // �ҷ���ϵ�y�M���c
house* generate_hou(); // �a�����ӹ��c(node)
landlord* generate_lan(); // �a�����|���c(node)
int printHouse(house*, landlord*); // ӡ�����Ӵ��С��x��鿴�YӍ
int houseFilter(house*, landlord*); // ݔ��l�� & �Y�x����

//������ϵ�y����ʽ
void findRoomer(); // ������ϵ�y�M���c
roomer* generate_roo(); // �a�����ѹ��c(node)
int printRoomer(roomer*); // ӡ�����Ѵ��С��x��鿴�YӍ
int roomerFilter(roomer*); // ݔ��l�� & �Y�x����

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
/// ���� ����ʽ��		    LandlordDatabase.txt�n�� ���|�Y�ώ쌧��		  	 ///
/// �����ø���ʽ���ҷ���ϵ�y

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
/// ���� ����ʽ��		    HouseDatabase.txt�n�� �����Y�ώ쌧��		  	 ///
/// �����ø���ʽ���ҷ���ϵ�y

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
/// ���� ����ʽ��		    RoomerDatabase.txt�n�� �����Y�ώ쌧��		  	 ///
/// �����ø���ʽ��������ϵ�y

roomer* roomerBuild(){ /* roomer �Y�ώ쌧���� Linked List */

    FILE *roomerFile;
    roomerFile = fopen("RoomerDatabase.txt", "r");
    if(roomerFile == NULL) {printf("Fail to open file!\n"); exit(EXIT_FAILURE); }

    roomer *head_roo = NULL, *current_roo = NULL, *temp1;

    // ���}��λ̎�� structure
    Junk junk;
    fscanf(roomerFile, "%s %s %s %s %s %s %s %s %s", junk.junk1, junk.junk2, junk.junk3, junk.junk4, junk.junk5, junk.junk6, junk.junk7, junk.junk8, junk.junk9);

    head_roo = generate_roo();
    head_roo->prev = head_roo;
    current_roo = head_roo;
    while(fscanf(roomerFile, "%s %d %d %s %d %s %s %s %s\n",
                 current_roo->RoomerName,   &current_roo->UserNumber,  &current_roo->Star,
                 current_roo->Gender,       &current_roo->SleepTime,    current_roo->School,
                 current_roo->Nationality,  current_roo->Habit,        current_roo->Disease) == 9){

        current_roo->next = generate_roo();
        current_roo->next->prev = current_roo;
        current_roo = current_roo->next;
    }
    // �h������һ�����N node
    current_roo = current_roo->prev;
    temp1 = current_roo->next;
    current_roo->next = NULL;
    free(temp1);

    // �yԇӡ�� landlord link list
    current_roo=head_roo;
    printf("\n�yԇӡ����\n");
    while(current_roo!=NULL){
        printf("%-15s %-2d %-2d %-10s %2d:00 %-40s %-20s %-20s %-20s\n",
               current_roo->RoomerName,   current_roo->UserNumber,  current_roo->Star,
               current_roo->Gender,       current_roo->SleepTime,   current_roo->School,
               current_roo->Nationality,  current_roo->Habit,       current_roo->Disease);
        current_roo=current_roo->next;
    } printf("\n���Ϝyԇӡ��\n");

    // �P�ļ�
    fclose(roomerFile);

    /* �؂��ѽ����õ� head ���c */
    return head_roo;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �ҷ���ϵ�y ����ʽ��		    �ҷ���ϵ�y�M���c		  	 ///
void findHouse(){
    house* head_hou = NULL;
    landlord* head_lan = NULL;

    /* �M�кY�x & �؂���B */
    // ��B 0���ɹ�&�˳���ʽ
    // ��B 2���ɹ�&���ºY�x
    int state = 2;
    while(state == 2){
        head_hou = houseBuild(); // ���� house linked list
        head_lan = landlordBuild(); // ���� landlord linked list
        state = houseFilter(head_hou, head_lan);
    }

    printf("||> �˳��ҷ���ϵ�y��\n");
    return;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �ҷ���ϵ�y ����ʽ��		    �a�����ӹ��c(node)		  	 ///
house* generate_hou(){
    house *item = NULL;
    item = (house*)malloc(sizeof(house));
    item->next = NULL;
    item->prev = NULL;

    return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �ҷ���ϵ�y ����ʽ��		    �a�����|���c(node)		  	 ///
landlord* generate_lan(){
    landlord *item = NULL;
    item = (landlord*)malloc(sizeof(landlord));
    item->next = NULL;
    item->prev = NULL;

    return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �ҷ���ϵ�y ����ʽ��		    ӡ�����Ӵ��С��x��鿴�YӍ		  	 ///
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
/// �ҷ���ϵ�y ����ʽ��		    ݔ��l�� & �Y�x����		  	 ///
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
/// ������ϵ�y ����ʽ��		    ������ϵ�y�M���c		  	 ///
void findRoomer(){
    roomer* head_roo = NULL;

    /* �M�кY�x & �؂���B */
    // ��B 0���ɹ�&�˳���ʽ
    // ��B 2���ɹ�&���ºY�x
    int state = 2;
    while(state == 2){
        head_roo = roomerBuild(); // ���� roomer linked list
        state = roomerFilter(head_roo);
    }

    printf("||> �˳�������ϵ�y��\n");
    return;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ������ϵ�y ����ʽ��		    �a�����ѹ��c(node)		  	 ///
roomer* generate_roo(){
    roomer *item = NULL;
    item = (roomer*)malloc(sizeof(roomer));
    item->next = NULL;
    item->prev = NULL;

    return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ������ϵ�y ����ʽ��		    ӡ�����Ѵ��С��x��鿴�YӍ		  	 ///
int printRoomer(roomer *head_roo){ /* �����������᣺ӡ�����Ѵ��С��x��鿴�YӍ */

    char name[15];
    roomer *current_roo;

    /* ӡ�����Ѵ��� */
    printf("||> ��������x�񣬷��ϗl���������У� \n");
    printf("|--------------------------------------------------------------------\n");
    current_roo = head_roo;
    while(current_roo != NULL){
        printf("||> Name:%-15s Star:%-2d Gender:%-10s \n |> SleepTime:%2d:00 \n |> School:%-40s \n |> Nationality:%-20s \n",
               current_roo->RoomerName,   current_roo->Star,
               current_roo->Gender,       current_roo->SleepTime,   current_roo->School,
               current_roo->Nationality);
        printf("|--------------------------------------------------------------------\n");
        current_roo = current_roo->next;
    }

    /* �鿴���ӵ�Ԕ���YӍ */
    printf("||> Ոݔ�����������Բ鿴Ԕ���YӍ(ex. \"Jack\"). \n|>> ");
    scanf("%s", name);
    current_roo = head_roo;
    while(current_roo != NULL){
        if(strcasecmp(current_roo->RoomerName, name) == 0) break;
        current_roo = current_roo->next;
    }

    printf("||>���x������ѣ�\n");
    printf("|====================================================================\n");
    printf("||>> Roomer Infomation: \n |> Name:%-15s Star:%-2d Gender:%-10s \n |> SleepTime:%2d:00 \n |> School:%-40s \n |> Nationality:%-20s \n |> Habit:%-20s \n |> Disease:%-20s \n",
               current_roo->RoomerName,   current_roo->Star,
               current_roo->Gender,       current_roo->SleepTime,   current_roo->School,
               current_roo->Nationality,  current_roo->Habit,       current_roo->Disease);
    printf("|====================================================================\n");

    /* �Ƿ����ºY�x�Д� */
    int state = 0;
    printf("||> �Ƿ����ºY�x���ѣ�0����2���� (ex. \"2\") \n|>> ");
    scanf("%d", &state);
    fflush(stdin);
    while(state != 0 && state != 2){
        printf("||> �Ƿ����ºY�x���ѣ�0����2���� (ex. \"0\") \n|>> ");
        scanf("%d", &state);
        fflush(stdin);
    }
    return state;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ������ϵ�y ����ʽ��		    ݔ��l�� & �Y�x����		  	 ///
int roomerFilter(roomer *head_roo){
    roomer *current_roo;
    roomer *tempNode;
    int cnt;
    int filter[4];
    char filter0[10];
    int filter1_a, filter1_b;
    char filter2;
    char filter3[15];

    for(cnt = 0; cnt < 4; cnt++) filter[cnt] = 0;

    printf("\n||> �gӭ�M��������ϵ�y�� <|\n");
    printf("||> Ո��Ҫ��ݔ��Y�x�l�� <|\n");
    printf("||> ���пɺY�x�l�����Ԅe��˯�ߕr�g���WУ������.\n");
    printf("|=======================================================================\n");

    printf("||> �Y�x�Ԅe���ǣ�1����0 \n|>> "); // �Y�x���p�x
    scanf("%d", &filter[0]);
    if(filter[0]){
        printf("||> �У�Male��Ů��Female(ex. \"Female\") \n|>> ");
        scanf("%s", filter0);
        fflush(stdin);
        /* �ж�ݔ����Ч */
        while(strcasecmp(filter0, "Male") && strcasecmp(filter0, "Female")){
            printf("||> Ոݔ�����_��ָ��(ex. \"male\") \n|>> ");
            scanf("%s", filter0);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_roo = head_roo;
        while(current_roo != NULL){

            if(strcasecmp(filter0, current_roo->Gender) ){
                tempNode = current_roo;
                if(current_roo == head_roo && current_roo->next == NULL){ // ��һ���c����
                    head_roo = NULL; current_roo = NULL;
                } else if(current_roo->next == NULL){ // ����ĩβ
                    current_roo = current_roo->prev;
                    current_roo->next = NULL;
                    current_roo = NULL;
                } else if(current_roo == head_roo){ // �����_�^
                    head_roo = head_roo->next;
                    head_roo->prev = head_roo;
                    current_roo = head_roo;
                } else{ // �������g
                    current_roo = current_roo->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_roo = current_roo->next;
                }
                free(tempNode);
            }
            else current_roo = current_roo->next;
        }
    }

    printf("|===============================\n");
    printf("||> �Y�x˯�ߕr�g���ǣ�1����0 \n|>> "); // �Y�x������
    scanf("%d", &filter[1]);
    if(filter[1]){
        printf("||> Ոݔ�빠��(�޶���20�c������6�c)(ex. \"20 1\"(20�c��1�c))(��߅�r�g�^��): \n|>> ");
        scanf("%d %d", &filter1_a, &filter1_b);
        fflush(stdin);
        /* �ж�ݔ����Ч */
        if(filter1_a<=6) filter1_a+=24; // may result in false time
        if(filter1_b<=6) filter1_b+=24; // may result in false time
        while(filter1_a<20 || filter1_a>30 || filter1_b<20 || filter1_b>30 || filter1_a>filter1_b){
            printf("||> Ոݔ�����_�Ĺ���(�޶���20�c������6�c)(ex. \"23 23\"(23�c��1�c))(��߅�r�g�^��) \n|>> ");
            scanf("%d %d", &filter1_a, &filter1_b);
            if(filter1_a<=6) filter1_a+=24; if(filter1_b<=6) filter1_b+=24;
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        int tempTime;
        current_roo = head_roo;

        while(current_roo != NULL){

            if(current_roo->SleepTime <= 6) tempTime = current_roo->SleepTime + 24;
            else tempTime = current_roo->SleepTime;

            if(tempTime<filter1_a || tempTime>filter1_b){
                tempNode = current_roo;
                if(current_roo == head_roo && current_roo->next == NULL){ // ��һ���c����
                    head_roo = NULL; current_roo = NULL;
                } else if(current_roo->next == NULL){ // ����ĩβ
                    current_roo = current_roo->prev;
                    current_roo->next = NULL;
                    current_roo = NULL;
                } else if(current_roo == head_roo){ // �����_�^
                    head_roo = head_roo->next;
                    head_roo->prev = head_roo;
                    current_roo = head_roo;
                } else{ // �������g
                    current_roo = current_roo->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_roo = current_roo->next;
                }
                free(tempNode);
            }
            else current_roo = current_roo->next;
        }
    }

    printf("|===============================\n");
    printf("||> �Y�x�WУ���ǣ�1����0 \n|>> "); // �Y�x�����x
    scanf("%d", &filter[2]);
    if(filter[2]){
        printf("||> ��״�W��F���|����W��T��̨�пƴ�S�����d��W��N���S��ƴ�O(ex. \"F\") \n|>> ");
        scanf("%c", &filter2);
        fflush(stdin);
        /* �ж�ݔ����Ч */
        while(filter2 != 'F' && filter2 != 'T' && filter2 != 'S' && filter2 != 'N' && filter2 != 'O'){
            printf("||> Ոݔ�����_��ָ��(ex. \"T\") \n|>> ");
            scanf("%c", &filter2);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_roo = head_roo;
        while(current_roo != NULL){

            if(filter2 != current_roo->School[0]){
                tempNode = current_roo;
                if(current_roo == head_roo && current_roo->next == NULL){ // ��һ���c����
                    head_roo = NULL; current_roo = NULL;
                } else if(current_roo->next == NULL){ // ����ĩβ
                    current_roo = current_roo->prev;
                    current_roo->next = NULL;
                    current_roo = NULL;
                } else if(current_roo == head_roo){ // �����_�^
                    head_roo = head_roo->next;
                    head_roo->prev = head_roo;
                    current_roo = head_roo;
                } else{ // �������g
                    current_roo = current_roo->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_roo = current_roo->next;
                }
                free(tempNode);
            }
            else current_roo = current_roo->next;
        }
    }

    printf("|===============================\n");
    printf("||> �Y�x�������ǣ�1����0 \n|>> "); // �Y�x�����x
    scanf("%d", &filter[3]);
    if(filter[3]){
        printf("||> ̨����Taiwan���R��������Malaysia���ձ���Japan��ӡ����������Indonesia�������e��Philippine���Ї���ꑣ�China(ex. \"Taiwan\") \n|>> ");
        scanf("%s", filter3);
        /* �ж�ݔ����Ч */
        while(strcasecmp(filter3, "Taiwan") && strcasecmp(filter3, "Malaysia") && strcasecmp(filter3, "Japan") && strcasecmp(filter3, "Indonesia") && strcasecmp(filter3, "Philippine") && strcasecmp(filter3, "China") ){
            printf("||> Ոݔ�����_��ָ��(ex. \"Suite\") \n|>> ");
            scanf("%s", filter3);
            fflush(stdin);
        }
        /* �h��������Ҫ���node */
        current_roo = head_roo;
        while(current_roo != NULL){

            if(strcasecmp(filter3, current_roo->Nationality) ){
                tempNode = current_roo;
                if(current_roo == head_roo && current_roo->next == NULL){ // ��һ���c����
                    head_roo = NULL; current_roo = NULL;
                } else if(current_roo->next == NULL){ // ����ĩβ
                    current_roo = current_roo->prev;
                    current_roo->next = NULL;
                    current_roo = NULL;
                } else if(current_roo == head_roo){ // �����_�^
                    head_roo = head_roo->next;
                    head_roo->prev = head_roo;
                    current_roo = head_roo;
                } else{ // �������g
                    current_roo = current_roo->prev;
                    tempNode->prev->next = tempNode->next;
                    tempNode->next->prev = tempNode->prev;
                    current_roo = current_roo->next;
                }
                free(tempNode);
            }
            else current_roo = current_roo->next;
        }
    }

    printf("|===============================\n");

    /* if �]�з��� */
    if(head_roo == NULL) {
        printf("||> �o����Ҫ��ķ��ӣ� <| \n");
        printf("||> �����M��ϵ�y�Y�x�� <| \n");
        return 2; // �����M��ϵ�y�Y�x
    }
    /* if �з��� */
    else {
        int state = printRoomer(head_roo); // ӡ�����ϗl�����ѡ��x��鿴�YӍ
        return state;
    }
}
///////////////////////////////////////////////

///////////////////////////////////////////////

///		    ����ʽ		  	 ///

///////////////////////////////////////////////
