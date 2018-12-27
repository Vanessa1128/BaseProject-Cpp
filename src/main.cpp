#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include <string>

using namespace std;
///登入系統副程式宣告區
//////////////////////////////////////////////
void show_menu();///顯示功能選單
bool login(string acc,string pas);///登入驗證
bool create_account(string acc,string pas);///創建帳號
void mutator(string pas);///更改密碼
int get_user_number(string acc,string pas);///取得使用者編號
//////////////////////////////////////////////

//////////////////////////////////////////////
///登入系統結構宣告
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


///////////////////////////////////////////////
///		    junk、房東、房子、房客結構的宣告		  	 ///
/*
提醒：這裡建構的鏈結串列 Lindked List 是雙向不循環的
比如： a <-> b <-> c <-> d ，但a、d未串聯，a->prev 是 a 自己，d->next 是 NULL
*/
typedef struct {
	char junk1[30]; char junk2[30]; char junk3[30];
	char junk4[30]; char junk5[30]; char junk6[30];
	char junk7[30]; char junk8[30]; char junk9[30];
	char junk10[30]; char junk11[30];
} Junk;

typedef struct landlordStruct {
	char LandlordName[15]; // name: 15 char max
	int UserNumber;
	int Star; // range: 1 - 10
	int NumberOfHouse;
	char Contact1[30];
	char Contact2[30];

	struct landlordStruct *next, *prev;
} landlord;

