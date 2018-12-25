#include <stdio.h>
#include <stdlib.h>
#include "main.h"

///////////////////////////////////////////////
///		    結構的宣告		  	 ///
typedef struct{
    char junk1[30]; char junk2[30]; char junk3[30];
    char junk4[30]; char junk5[30]; char junk6[30];
    char junk7[30]; char junk8[30]; char junk9[30];
    char junk10[30]; char junk11[30];
} Junk;

typedef struct landlordStruct{
    char LandlordName[15]; // name: 15 char max
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
///		    記得在這裡提前宣告一下 副程式		  	 ///
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
///		    .txt檔案的導入 稍後放上  at 19:32		  	 ///
///////////////////////////////////////////////

///////////////////////////////////////////////

///		    副程式		  	 ///

///////////////////////////////////////////////
