#include<stdio.h>

void show_menu();

int main (void){
	
	int option; //功能選項 
	
	show_menu();//show選單
	for(;;){
		
		if(scanf(" %d", & option) !=1 );
		
	}
	
	
	if(option == 1){
		
	}
	else if(option == 2){
		
	}
	else if(option == 3){
		
	}
	else{
		
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
    printf("1.登入  2.新建帳號 3.離開系統\n");
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

