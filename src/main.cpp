#include <stdio.h>
#include <stdlib.h>
#include "main.h"

///////////////////////////////////////////////
///		    junk�����|�����ӡ����ͽY��������		  	 ///
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
///		    LandlordDatabase.txt�n�� ���|�Y�ώ쌧��		  	 ///

landlord* landlordBuild(){

    /* �����Y�ϵ�structure */
    FILE *landlordFile;
    landlordFile = fopen("LandlordDatabase.txt", "r");
    if(landlordFile == NULL) {printf("Fail to open file!\n"); exit(EXIT_FAILURE); }

    // landlord �Y�ώ쌧��
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
///		    HouseDatabase.txt�n�� �����Y�ώ쌧��		  	 ///

house* houseBuild(){

    /* �����Y�ϵ�structure */
    FILE *houseFile;
    houseFile = fopen("HouseDatabase.txt", "r");
    if(houseFile == NULL) {printf("Fail to open file!\n"); exit(EXIT_FAILURE); }

    // house �Y�ώ쌧��
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
