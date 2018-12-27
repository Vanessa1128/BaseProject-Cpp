
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string>

using namespace std;

///副程式宣告區
//////////////////////////////////////////////
void show_menu();///顯示功能選單
bool login(string acc,string pas);///登入驗證
bool create_account(string acc,string pas);///創建帳號
void mutator(string pas);///更改密碼
int get_user_number(string acc,string pas);///取得使用者編號
//////////////////////////////////////////////
///結構宣告
//////////////////////////////////////////////
typedef struct {
	char num[8]; char type[8]; char acc[8];
	char pas[8];
} account_database_title;//接收帳戶資料庫的第一行

typedef struct account{//帳號結構
	int num[8];
	char type;
	char account[20];
	char password[20];

	struct account *next, *previous;
} account_data;
//////////////////////////////////////////////
int main (void){

	int option = 0; //功能選項

	show_menu();//show選單
	for(;;){//無限迴圈直到輸入正確指令

		if(scanf(" %d", & option) ==1 && option <=4 && option >= 1){//當輸入為整數且為功能選項時跳出
            break;
		}

		else{//例外 顯示錯誤訊息 重新顯示選單 並清空輸入緩衝
            printf("無效的指令!!");
            system("pause");
            system("CLS");
            show_menu();
            fflush(stdin);
		}
	}


	if(option == 1){//登入驗證
	    system("CLS");
	    printf("==歡迎來到登入頁面==\n");
        printf("請輸入帳號:");
        string acc,pas;
        scanf(" %s",acc);
        system("CLS");
        printf("==歡迎來到登入頁面==\n");
        printf("請輸入帳號:%s\n",acc);
        printf("請輸入密碼:");
        scanf(" %s",pas);
        bool validate;
        validate = login(acc,pas);
        if(validate == true){
            system("CLS");
            printf("\n\t==已登入!!==\n");
        }

        if(validate == false){
            system("CLS");
            printf("\n\t==登入失敗!!==\n");
        }

	}
	else if(option == 2){//新建帳號

	}
	else if(option == 3){//修改密碼

	}
	else if(option == 4){//離開
        system("CLS");
        printf("\n\t<<~感謝您使用本系統~>>\n");
        printf("\n\t==按下任意鍵離開本系統==\n");
        return 0;
	}

}

///////////////////////////////////////////////
///		    副程式		  	 ///
///////////////////////////////////////////////

///顯示功能選單
void show_menu() {
    printf("<<歡迎使用找室友系統>>\n");
    printf("按下數字鍵選擇服務\n");
    printf("1.登入\t\t2.新增帳號\n3.修改密碼\t4.離開系統\n");
    printf("請輸入服務選項:");
}

///登入驗證///		*true = 登入成功 *false = 登入失敗
bool login(string acc,string pas) {
    return true;
}

///創建帳號///		*true = 創建成功 *false = 創建失敗
bool create_account(string acc,string pas) {

}

///更改密碼
void mutator(string pas) {

}

//註記 與資料庫連動的user number取得副程式還須新增 <<二擇一>> 1.登入驗證回傳值為int = user number  2.多寫一個get user number的副程式

///取得使用者編號
int get_user_number(string acc,string pas){

}
