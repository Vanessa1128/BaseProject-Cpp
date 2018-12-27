#include<stdio.h>
#include<stdlib.h>
#include<iostream>
///副程式宣告區
//////////////////////////////////////////////
void show_menu();
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


	if(option == 1){

	}
	else if(option == 2){

	}
	else if(option == 3){

	}
	else if(option == 4){//離開
        system("CLS");
        printf("\n\t<<~感謝您使用本系統~>>\n");
        printf("\n\t==按下任意鍵離開本系統==\n");
        return 0;
	}

	//switch寫法 對應各功能
	//1.login
	//2.create account
	//3.quit
	//4.改密碼


}

///////////////////////////////////////////////
///		    副程式		  	 ///
///////////////////////////////////////////////

///顯示功能選單
void show_menu() {
    printf("<<歡迎使用找室友系統>>\n");
    printf("按下數字鍵選擇服務\n");
    printf("1.登入  2.新建帳號 3.修改密碼 4.離開系統\n");
    printf("請輸入服務選項:");
}

///登入驗證///		*true = 登入成功 *false = 登入失敗
bool login(/*帳號密碼*/) {

}

///創建帳號///		*true = 創建成功 *false = 創建失敗
bool create_account(/*帳號資訊*/) {

}

///更改密碼
void mutator(/*欲更改的職*/) {

}

//註記 與資料庫連動的user number取得副程式還須新增 <<二擇一>> 1.登入驗證回傳值為int = user number  2.多寫一個get user number的副程式