typedef struct houseStruct {
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

typedef struct roomerStruct {
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
///		    *記得* 在這裡提前宣告一下 副程式		  	 ///

// 共用副程式
landlord* landlordBuild(); // 房東資料庫導入
house* houseBuild(); // 房子資料庫導入
roomer* roomerBuild(); // 房客資料庫導入

// 找房子系統副程式
void findHouse(); // 找房子系統進入點
house* generate_hou(); // 產生房子節點(node)
landlord* generate_lan(); // 產生房東節點(node)
int printHouse(house*, landlord*); // 印出房子串列、選擇查看資訊
int houseFilter(house*, landlord*); // 輸入條件 & 篩選房子

//找室友系統副程式
void findRoomer(); // 找室友系統進入點
roomer* generate_roo(); // 產生室友節點(node)
int printRoomer(roomer*); // 印出室友串列、選擇查看資訊
int roomerFilter(roomer*); // 輸入條件 & 篩選室友

//室友評分的系統,房東評分的系統
void landlordGetScore(landlord*);
void roomerGetScore(roomer*);

///////////////////////////////////////////////

int main() {
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
	return 0;
}

///////////////////////////////////////////////
/// 共用 副程式：		    產生房子節點(node)		  	 ///
/// 已利用副程式：找房子系統
house* generate_hou() {
	house *item = NULL;
	item = (house*)malloc(sizeof(house));
	item->next = NULL;
	item->prev = NULL;

	return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 共用 副程式：		    產生房東節點(node)		  	 ///
/// 已利用副程式：找房子系統
landlord* generate_lan() {
	landlord *item = NULL;
	item = (landlord*)malloc(sizeof(landlord));
	item->next = NULL;
	item->prev = NULL;

	return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 共用 副程式：		    產生室友節點(node)		  	 ///
/// 已利用副程式：找室友系統
roomer* generate_roo() {
	roomer *item = NULL;
	item = (roomer*)malloc(sizeof(roomer));
	item->next = NULL;
	item->prev = NULL;

	return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 共用 副程式：		    LandlordDatabase.txt檔案 房東資料庫導入		  	 ///
/// 已利用副程式：找房子系統

landlord* landlordBuild() {

	FILE *landlordFile;
	landlordFile = fopen("LandlordDatabase.txt", "r");
	if (landlordFile == NULL) { printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
	landlord *head_lan = NULL, *current_lan = NULL, *temp1;

	// 標題欄位處理 structure
	Junk junk;
	fscanf(landlordFile, "%s %s %s %s %s %s", junk.junk1, junk.junk2, junk.junk3, junk.junk4, junk.junk5, junk.junk6);

	head_lan = generate_lan();
	head_lan->prev = head_lan;
	current_lan = head_lan;
	while (fscanf(landlordFile, "%s %d %d %d %s %s\n", current_lan->LandlordName, &current_lan->UserNumber,
		&current_lan->Star, &current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2) == 6) {

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
	current_lan = head_lan;
	printf("\n測試印出：\n");
	while (current_lan != NULL) {
		printf("%-15s %-2d %-2d %-2d %-30s %-30s\n", current_lan->LandlordName, current_lan->UserNumber, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);
		current_lan = current_lan->next;
	} printf("\n以上測試印出\n");

	// 關文件
	fclose(landlordFile);

	/* 回傳已建立好的 head 節點 */
	return head_lan;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 共用 副程式：		    HouseDatabase.txt檔案 房子資料庫導入		  	 ///
/// 已利用副程式：找房子系統

house* houseBuild() {

	FILE *houseFile;
	houseFile = fopen("HouseDatabase.txt", "r");
	if (houseFile == NULL) { printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
	house *head_hou = NULL, *current_hou = NULL, *temp;

	// 標題欄位處理 structure
	Junk junk;
	fscanf(houseFile, "%s %s %s %s %s %s %s %s %s %s %s", junk.junk1, junk.junk2, junk.junk3,
		junk.junk4, junk.junk5, junk.junk6, junk.junk7, junk.junk8, junk.junk9, junk.junk10, junk.junk11);

	head_hou = generate_hou();
	head_hou->prev = head_hou;
	current_hou = head_hou;
	while (fscanf(houseFile, "%s %d %lf %lf %lf %s %d %s %s %s %s\n",
		current_hou->LandlordName, &current_hou->Number, &current_hou->Area,
		&current_hou->Rent, &current_hou->OtherCost, current_hou->Address,
		&current_hou->PeopleNumber, current_hou->Network, current_hou->RoomType,
		current_hou->Pet, current_hou->Facilities) == 11) {

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
	current_hou = head_hou;
	printf("\n測試印出：\n");
	while (current_hou != NULL) {
		printf("%-5s %2d %-7g %-7g %-7g %-30s %-2d %-13s %-10s %-5s %-100s\n",
			current_hou->LandlordName, current_hou->Number, current_hou->Area,
			current_hou->Rent, current_hou->OtherCost, current_hou->Address,
			current_hou->PeopleNumber, current_hou->Network, current_hou->RoomType,
			current_hou->Pet, current_hou->Facilities);
		current_hou = current_hou->next;
	} printf("\n以上測試印出\n");

	// 關文件
	fclose(houseFile);

	/* 回傳已建立好的 head 節點 */
	return head_hou;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 共用 副程式：		    RoomerDatabase.txt檔案 房客資料庫導入		  	 ///
/// 已利用副程式：找室友系統

roomer* roomerBuild() { /* roomer 資料庫導出到 Linked List */

	FILE *roomerFile;
	roomerFile = fopen("RoomerDatabase.txt", "r");
	if (roomerFile == NULL) { printf("Fail to open file!\n"); exit(EXIT_FAILURE); }

	roomer *head_roo = NULL, *current_roo = NULL, *temp1;

	// 標題欄位處理 structure
	Junk junk;
	fscanf(roomerFile, "%s %s %s %s %s %s %s %s %s", junk.junk1, junk.junk2, junk.junk3, junk.junk4, junk.junk5, junk.junk6, junk.junk7, junk.junk8, junk.junk9);

	head_roo = generate_roo();
	head_roo->prev = head_roo;
	current_roo = head_roo;
	while (fscanf(roomerFile, "%s %d %d %s %d %s %s %s %s\n",
		current_roo->RoomerName, &current_roo->UserNumber, &current_roo->Star,
		current_roo->Gender, &current_roo->SleepTime, current_roo->School,
		current_roo->Nationality, current_roo->Habit, current_roo->Disease) == 9) {

		current_roo->next = generate_roo();
		current_roo->next->prev = current_roo;
		current_roo = current_roo->next;
	}
	// 刪除最後一個多餘 node
	current_roo = current_roo->prev;
	temp1 = current_roo->next;
	current_roo->next = NULL;
	free(temp1);

	// 測試印出 landlord link list
	current_roo = head_roo;
	printf("\n測試印出：\n");
	while (current_roo != NULL) {
		printf("%-15s %-2d %-2d %-10s %2d:00 %-40s %-20s %-20s %-20s\n",
			current_roo->RoomerName, current_roo->UserNumber, current_roo->Star,
			current_roo->Gender, current_roo->SleepTime, current_roo->School,
			current_roo->Nationality, current_roo->Habit, current_roo->Disease);
		current_roo = current_roo->next;
	} printf("\n以上測試印出\n");

	// 關文件
	fclose(roomerFile);

	/* 回傳已建立好的 head 節點 */
	return head_roo;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 找房子系統 主程式：		    找房子系統進入點		  	 ///
void findHouse() {
	house* head_hou = NULL;
	landlord* head_lan = NULL;

	/* 進行篩選 & 回傳狀態 */
	// 狀態 0：成功&退出程式
	// 狀態 2：成功&重新篩選
	int state = 2;
	while (state == 2) {
		head_hou = houseBuild(); // 建立 house linked list
		head_lan = landlordBuild(); // 建立 landlord linked list
		state = houseFilter(head_hou, head_lan);
	}

	printf("||> 退出找房子系統！\n");
	return;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 找房子系統 副程式：		    印出房子串列、選擇查看資訊		  	 ///
int printHouse(house *head_hou, landlord *head_lan) { /* 搜索到房子後：印出房子串列、選擇查看資訊 */

	char name[15];
	int num;
	house *current_hou;
	landlord *current_lan;

	/* 印出房子串列 */
	printf("||> 根據你的選擇，符合條件的房子有： \n");
	printf("|--------------------------------------------------------------------\n");
	current_hou = head_hou;
	while (current_hou != NULL) {
		printf("||> Landlord:%-15s Number:%2d \n |> Area:%-7g Rent:%-7g OtherCost:%-7g \n |> Address:%-30s \n |> PeopleNumber:%-2d Network:%-13s RoomType:%-10s Pet:%-5s \n |> Facilities:%-100s\n",
			current_hou->LandlordName, current_hou->Number, current_hou->Area,
			current_hou->Rent, current_hou->OtherCost, current_hou->Address,
			current_hou->PeopleNumber, current_hou->Network, current_hou->RoomType,
			current_hou->Pet, current_hou->Facilities);
		printf("|--------------------------------------------------------------------\n");
		current_hou = current_hou->next;
	}

	/* 查看房子的詳細資訊 */
	printf("||> 請輸入房東名字&序號以查看詳細資訊(ex. \"Joe 0\"). \n|>> ");
	scanf("%s %d", name, &num);
	current_lan = head_lan;
	while (current_lan != NULL) {
		if (strcasecmp(current_lan->LandlordName, name) == 0) break;
		current_lan = current_lan->next;
	}
	current_hou = head_hou;
	while (current_hou != NULL) {
		if (strcasecmp(current_hou->LandlordName, name) == 0 && current_hou->Number == num) break;
		current_hou = current_hou->next;
	}

	printf("||>你選擇的房子：\n");
	printf("|====================================================================\n");
	printf("||>> Landlord Infomation: \n |> Name: %-15s Star: %-2d Number of house: %-2d \n |> Contact1: %-30s \n |> Contact2: %-30s\n",
		current_lan->LandlordName, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);

	printf("||>> House Infomation: \n |> Area:%-7g Rent:%-7g OtherCost:%-7g \n |> Address:%-30s \n |> PeopleNumber:%-2d Network:%-13s RoomType:%-10s Pet:%-5s \n |> Facilities:%-100s\n",
		current_hou->Area,
		current_hou->Rent, current_hou->OtherCost, current_hou->Address,
		current_hou->PeopleNumber, current_hou->Network, current_hou->RoomType,
		current_hou->Pet, current_hou->Facilities);
	printf("|====================================================================\n");

	/* 是否重新篩選判斷 */
	int state = 0;
	printf("||> 是否重新篩選房子？0：否；2：是 (ex. \"2\") \n|>> ");
	scanf("%d", &state);
	fflush(stdin);
	while (state != 0 && state != 2) {
		printf("||> 是否重新篩選房子？0：否；2：是 (ex. \"0\") \n|>> ");
		scanf("%d", &state);
		fflush(stdin);
	}
	return state;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 找房子系統 副程式：		    輸入條件 & 篩選房子		  	 ///
int houseFilter(house *head_hou, landlord *head_lan) {
	house *current_hou;
	house *tempNode;
	int cnt;
	int filter[6];
	double filter0_a, filter0_b, filter1_a, filter1_b;
	int filter2_a, filter2_b;
	char filter3[5];
	char filter4[6];
	char filter5[5];
	for (cnt = 0; cnt < 6; cnt++) filter[cnt] = 0;

	printf("\n||> 歡迎進入找房子系統！ <|\n");
	printf("||> 請按要求輸入篩選條件 <|\n");
	printf("||> 所有可篩選條件：坪數、房租、入住人數、網路品質、套房/雅房、可否養寵.\n");
	printf("|=======================================================================\n");

	printf("||> 篩選坪數？是：1；否：0 \n|>> "); // 篩選：範圍
	scanf("%d", &filter[0]);
	if (filter[0]) {
		printf("||> 請輸入範圍(ex. \"10.5 20\")(左<右): \n|>> ");
		scanf("%lf %lf", &filter0_a, &filter0_b);
		fflush(stdin);
		/* 判定輸入有效 */
		while (filter0_a < 0 || filter0_b < 0 || filter0_a >= filter0_b) {
			printf("||> 請輸入正確的範圍(ex. \"0 36.5\")(左<右): \n|>> ");
			scanf("%lf %lf", &filter0_a, &filter0_b);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->Area<filter0_a || current_hou->Area>filter0_b) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // 單一節點串列
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // 串列末尾
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // 串列開頭
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // 串列中間
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
	if (filter[1]) {
		printf("||> 請輸入範圍(ex. \"3000 4000\")(左<右): \n|>> ");
		scanf("%lf %lf", &filter1_a, &filter1_b);
		fflush(stdin);
		/* 判定輸入有效 */
		while (filter1_a < 0 || filter1_b < 0 || filter1_a >= filter1_b) {
			printf("||> 請輸入正確的範圍(ex. \"2000 8000\")(左<右): \n|>> ");
			scanf("%lf %lf", &filter1_a, &filter1_b);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->Rent<filter1_a || current_hou->Rent>filter1_b) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // 單一節點串列
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // 串列末尾
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // 串列開頭
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // 串列中間
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
	if (filter[2]) {
		printf("||> 請輸入範圍(ex. \"1 1\")(左<=右): \n|>> ");
		scanf("%d %d", &filter2_a, &filter2_b);
		fflush(stdin);
		/* 判定輸入有效 */
		while (filter2_a <= 0 || filter2_b <= 0 || filter2_a > filter2_b) {
			printf("||> 請輸入正確的範圍(ex. \"2 5\")(左<=右): \n|>> ");
			scanf("%d %d", &filter2_a, &filter2_b);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->PeopleNumber<filter2_a || current_hou->PeopleNumber>filter2_b) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // 單一節點串列
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // 串列末尾
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // 串列開頭
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // 串列中間
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
	if (filter[3]) {
		printf("||> 無網路：No；有網路,20M：20M；有網路,60M：60M；有網路,100M：100M(ex. \"20M\") \n|>> ");
		scanf("%s", filter3);
		fflush(stdin);
		/* 判定輸入有效 */
		while (strcasecmp(filter3, "No") && strcasecmp(filter3, "20M") && strcasecmp(filter3, "60M") && strcasecmp(filter3, "100M")) {
			printf("||> 請輸入正確的指令(ex. \"No\") \n|>> ");
			scanf("%s", filter3);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (strncasecmp(current_hou->Network, filter3, 2)) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // 單一節點串列
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // 串列末尾
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // 串列開頭
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // 串列中間
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
	if (filter[4]) {
		printf("||> 套房：Suite；雅房：Share(ex. \"suite\") \n|>> ");
		scanf("%s", filter4);
		/* 判定輸入有效 */
		while (strcasecmp(filter4, "Suite") && strcasecmp(filter4, "Share")) {
			printf("||> 請輸入正確的指令(ex. \"Share\") \n|>> ");
			scanf("%s", filter4);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->RoomType[1] != filter4[1]) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // 單一節點串列
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // 串列末尾
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // 串列開頭
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // 串列中間
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
	if (filter[5]) {
		printf("||> 可養寵物：Yes；不可養寵物：No(ex. \"no\") \n|>> ");
		scanf("%s", filter5);
		/* 判定輸入有效 */
		while (strcasecmp(filter5, "es") && strcasecmp(filter5, "No")) {
			printf("||> 請輸入正確的指令(ex. \"Yes\") \n|>> ");
			scanf("%s", filter5);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (strncasecmp(current_hou->Pet, filter5, 2)) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // 單一節點串列
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // 串列末尾
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // 串列開頭
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // 串列中間
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
	if (head_hou == NULL) {
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
/// 找室友系統 主程式：		    找室友系統進入點		  	 ///
void findRoomer() {
	roomer* head_roo = NULL;

	/* 進行篩選 & 回傳狀態 */
	// 狀態 0：成功&退出程式
	// 狀態 2：成功&重新篩選
	int state = 2;
	while (state == 2) {
		head_roo = roomerBuild(); // 建立 roomer linked list
		state = roomerFilter(head_roo);
	}

	printf("||> 退出找室友系統！\n");
	return;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 找室友系統 副程式：		    印出室友串列、選擇查看資訊		  	 ///
int printRoomer(roomer *head_roo) { /* 搜索到室友後：印出室友串列、選擇查看資訊 */

	char name[15];
	roomer *current_roo;

	/* 印出室友串列 */
	printf("||> 根據你的選擇，符合條件的室友有： \n");
	printf("|--------------------------------------------------------------------\n");
	current_roo = head_roo;
	while (current_roo != NULL) {
		printf("||> Name:%-15s Star:%-2d Gender:%-10s \n |> SleepTime:%2d:00 \n |> School:%-40s \n |> Nationality:%-20s \n",
			current_roo->RoomerName, current_roo->Star,
			current_roo->Gender, current_roo->SleepTime, current_roo->School,
			current_roo->Nationality);
		printf("|--------------------------------------------------------------------\n");
		current_roo = current_roo->next;
	}

	/* 查看房子的詳細資訊 */
	printf("||> 請輸入室友名字以查看詳細資訊(ex. \"Jack\"). \n|>> ");
	scanf("%s", name);
	current_roo = head_roo;
	while (current_roo != NULL) {
		if (strcasecmp(current_roo->RoomerName, name) == 0) break;
		current_roo = current_roo->next;
	}

	printf("||>你選擇的室友：\n");
	printf("|====================================================================\n");
	printf("||>> Roomer Infomation: \n |> Name:%-15s Star:%-2d Gender:%-10s \n |> SleepTime:%2d:00 \n |> School:%-40s \n |> Nationality:%-20s \n |> Habit:%-20s \n |> Disease:%-20s \n",
		current_roo->RoomerName, current_roo->Star,
		current_roo->Gender, current_roo->SleepTime, current_roo->School,
		current_roo->Nationality, current_roo->Habit, current_roo->Disease);
	printf("|====================================================================\n");

	/* 是否重新篩選判斷 */
	int state = 0;
	printf("||> 是否重新篩選室友？0：否；2：是 (ex. \"2\") \n|>> ");
	scanf("%d", &state);
	fflush(stdin);
	while (state != 0 && state != 2) {
		printf("||> 是否重新篩選室友？0：否；2：是 (ex. \"0\") \n|>> ");
		scanf("%d", &state);
		fflush(stdin);
	}
	return state;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// 找室友系統 副程式：		    輸入條件 & 篩選室友		  	 ///
int roomerFilter(roomer *head_roo) {
	roomer *current_roo;
	roomer *tempNode;
	int cnt;
	int filter[4];
	char filter0[10];
	int filter1_a, filter1_b;
	char filter2;
	char filter3[15];

	for (cnt = 0; cnt < 4; cnt++) filter[cnt] = 0;

	printf("\n||> 歡迎進入找室友系統！ <|\n");
	printf("||> 請按要求輸入篩選條件 <|\n");
	printf("||> 所有可篩選條件：性別、睡眠時間、學校、國籍.\n");
	printf("|=======================================================================\n");

	printf("||> 篩選性別？是：1；否：0 \n|>> "); // 篩選：雙選
	scanf("%d", &filter[0]);
	if (filter[0]) {
		printf("||> 男：Male；女：Female(ex. \"Female\") \n|>> ");
		scanf("%s", filter0);
		fflush(stdin);
		/* 判定輸入有效 */
		while (strcasecmp(filter0, "Male") && strcasecmp(filter0, "Female")) {
			printf("||> 請輸入正確的指令(ex. \"male\") \n|>> ");
			scanf("%s", filter0);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_roo = head_roo;
		while (current_roo != NULL) {

			if (strcasecmp(filter0, current_roo->Gender)) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // 單一節點串列
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // 串列末尾
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // 串列開頭
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // 串列中間
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
	printf("||> 篩選睡眠時間？是：1；否：0 \n|>> "); // 篩選：範圍
	scanf("%d", &filter[1]);
	if (filter[1]) {
		printf("||> 請輸入範圍(限定晚20點～隔日6點)(ex. \"20 1\"(20點～1點))(左邊時間較早): \n|>> ");
		scanf("%d %d", &filter1_a, &filter1_b);
		fflush(stdin);
		/* 判定輸入有效 */
		if (filter1_a <= 6) filter1_a += 24; // may result in false time
		if (filter1_b <= 6) filter1_b += 24; // may result in false time
		while (filter1_a < 20 || filter1_a>30 || filter1_b < 20 || filter1_b>30 || filter1_a > filter1_b) {
			printf("||> 請輸入正確的範圍(限定晚20點～隔日6點)(ex. \"23 23\"(23點～1點))(左邊時間較早) \n|>> ");
			scanf("%d %d", &filter1_a, &filter1_b);
			if (filter1_a <= 6) filter1_a += 24; if (filter1_b <= 6) filter1_b += 24;
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		int tempTime;
		current_roo = head_roo;

		while (current_roo != NULL) {

			if (current_roo->SleepTime <= 6) tempTime = current_roo->SleepTime + 24;
			else tempTime = current_roo->SleepTime;

			if (tempTime<filter1_a || tempTime>filter1_b) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // 單一節點串列
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // 串列末尾
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // 串列開頭
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // 串列中間
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
	printf("||> 篩選學校？是：1；否：0 \n|>> "); // 篩選：多選
	scanf("%d", &filter[2]);
	if (filter[2]) {
		printf("||> 逢甲大學：F；東海大學：T；台中科大：S；中興大學：N；僑光科大：O(ex. \"F\") \n|>> ");
		scanf("%c", &filter2);
		fflush(stdin);
		/* 判定輸入有效 */
		while (filter2 != 'F' && filter2 != 'T' && filter2 != 'S' && filter2 != 'N' && filter2 != 'O') {
			printf("||> 請輸入正確的指令(ex. \"T\") \n|>> ");
			scanf("%c", &filter2);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_roo = head_roo;
		while (current_roo != NULL) {

			if (filter2 != current_roo->School[0]) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // 單一節點串列
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // 串列末尾
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // 串列開頭
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // 串列中間
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
	printf("||> 篩選國籍？是：1；否：0 \n|>> "); // 篩選：多選
	scanf("%d", &filter[3]);
	if (filter[3]) {
		printf("||> 台灣：Taiwan；馬來西亞：Malaysia；日本：Japan；印度尼西亞：Indonesia；菲律賓：Philippine；中國大陸：China(ex. \"Taiwan\") \n|>> ");
		scanf("%s", filter3);
		/* 判定輸入有效 */
		while (strcasecmp(filter3, "Taiwan") && strcasecmp(filter3, "Malaysia") && strcasecmp(filter3, "Japan") && strcasecmp(filter3, "Indonesia") && strcasecmp(filter3, "Philippine") && strcasecmp(filter3, "China")) {
			printf("||> 請輸入正確的指令(ex. \"Suite\") \n|>> ");
			scanf("%s", filter3);
			fflush(stdin);
		}
		/* 刪除不符合要求的node */
		current_roo = head_roo;
		while (current_roo != NULL) {

			if (strcasecmp(filter3, current_roo->Nationality)) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // 單一節點串列
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // 串列末尾
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // 串列開頭
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // 串列中間
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

	/* if 沒有房子 */
	if (head_roo == NULL) {
		printf("||> 無符合要求的房子！ <| \n");
		printf("||> 重新進入系統篩選。 <| \n");
		return 2; // 重新進入系統篩選
	}
	/* if 有房子 */
	else {
		int state = printRoomer(head_roo); // 印出符合條件室友、選擇查看資訊
		return state;
	}
}
///////////////////////////////////////////////
//新增房東,室友評分系統
void landlordGetScore(landlord *landlordHead)
{
	char name[20];
	int score=0; 
	
	landlord*ptr,*fprint;
	
	ptr=landlordHead;//ptr控制指標的位址 
	
	printf("--進入房東評分系統---\n");
	printf("請輸入需要評分的對象\n");
	scanf("%s",name);
	
	while(ptr!=NULL)
	{ 
	    if(strcmp(name,ptr->LandlordName)==0)
	    {	 
		 break;//這個評分對象存在
	    }
	  ptr=ptr->next; 
	} 
	/*ptr目前為存在對象*/
	
	if(ptr != NULL)//判斷評分對象存不存在 
	{
	    printf("輸入要評分對象的分數(1-10)\n");	
		scanf("%d",&score);
		
		if( score<=10 && score>=1 && ptr->Star<=10 && ptr->Star>=1)//已經被評分過但是還要評分的角色 
		{ 
		  printf("---以評分過的對象---\n"); 
		  ptr->Star = double(score+ptr->Star)/2; 
		}
		else if( score<=10 && score>=1)//從未評分角色 
		{ 
		  ptr->Star=score; 
		}
		else //錯誤評分 
		{
		 printf("評分錯誤 ,使用者輸入不在評分內(提示使用者輸入錯誤請重)");	
		}
		
	} 
	else//角色不存在輸出 
	{
	 printf("輸入不存在名字 或錯誤的數字");		
	}
    
	if( score<=10 && score>=1)
	{ 
	 printf("輸入記憶體的分數:%2d",ptr->Star); 
	} 
	//////////////////////////////////////////////////
	FILE *landlordFile;
	landlordFile = fopen("LandlordDatabase.txt", "w");
	
	fprint=landlordHead;//指標指向標頭 
	
	fprintf(landlordFile,"%-15s %-10s %-10s %-30s %-30s %-30s\n","Name","UserNumber","Star","NumberOfHouse","Contact1","Contact2");
	while(fprint != NULL)//將評分完的檔案輸入資料庫 
	{
	    fprintf(landlordFile,"%-15s %-10d %-10d %-30d %-30s %-30s \n",
			     fprint->LandlordName, fprint->UserNumber, fprint->Star,
			     fprint->NumberOfHouse, fprint->Contact1, fprint->Contact2);
		 	
	   fprint=fprint->next;	
	}
    
	fclose(landlordFile);//關檔 
	
}
void roomerGetScore(roomer*roomerHead)
{

	char name[20];
	int i=0 , score=0; 
	roomer*ptr, *fprint;
		
	ptr=roomerHead;//ptr控制指標的位址 
	
	printf("--進入室友評分系統---\n");
	printf("請輸入需要評分的對象:\n");
	scanf("%s",name);
	
	while(ptr!=NULL)
	{ 
	    if(strcmp(name,ptr->RoomerName)==0)
	    {	     
		  break;//這個評分對象存在
	    }
	  ptr=ptr->next; 
	} 

	/*ptr目前為存在對象*/
	
	if(ptr != NULL)//判斷評分對象存不存在 
	{
	    printf("輸入要評分對象的分數(1-10)\n");	
		scanf("%d",&score);
		
		if( score<=10 && score>=1 && ptr->Star<=10 && ptr->Star>=1 )//已經被評分過但是還要評分的角色 
		{
		  printf("---以評分過的對象---\n");
		  ptr->Star = double(score+ptr->Star)/2;
		}
		else if( score<=10 && score>=1)//從未評分角色 
		{ 
		  ptr->Star=score; 
		}
		else //錯誤評分 
		{
		  printf("評分錯誤 ,使用者輸入不在評分內(提示使用者輸入錯誤請重)");	
		}
		
	} 
	else //角色不存在輸出 
	{
	 printf("輸入不存在名字 或錯誤的數字");		
	}
   
    if( score<=10 && score>=1)
	{
	   printf("輸入記憶體的分數:%2d",ptr->Star);
    }
	//////////////////////////////////////////////////////
	   FILE *roomerFile;
	   roomerFile = fopen("RoomerDatabase.txt","w");//開啟檔案 
	   fprint=roomerHead;
	
	   fprintf(roomerFile,"%-15s%-14s%-8s%-10s%-15s%-40s%-20s%-20s%-20s\n","Name","UserNumber","Star","Gender","SleepTime","School","Nationality","Habit","Disease");
	   while(fprint!=NULL)//將評分完的檔案輸入資料庫 
	  {
	     fprintf(roomerFile,"%-15s%-14d%-8d%-10s%-15d%-40s%-20s%-20s%-20s\n",
			     fprint->RoomerName, fprint->UserNumber, fprint->Star,
			     fprint->Gender, fprint->SleepTime, fprint->School,
			     fprint->Nationality, fprint->Habit, fprint->Disease);	
		 fprint=fprint->next;	
	  }
    
	fclose(roomerFile);//關檔 
}
///////////////////////////////////////////////
///////////////////////////////////////////////
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

