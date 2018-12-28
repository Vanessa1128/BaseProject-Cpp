
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string.h>

using namespace std;
///結構宣告
//////////////////////////////////////////////
typedef struct account_database_title{
	char num[8]; char type[8]; char acc[8];
	char pas[8];
} Title;//接收帳戶資料庫的第一行

typedef struct account_data{//帳號結構
	int num;
	char type;
	char account[20];
	char password[20];

	struct account_data *next, *previous;
} Account;
//////////////////////////////////////////////
///副程式宣告區
//////////////////////////////////////////////
void show_menu();///顯示功能選單
bool login(char acc[],char pas[]);///登入驗證
bool create_account(char acc[],char pas[],char type);///創建帳號
//void mutator(char acc[],char pas[],char new_pas[]);///更改密碼
int get_user_number(char acc[],char pas[]);///取得使用者編號
Account* acc_node();///產生帳號節點
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
        char acc[20],pas[20];
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
            printf("\n\t==已登入!!==\n\n");
            system("pause");
            system("CLS");

        }

        if(validate == false){
            system("CLS");
            printf("\n\t==登入失敗!!==\n");
        }

	}
	else if(option == 2){//新建帳號
        system("CLS");
	    printf("==歡迎 新使用者==\n");
        printf("請輸入帳號:");
        char acc[20],pas[20],type;
        scanf(" %s",acc);
        system("CLS");
        printf("==歡迎 新使用者==\n");
        printf("請輸入帳號:%s\n",acc);
        printf("請輸入密碼:");
        scanf(" %s",pas);
        system("CLS");
        printf("==歡迎 新使用者==\n");
        printf("請輸入帳號:%s\n",acc);
        printf("請輸入密碼:%s\n",pas);
        printf("請輸入類別  房客:r 房東:l :");
        scanf(" %c",& type);
        create_account(acc,pas,type);


	}
	/*else if(option == 3){//修改密碼
        system("CLS");
	    printf("==歡迎來到登入頁面==\n");
        printf("請輸入帳號:");
        char acc[20],pas[20];
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
            printf("\n\t==已登入!!==\n請輸入新密碼:");
            char new_pas[20];
            scanf(" %s",new_pas);
            mutator(acc,pas,new_pas);
            system("pause");
            system("CLS");

        }

        if(validate == false){
            system("CLS");
            printf("\n\t==登入失敗!!==\n");
        }
	}*/
	else if(option == 3){//離開
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
    printf("1.登入\t\t2.新增帳號\n3.離開系統\n");
    printf("請輸入服務選項:");
}

///登入驗證///		*true = 登入成功 *false = 登入失敗
bool login(char acc[],char pas[]) {
    int login = 0;
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "r");
    if (acc_open == NULL) {
        printf("無法連接帳號資料庫!!\n");
        system("pause");
        return false;
    }
	Account *head_acc = NULL, *current_acc = NULL;
	Title title;
	fscanf(acc_open," %s %s %s %s",title.num,title.type,title.acc,title.pas );

    head_acc = acc_node();
    head_acc->previous = head_acc;
	current_acc = head_acc;
	while (fscanf(acc_open,"%d %c %s %s",&current_acc->num, &current_acc->type, current_acc->account,current_acc->password) != EOF) {
        if(strcmp(current_acc->account,acc)==0&& strcmp(current_acc->password,pas)== 0){
            login = 1;
            break;
        }
		current_acc->next = acc_node();
		current_acc->previous = current_acc;
		current_acc = current_acc->next;

	}
	if(login == 1)
        return true;
	else
        return false;
}
///產生節點
Account* acc_node() {
	Account *node = NULL;
	node = (Account*)malloc(sizeof(Account));
	node->next = NULL;
	node->previous = NULL;

	return node;
}

///創建帳號///		*true = 創建成功 *false = 創建失敗
bool create_account(char acc[],char pas[],char type) {
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "w");
    if (acc_open == NULL) {
        printf("無法連接帳號資料庫!!\n");
        system("pause");
        return false;
    }
    int num = 0;

    Account *head_acc = NULL, *current_acc = NULL;
	Title title;
	fscanf(acc_open," %s %s %s %s",title.num,title.type,title.acc,title.pas );

    head_acc = acc_node();
    head_acc->previous = head_acc;
	current_acc = head_acc;
	while (fscanf(acc_open,"%d %c %s %s",&current_acc->num, &current_acc->type, current_acc->account,current_acc->password) != EOF) {

		current_acc->next = acc_node();
		current_acc->previous = current_acc;
		current_acc = current_acc->next;
		num++;

	}


    fprintf(acc_open,"%d\t%c\t%s\t%s",num,type,acc,pas);
    fclose(acc_open);
    return true;
}

///更改密碼
/*void mutator(char acc[],char pas[],char new_pas[]) {
   int login = 0;
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "r");
    if (acc_open == NULL) {
        printf("無法連接帳號資料庫!!\n");
        system("pause");
    }
	Account *head_acc = NULL, *current_acc = NULL;
	Title title;
	fscanf(acc_open," %s %s %s %s",title.num,title.type,title.acc,title.pas );

    head_acc = acc_node();
    head_acc->previous = head_acc;
	current_acc = head_acc;
	while (fscanf(acc_open,"%d %c %s %s",&current_acc->num, &current_acc->type, current_acc->account,current_acc->password) != EOF) {
        if(strcmp(current_acc->account,acc)==0&& strcmp(current_acc->password,pas)== 0){
            //取代功能
            //
            printf("%d %c %s %s",&current_acc->num, &current_acc->type, current_acc->account,current_acc->password);
            //
            break;
        }
		current_acc->next = acc_node();
		current_acc->previous = current_acc;
		current_acc = current_acc->next;

	}
}

//註記 與資料庫連動的user number取得副程式還須新增 <<二擇一>> 1.登入驗證回傳值為int = user number  2.多寫一個get user number的副程式

///取得使用者編號
int get_user_number(char acc[],char pas[]){
    int login = 0;
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "r");
    if (acc_open == NULL) {
        printf("無法連接帳號資料庫!!\n");
        system("pause");
        return false;
    }
	Account *head_acc = NULL, *current_acc = NULL;
	Title title;
	fscanf(acc_open," %s %s %s %s",title.num,title.type,title.acc,title.pas );

    head_acc = acc_node();
    head_acc->previous = head_acc;
	current_acc = head_acc;
	int user_num = -1;
	while (fscanf(acc_open,"%d %c %s %s",&current_acc->num, &current_acc->type, current_acc->account,current_acc->password) != EOF) {
        if(strcmp(current_acc->account,acc)==0&& strcmp(current_acc->password,pas)== 0){
            user_num = current_acc->num;
            break;
        }
		current_acc->next = acc_node();
		current_acc->previous = current_acc;
		current_acc = current_acc->next;

	}
	return user_num;
}*/
