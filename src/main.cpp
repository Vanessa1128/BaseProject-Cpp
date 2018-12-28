#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include <string>


using namespace std;
///���c�ŧi
//////////////////////////////////////////////
typedef struct account_database_title{
	char num[8]; char type[8]; char acc[8];
	char pas[8];
} Title;//�����b���Ʈw���Ĥ@��

typedef struct account_data{//�b�����c
	int num;
	char type;
	char account[20];
	char password[20];

	struct account_data *next, *previous;
} Account;
//////////////////////////////////////////////
///�Ƶ{���ŧi��
//////////////////////////////////////////////
void show_menu();///��ܥ\����
bool login(char acc[],char pas[]);///�n�J����
bool create_account(char acc[],char pas[],char type);///�Ыرb��
//void mutator(char acc[],char pas[],char new_pas[]);///���K�X
int get_user_number(char acc[],char pas[]);///���o�ϥΪ̽s��
Account* acc_node();///���ͱb���`�I
//////////////////////////////////////////////


///////////////////////////////////////////////
///		    junk�B�ЪF�B�Фl�B�Ыȵ��c���ŧi		  	 ///
/*
�����G�o�̫غc���쵲��C Lindked List �O���V���`����
��p�G a <-> b <-> c <-> d �A��a�Bd�����p�Aa->prev �O a �ۤv�Ad->next �O NULL
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
///		    *�O�o* �b�o�̴��e�ŧi�@�U �Ƶ{��		  	 ///

// �@�ΰƵ{��
landlord* landlordBuild(); // �ЪF��Ʈw�ɤJ
house* houseBuild(); // �Фl��Ʈw�ɤJ
roomer* roomerBuild(); // �Ыȸ�Ʈw�ɤJ

// ��Фl�t�ΰƵ{��
void findHouse(); // ��Фl�t�ζi�J�I
house* generate_hou(); // ���ͩФl�`�I(node)
landlord* generate_lan(); // ���ͩЪF�`�I(node)
int printHouse(house*, landlord*); // �L�X�Фl��C�B��ܬd�ݸ�T
int houseFilter(house*, landlord*); // ��J���� & �z��Фl

//��Ǥͨt�ΰƵ{��
void findRoomer(); // ��Ǥͨt�ζi�J�I
roomer* generate_roo(); // ���ͫǤ͸`�I(node)
int printRoomer(roomer*); // �L�X�Ǥͦ�C�B��ܬd�ݸ�T
int roomerFilter(roomer*); // ��J���� & �z��Ǥ�

//�Ǥ͵������t��,�ЪF�������t��
void landlordGetScore(landlord*);
void roomerGetScore(roomer*);

///////////////////////////////////////////////

int main (void){

	int option = 0; //�\��ﶵ

	show_menu();//show���
	for(;;){//�L���j�骽���J���T���O

		if(scanf(" %d", & option) ==1 && option <=4 && option >= 1){//���J����ƥB���\��ﶵ�ɸ��X
            break;
		}

		else{//�ҥ~ ��ܿ��~�T�� ���s��ܿ�� �òM�ſ�J�w��
            printf("�L�Ī����O!!");
            system("pause");
            system("CLS");
            show_menu();
            fflush(stdin);
		}
	}


	if(option == 1){//�n�J����
        system("CLS");
	    printf("==�w��Ө�n�J����==\n");
        printf("�п�J�b��:");
        char acc[20],pas[20];
        scanf(" %s",acc);
        system("CLS");
        printf("==�w��Ө�n�J����==\n");
        printf("�п�J�b��:%s\n",acc);
        printf("�п�J�K�X:");
        scanf(" %s",pas);
        bool validate;
        validate = login(acc,pas);

        if(validate == true){
            system("CLS");
            printf("\n\t==�w�n�J!!==\n\n");
            system("pause");
            system("CLS");

        }

        if(validate == false){
            system("CLS");
            printf("\n\t==�n�J����!!==\n");
        }

	}
	else if(option == 2){//�s�رb��
        system("CLS");
	    printf("==�w�� �s�ϥΪ�==\n");
        printf("�п�J�b��:");
        char acc[20],pas[20],type;
        scanf(" %s",acc);
        system("CLS");
        printf("==�w�� �s�ϥΪ�==\n");
        printf("�п�J�b��:%s\n",acc);
        printf("�п�J�K�X:");
        scanf(" %s",pas);
        system("CLS");
        printf("==�w�� �s�ϥΪ�==\n");
        printf("�п�J�b��:%s\n",acc);
        printf("�п�J�K�X:%s\n",pas);
        printf("�п�J���O  �Ы�:r �ЪF:l :");
        scanf(" %c",& type);
        create_account(acc,pas,type);


	}
	/*else if(option == 3){//�ק�K�X
        system("CLS");
	    printf("==�w��Ө�n�J����==\n");
        printf("�п�J�b��:");
        char acc[20],pas[20];
        scanf(" %s",acc);
        system("CLS");
        printf("==�w��Ө�n�J����==\n");
        printf("�п�J�b��:%s\n",acc);
        printf("�п�J�K�X:");
        scanf(" %s",pas);
        bool validate;
        validate = login(acc,pas);
        if(validate == true){
            system("CLS");
            printf("\n\t==�w�n�J!!==\n�п�J�s�K�X:");
            char new_pas[20];
            scanf(" %s",new_pas);
            mutator(acc,pas,new_pas);
            system("pause");
            system("CLS");

        }

        if(validate == false){
            system("CLS");
            printf("\n\t==�n�J����!!==\n");
        }
	}*/
	else if(option == 3){//���}
        system("CLS");
        printf("\n\t<<~�P�±z�ϥΥ��t��~>>\n");
        printf("\n\t==���U���N�����}���t��==\n");
        return 0;
	}

}
///////////////////////////////////////////////
/// �@�� �Ƶ{���G		    ���ͩФl�`�I(node)		  	 ///
/// �w�Q�ΰƵ{���G��Фl�t��
house* generate_hou() {
	house *item = NULL;
	item = (house*)malloc(sizeof(house));
	item->next = NULL;
	item->prev = NULL;

	return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �@�� �Ƶ{���G		    ���ͩЪF�`�I(node)		  	 ///
/// �w�Q�ΰƵ{���G��Фl�t��
landlord* generate_lan() {
	landlord *item = NULL;
	item = (landlord*)malloc(sizeof(landlord));
	item->next = NULL;
	item->prev = NULL;

	return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �@�� �Ƶ{���G		    ���ͫǤ͸`�I(node)		  	 ///
/// �w�Q�ΰƵ{���G��Ǥͨt��
roomer* generate_roo() {
	roomer *item = NULL;
	item = (roomer*)malloc(sizeof(roomer));
	item->next = NULL;
	item->prev = NULL;

	return item;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �@�� �Ƶ{���G		    LandlordDatabase.txt�ɮ� �ЪF��Ʈw�ɤJ		  	 ///
/// �w�Q�ΰƵ{���G��Фl�t��

landlord* landlordBuild() {

	FILE *landlordFile;
	landlordFile = fopen("LandlordDatabase.txt", "r");
	if (landlordFile == NULL) { printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
	landlord *head_lan = NULL, *current_lan = NULL, *temp1;

	// ���D���B�z structure
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
	// �R���̫�@�Ӧh�l node
	current_lan = current_lan->prev;
	temp1 = current_lan->next;
	current_lan->next = NULL;
	free(temp1);

	// ���զL�X landlord link list
	current_lan = head_lan;
	printf("\n���զL�X�G\n");
	while (current_lan != NULL) {
		printf("%-15s %-2d %-2d %-2d %-30s %-30s\n", current_lan->LandlordName, current_lan->UserNumber, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);
		current_lan = current_lan->next;
	} printf("\n�H�W���զL�X\n");

	// �����
	fclose(landlordFile);

	/* �^�Ǥw�إߦn�� head �`�I */
	return head_lan;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �@�� �Ƶ{���G		    HouseDatabase.txt�ɮ� �Фl��Ʈw�ɤJ		  	 ///
/// �w�Q�ΰƵ{���G��Фl�t��

house* houseBuild() {

	FILE *houseFile;
	houseFile = fopen("HouseDatabase.txt", "r");
	if (houseFile == NULL) { printf("Fail to open file!\n"); exit(EXIT_FAILURE); }
	house *head_hou = NULL, *current_hou = NULL, *temp;

	// ���D���B�z structure
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
	// �R���̫�@�Ӧh�l node
	current_hou = current_hou->prev;
	temp = current_hou->next;
	current_hou->next = NULL;
	free(temp);

	// ���զL�X house link list
	current_hou = head_hou;
	printf("\n���զL�X�G\n");
	while (current_hou != NULL) {
		printf("%-5s %2d %-7g %-7g %-7g %-30s %-2d %-13s %-10s %-5s %-100s\n",
			current_hou->LandlordName, current_hou->Number, current_hou->Area,
			current_hou->Rent, current_hou->OtherCost, current_hou->Address,
			current_hou->PeopleNumber, current_hou->Network, current_hou->RoomType,
			current_hou->Pet, current_hou->Facilities);
		current_hou = current_hou->next;
	} printf("\n�H�W���զL�X\n");

	// �����
	fclose(houseFile);

	/* �^�Ǥw�إߦn�� head �`�I */
	return head_hou;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// �@�� �Ƶ{���G		    RoomerDatabase.txt�ɮ� �Ыȸ�Ʈw�ɤJ		  	 ///
/// �w�Q�ΰƵ{���G��Ǥͨt��

roomer* roomerBuild() { /* roomer ��Ʈw�ɥX�� Linked List */

	FILE *roomerFile;
	roomerFile = fopen("RoomerDatabase.txt", "r");
	if (roomerFile == NULL) { printf("Fail to open file!\n"); exit(EXIT_FAILURE); }

	roomer *head_roo = NULL, *current_roo = NULL, *temp1;

	// ���D���B�z structure
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
	// �R���̫�@�Ӧh�l node
	current_roo = current_roo->prev;
	temp1 = current_roo->next;
	current_roo->next = NULL;
	free(temp1);

	// ���զL�X landlord link list
	current_roo = head_roo;
	printf("\n���զL�X�G\n");
	while (current_roo != NULL) {
		printf("%-15s %-2d %-2d %-10s %2d:00 %-40s %-20s %-20s %-20s\n",
			current_roo->RoomerName, current_roo->UserNumber, current_roo->Star,
			current_roo->Gender, current_roo->SleepTime, current_roo->School,
			current_roo->Nationality, current_roo->Habit, current_roo->Disease);
		current_roo = current_roo->next;
	} printf("\n�H�W���զL�X\n");

	// �����
	fclose(roomerFile);

	/* �^�Ǥw�إߦn�� head �`�I */
	return head_roo;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ��Фl�t�� �D�{���G		    ��Фl�t�ζi�J�I		  	 ///
void findHouse() {
	house* head_hou = NULL;
	landlord* head_lan = NULL;

	/* �i��z�� & �^�Ǫ��A */
	// ���A 0�G���\&�h�X�{��
	// ���A 2�G���\&���s�z��
	int state = 2;
	while (state == 2) {
		head_hou = houseBuild(); // �إ� house linked list
		head_lan = landlordBuild(); // �إ� landlord linked list
		state = houseFilter(head_hou, head_lan);
	}

	printf("||> �h�X��Фl�t�ΡI\n");
	return;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ��Фl�t�� �Ƶ{���G		    �L�X�Фl��C�B��ܬd�ݸ�T		  	 ///
int printHouse(house *head_hou, landlord *head_lan) { /* �j����Фl��G�L�X�Фl��C�B��ܬd�ݸ�T */

	char name[15];
	int num;
	house *current_hou;
	landlord *current_lan;

	/* �L�X�Фl��C */
	printf("||> �ھڧA����ܡA�ŦX���󪺩Фl���G \n");
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

	/* �d�ݩФl���ԲӸ�T */
	printf("||> �п�J�ЪF�W�r&�Ǹ��H�d�ݸԲӸ�T(ex. \"Joe 0\"). \n|>> ");
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

	printf("||>�A��ܪ��Фl�G\n");
	printf("|====================================================================\n");
	printf("||>> Landlord Infomation: \n |> Name: %-15s Star: %-2d Number of house: %-2d \n |> Contact1: %-30s \n |> Contact2: %-30s\n",
		current_lan->LandlordName, current_lan->Star, current_lan->NumberOfHouse, current_lan->Contact1, current_lan->Contact2);

	printf("||>> House Infomation: \n |> Area:%-7g Rent:%-7g OtherCost:%-7g \n |> Address:%-30s \n |> PeopleNumber:%-2d Network:%-13s RoomType:%-10s Pet:%-5s \n |> Facilities:%-100s\n",
		current_hou->Area,
		current_hou->Rent, current_hou->OtherCost, current_hou->Address,
		current_hou->PeopleNumber, current_hou->Network, current_hou->RoomType,
		current_hou->Pet, current_hou->Facilities);
	printf("|====================================================================\n");

	/* �O�_���s�z��P�_ */
	int state = 0;
	printf("||> �O�_���s�z��Фl�H0�G�_�F2�G�O (ex. \"2\") \n|>> ");
	scanf("%d", &state);
	fflush(stdin);
	while (state != 0 && state != 2) {
		printf("||> �O�_���s�z��Фl�H0�G�_�F2�G�O (ex. \"0\") \n|>> ");
		scanf("%d", &state);
		fflush(stdin);
	}
	return state;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ��Фl�t�� �Ƶ{���G		    ��J���� & �z��Фl		  	 ///
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

	printf("\n||> �w��i�J��Фl�t�ΡI <|\n");
	printf("||> �Ы��n�D��J�z����� <|\n");
	printf("||> �Ҧ��i�z�����G�W�ơB�Я��B�J��H�ơB�����~��B�M��/���СB�i�_�i�d.\n");
	printf("|=======================================================================\n");

	printf("||> �z��W�ơH�O�G1�F�_�G0 \n|>> "); // �z��G�d��
	scanf("%d", &filter[0]);
	if (filter[0]) {
		printf("||> �п�J�d��(ex. \"10.5 20\")(��<�k): \n|>> ");
		scanf("%lf %lf", &filter0_a, &filter0_b);
		fflush(stdin);
		/* �P�w��J���� */
		while (filter0_a < 0 || filter0_b < 0 || filter0_a >= filter0_b) {
			printf("||> �п�J���T���d��(ex. \"0 36.5\")(��<�k): \n|>> ");
			scanf("%lf %lf", &filter0_a, &filter0_b);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->Area<filter0_a || current_hou->Area>filter0_b) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // ��@�`�I��C
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // ��C����
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // ��C�}�Y
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // ��C����
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
	printf("||> �z��Я��H�O�G1�F�_�G0 \n|>> "); // �z��G�d��
	scanf("%d", &filter[1]);
	if (filter[1]) {
		printf("||> �п�J�d��(ex. \"3000 4000\")(��<�k): \n|>> ");
		scanf("%lf %lf", &filter1_a, &filter1_b);
		fflush(stdin);
		/* �P�w��J���� */
		while (filter1_a < 0 || filter1_b < 0 || filter1_a >= filter1_b) {
			printf("||> �п�J���T���d��(ex. \"2000 8000\")(��<�k): \n|>> ");
			scanf("%lf %lf", &filter1_a, &filter1_b);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->Rent<filter1_a || current_hou->Rent>filter1_b) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // ��@�`�I��C
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // ��C����
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // ��C�}�Y
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // ��C����
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
	printf("||> �z��J��H�ơH�O�G1�F�_�G0 \n||> "); // �z��G�d��
	scanf("%d", &filter[2]);
	if (filter[2]) {
		printf("||> �п�J�d��(ex. \"1 1\")(��<=�k): \n|>> ");
		scanf("%d %d", &filter2_a, &filter2_b);
		fflush(stdin);
		/* �P�w��J���� */
		while (filter2_a <= 0 || filter2_b <= 0 || filter2_a > filter2_b) {
			printf("||> �п�J���T���d��(ex. \"2 5\")(��<=�k): \n|>> ");
			scanf("%d %d", &filter2_a, &filter2_b);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->PeopleNumber<filter2_a || current_hou->PeopleNumber>filter2_b) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // ��@�`�I��C
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // ��C����
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // ��C�}�Y
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // ��C����
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
	printf("||> �z������~��H�O�G1�F�_�G0 \n|>> "); // �z��G�h��
	scanf("%d", &filter[3]);
	if (filter[3]) {
		printf("||> �L�����GNo�F������,20M�G20M�F������,60M�G60M�F������,100M�G100M(ex. \"20M\") \n|>> ");
		scanf("%s", filter3);
		fflush(stdin);
		/* �P�w��J���� */
		while (strcasecmp(filter3, "No") && strcasecmp(filter3, "20M") && strcasecmp(filter3, "60M") && strcasecmp(filter3, "100M")) {
			printf("||> �п�J���T�����O(ex. \"No\") \n|>> ");
			scanf("%s", filter3);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (strncasecmp(current_hou->Network, filter3, 2)) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // ��@�`�I��C
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // ��C����
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // ��C�}�Y
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // ��C����
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
	printf("||> �z��M��/���СH�O�G1�F�_�G0 \n|>> "); // �z��G����
	scanf("%d", &filter[4]);
	if (filter[4]) {
		printf("||> �M�СGSuite�F���СGShare(ex. \"suite\") \n|>> ");
		scanf("%s", filter4);
		/* �P�w��J���� */
		while (strcasecmp(filter4, "Suite") && strcasecmp(filter4, "Share")) {
			printf("||> �п�J���T�����O(ex. \"Share\") \n|>> ");
			scanf("%s", filter4);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (current_hou->RoomType[1] != filter4[1]) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // ��@�`�I��C
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // ��C����
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // ��C�}�Y
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // ��C����
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
	printf("||> �z��i�_�i�d�H�O�G1�F�_�G0 \n|>> "); // �z��G����
	scanf("%d", &filter[5]);
	if (filter[5]) {
		printf("||> �i�i�d���GYes�F���i�i�d���GNo(ex. \"no\") \n|>> ");
		scanf("%s", filter5);
		/* �P�w��J���� */
		while (strcasecmp(filter5, "es") && strcasecmp(filter5, "No")) {
			printf("||> �п�J���T�����O(ex. \"Yes\") \n|>> ");
			scanf("%s", filter5);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_hou = head_hou;
		while (current_hou != NULL) {

			if (strncasecmp(current_hou->Pet, filter5, 2)) {
				tempNode = current_hou;
				if (current_hou == head_hou && current_hou->next == NULL) { // ��@�`�I��C
					head_hou = NULL; current_hou = NULL;
				}
				else if (current_hou->next == NULL) { // ��C����
					current_hou = current_hou->prev;
					current_hou->next = NULL;
					current_hou = NULL;
				}
				else if (current_hou == head_hou) { // ��C�}�Y
					head_hou = head_hou->next;
					head_hou->prev = head_hou;
					current_hou = head_hou;
				}
				else { // ��C����
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

	/* if �S���Фl */
	if (head_hou == NULL) {
		printf("||> �L�ŦX�n�D���Фl�I <| \n");
		printf("||> ���s�i�J�t�οz��C <| \n");
		return 2; // ���s�i�J�t�οz��
	}
	/* if ���Фl */
	else {
		int state = printHouse(head_hou, head_lan); // �L�X�ŦX����Фl�B��ܬd�ݸ�T
		return state;
	}

}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ��Ǥͨt�� �D�{���G		    ��Ǥͨt�ζi�J�I		  	 ///
void findRoomer() {
	roomer* head_roo = NULL;

	/* �i��z�� & �^�Ǫ��A */
	// ���A 0�G���\&�h�X�{��
	// ���A 2�G���\&���s�z��
	int state = 2;
	while (state == 2) {
		head_roo = roomerBuild(); // �إ� roomer linked list
		state = roomerFilter(head_roo);
	}

	printf("||> �h�X��Ǥͨt�ΡI\n");
	return;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ��Ǥͨt�� �Ƶ{���G		    �L�X�Ǥͦ�C�B��ܬd�ݸ�T		  	 ///
int printRoomer(roomer *head_roo) { /* �j����Ǥͫ�G�L�X�Ǥͦ�C�B��ܬd�ݸ�T */

	char name[15];
	roomer *current_roo;

	/* �L�X�Ǥͦ�C */
	printf("||> �ھڧA����ܡA�ŦX���󪺫Ǥͦ��G \n");
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

	/* �d�ݩФl���ԲӸ�T */
	printf("||> �п�J�ǤͦW�r�H�d�ݸԲӸ�T(ex. \"Jack\"). \n|>> ");
	scanf("%s", name);
	current_roo = head_roo;
	while (current_roo != NULL) {
		if (strcasecmp(current_roo->RoomerName, name) == 0) break;
		current_roo = current_roo->next;
	}

	printf("||>�A��ܪ��Ǥ͡G\n");
	printf("|====================================================================\n");
	printf("||>> Roomer Infomation: \n |> Name:%-15s Star:%-2d Gender:%-10s \n |> SleepTime:%2d:00 \n |> School:%-40s \n |> Nationality:%-20s \n |> Habit:%-20s \n |> Disease:%-20s \n",
		current_roo->RoomerName, current_roo->Star,
		current_roo->Gender, current_roo->SleepTime, current_roo->School,
		current_roo->Nationality, current_roo->Habit, current_roo->Disease);
	printf("|====================================================================\n");

	/* �O�_���s�z��P�_ */
	int state = 0;
	printf("||> �O�_���s�z��Ǥ͡H0�G�_�F2�G�O (ex. \"2\") \n|>> ");
	scanf("%d", &state);
	fflush(stdin);
	while (state != 0 && state != 2) {
		printf("||> �O�_���s�z��Ǥ͡H0�G�_�F2�G�O (ex. \"0\") \n|>> ");
		scanf("%d", &state);
		fflush(stdin);
	}
	return state;
}
///////////////////////////////////////////////

///////////////////////////////////////////////
/// ��Ǥͨt�� �Ƶ{���G		    ��J���� & �z��Ǥ�		  	 ///
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

	printf("\n||> �w��i�J��Ǥͨt�ΡI <|\n");
	printf("||> �Ы��n�D��J�z����� <|\n");
	printf("||> �Ҧ��i�z�����G�ʧO�B�ίv�ɶ��B�ǮաB���y.\n");
	printf("|=======================================================================\n");

	printf("||> �z��ʧO�H�O�G1�F�_�G0 \n|>> "); // �z��G����
	scanf("%d", &filter[0]);
	if (filter[0]) {
		printf("||> �k�GMale�F�k�GFemale(ex. \"Female\") \n|>> ");
		scanf("%s", filter0);
		fflush(stdin);
		/* �P�w��J���� */
		while (strcasecmp(filter0, "Male") && strcasecmp(filter0, "Female")) {
			printf("||> �п�J���T�����O(ex. \"male\") \n|>> ");
			scanf("%s", filter0);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_roo = head_roo;
		while (current_roo != NULL) {

			if (strcasecmp(filter0, current_roo->Gender)) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // ��@�`�I��C
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // ��C����
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // ��C�}�Y
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // ��C����
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
	printf("||> �z��ίv�ɶ��H�O�G1�F�_�G0 \n|>> "); // �z��G�d��
	scanf("%d", &filter[1]);
	if (filter[1]) {
		printf("||> �п�J�d��(���w��20�I��j��6�I)(ex. \"20 1\"(20�I��1�I))(����ɶ�����): \n|>> ");
		scanf("%d %d", &filter1_a, &filter1_b);
		fflush(stdin);
		/* �P�w��J���� */
		if (filter1_a <= 6) filter1_a += 24; // may result in false time
		if (filter1_b <= 6) filter1_b += 24; // may result in false time
		while (filter1_a < 20 || filter1_a>30 || filter1_b < 20 || filter1_b>30 || filter1_a > filter1_b) {
			printf("||> �п�J���T���d��(���w��20�I��j��6�I)(ex. \"23 23\"(23�I��1�I))(����ɶ�����) \n|>> ");
			scanf("%d %d", &filter1_a, &filter1_b);
			if (filter1_a <= 6) filter1_a += 24; if (filter1_b <= 6) filter1_b += 24;
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		int tempTime;
		current_roo = head_roo;

		while (current_roo != NULL) {

			if (current_roo->SleepTime <= 6) tempTime = current_roo->SleepTime + 24;
			else tempTime = current_roo->SleepTime;

			if (tempTime<filter1_a || tempTime>filter1_b) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // ��@�`�I��C
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // ��C����
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // ��C�}�Y
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // ��C����
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
	printf("||> �z��ǮաH�O�G1�F�_�G0 \n|>> "); // �z��G�h��
	scanf("%d", &filter[2]);
	if (filter[2]) {
		printf("||> �{�Ҥj�ǡGF�F�F���j�ǡGT�F�x����j�GS�F�����j�ǡGN�F������j�GO(ex. \"F\") \n|>> ");
		scanf("%c", &filter2);
		fflush(stdin);
		/* �P�w��J���� */
		while (filter2 != 'F' && filter2 != 'T' && filter2 != 'S' && filter2 != 'N' && filter2 != 'O') {
			printf("||> �п�J���T�����O(ex. \"T\") \n|>> ");
			scanf("%c", &filter2);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_roo = head_roo;
		while (current_roo != NULL) {

			if (filter2 != current_roo->School[0]) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // ��@�`�I��C
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // ��C����
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // ��C�}�Y
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // ��C����
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
	printf("||> �z����y�H�O�G1�F�_�G0 \n|>> "); // �z��G�h��
	scanf("%d", &filter[3]);
	if (filter[3]) {
		printf("||> �x�W�GTaiwan�F���Ӧ�ȡGMalaysia�F�饻�GJapan�F�L�ץ���ȡGIndonesia�F��߻��GPhilippine�F����j���GChina(ex. \"Taiwan\") \n|>> ");
		scanf("%s", filter3);
		/* �P�w��J���� */
		while (strcasecmp(filter3, "Taiwan") && strcasecmp(filter3, "Malaysia") && strcasecmp(filter3, "Japan") && strcasecmp(filter3, "Indonesia") && strcasecmp(filter3, "Philippine") && strcasecmp(filter3, "China")) {
			printf("||> �п�J���T�����O(ex. \"Suite\") \n|>> ");
			scanf("%s", filter3);
			fflush(stdin);
		}
		/* �R�����ŦX�n�D��node */
		current_roo = head_roo;
		while (current_roo != NULL) {

			if (strcasecmp(filter3, current_roo->Nationality)) {
				tempNode = current_roo;
				if (current_roo == head_roo && current_roo->next == NULL) { // ��@�`�I��C
					head_roo = NULL; current_roo = NULL;
				}
				else if (current_roo->next == NULL) { // ��C����
					current_roo = current_roo->prev;
					current_roo->next = NULL;
					current_roo = NULL;
				}
				else if (current_roo == head_roo) { // ��C�}�Y
					head_roo = head_roo->next;
					head_roo->prev = head_roo;
					current_roo = head_roo;
				}
				else { // ��C����
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

	/* if �S���Фl */
	if (head_roo == NULL) {
		printf("||> �L�ŦX�n�D���Фl�I <| \n");
		printf("||> ���s�i�J�t�οz��C <| \n");
		return 2; // ���s�i�J�t�οz��
	}
	/* if ���Фl */
	else {
		int state = printRoomer(head_roo); // �L�X�ŦX����Ǥ͡B��ܬd�ݸ�T
		return state;
	}
}
///////////////////////////////////////////////
//�s�W�ЪF,�Ǥ͵����t��
void landlordGetScore(landlord *landlordHead)
{
	char name[20];
	int score=0;

	landlord*ptr,*fprint;

	ptr=landlordHead;//ptr������Ъ���}

	printf("--�i�J�ЪF�����t��---\n");
	printf("�п�J�ݭn��������H\n");
	scanf("%s",name);

	while(ptr!=NULL)
	{
	    if(strcmp(name,ptr->LandlordName)==0)
	    {
		 break;//�o�ӵ�����H�s�b
	    }
	  ptr=ptr->next;
	}
	/*ptr�ثe���s�b��H*/

	if(ptr != NULL)//�P�_������H�s���s�b
	{
	    printf("��J�n������H������(1-10)\n");
		scanf("%d",&score);

		if( score<=10 && score>=1 && ptr->Star<=10 && ptr->Star>=1)//�w�g�Q�����L���O�٭n����������
		{
		  printf("---�H�����L����H---\n");
		  ptr->Star = double(score+ptr->Star)/2;
		}
		else if( score<=10 && score>=1)//�q����������
		{
		  ptr->Star=score;
		}
		else //���~����
		{
		 printf("�������~ ,�ϥΪ̿�J���b������(���ܨϥΪ̿�J���~�Э�)");
		}

	}
	else//���⤣�s�b��X
	{
	 printf("��J���s�b�W�r �ο��~���Ʀr");
	}

	if( score<=10 && score>=1)
	{
	 printf("��J�O���骺����:%2d",ptr->Star);
	}
	//////////////////////////////////////////////////
	FILE *landlordFile;
	landlordFile = fopen("LandlordDatabase.txt", "w");

	fprint=landlordHead;//���Ы��V���Y

	fprintf(landlordFile,"%-15s %-10s %-10s %-30s %-30s %-30s\n","Name","UserNumber","Star","NumberOfHouse","Contact1","Contact2");
	while(fprint != NULL)//�N���������ɮ׿�J��Ʈw
	{
	    fprintf(landlordFile,"%-15s %-10d %-10d %-30d %-30s %-30s \n",
			     fprint->LandlordName, fprint->UserNumber, fprint->Star,
			     fprint->NumberOfHouse, fprint->Contact1, fprint->Contact2);

	   fprint=fprint->next;
	}

	fclose(landlordFile);//����

}
void roomerGetScore(roomer*roomerHead)
{

	char name[20];
	int i=0 , score=0;
	roomer*ptr, *fprint;

	ptr=roomerHead;//ptr������Ъ���}

	printf("--�i�J�Ǥ͵����t��---\n");
	printf("�п�J�ݭn��������H:\n");
	scanf("%s",name);

	while(ptr!=NULL)
	{
	    if(strcmp(name,ptr->RoomerName)==0)
	    {
		  break;//�o�ӵ�����H�s�b
	    }
	  ptr=ptr->next;
	}

	/*ptr�ثe���s�b��H*/

	if(ptr != NULL)//�P�_������H�s���s�b
	{
	    printf("��J�n������H������(1-10)\n");
		scanf("%d",&score);

		if( score<=10 && score>=1 && ptr->Star<=10 && ptr->Star>=1 )//�w�g�Q�����L���O�٭n����������
		{
		  printf("---�H�����L����H---\n");
		  ptr->Star = double(score+ptr->Star)/2;
		}
		else if( score<=10 && score>=1)//�q����������
		{
		  ptr->Star=score;
		}
		else //���~����
		{
		  printf("�������~ ,�ϥΪ̿�J���b������(���ܨϥΪ̿�J���~�Э�)");
		}

	}
	else //���⤣�s�b��X
	{
	 printf("��J���s�b�W�r �ο��~���Ʀr");
	}

    if( score<=10 && score>=1)
	{
	   printf("��J�O���骺����:%2d",ptr->Star);
    }
	//////////////////////////////////////////////////////
	   FILE *roomerFile;
	   roomerFile = fopen("RoomerDatabase.txt","w");//�}���ɮ�
	   fprint=roomerHead;

	   fprintf(roomerFile,"%-15s %-14s %-8s %-10s %-15s %-40s %-20s %-20s %-20s\n","Name","UserNumber","Star","Gender","SleepTime","School","Nationality","Habit","Disease");
	   while(fprint!=NULL)//�N���������ɮ׿�J��Ʈw
	  {
	     fprintf(roomerFile,"%-15s %-14d %-8d %-10s %-15d %-40s %-20s %-20s %-20s\n",
			     fprint->RoomerName, fprint->UserNumber, fprint->Star,
			     fprint->Gender, fprint->SleepTime, fprint->School,
			     fprint->Nationality, fprint->Habit, fprint->Disease);
		 fprint=fprint->next;
	  }

	fclose(roomerFile);//����
}
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///		    �n�J�t�ΥΰƵ{��		  	 ///
///////////////////////////////////////////////

///��ܥ\����
void show_menu() {
    printf("<<�w��ϥΧ�Ǥͨt��>>\n");
    printf("���U�Ʀr���ܪA��\n");
    printf("1.�n�J\t\t2.�s�W�b��\n3.���}�t��\n");
    printf("�п�J�A�ȿﶵ:");
}

///�n�J����///		*true = �n�J���\ *false = �n�J����
bool login(char acc[],char pas[]) {
    int login = 0;
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "r");
    if (acc_open == NULL) {
        printf("�L�k�s���b����Ʈw!!\n");
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
///���͸`�I
Account* acc_node() {
	Account *node = NULL;
	node = (Account*)malloc(sizeof(Account));
	node->next = NULL;
	node->previous = NULL;

	return node;
}

///�Ыرb��///		*true = �Ыئ��\ *false = �Ыإ���
bool create_account(char acc[],char pas[],char type) {
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "a");
    if (acc_open == NULL) {
        printf("�L�k�s���b����Ʈw!!\n");
        system("pause");
        return false;
    }
    int num =0;
    Account *head_acc = NULL, *current_acc = NULL;
	Title title;
	fscanf(acc_open," %s %s %s %s",title.num,title.type,title.acc,title.pas );

    head_acc = acc_node();
    head_acc->previous = head_acc;
	current_acc = head_acc;

	while (fscanf(acc_open,"%d %c %s %s",&current_acc->num, &current_acc->type, current_acc->account,current_acc->password) != EOF) {
		current_acc->next = acc_node();
		current_acc = current_acc->next;

	}
    current_acc->next = acc_node();
    num = current_acc->num + 1;



    fprintf(acc_open,"\n%d\t%c\t%s\t%s",num,type,acc,pas);
    fclose(acc_open);
    return true;
}

///���K�X
/*void mutator(char acc[],char pas[],char new_pas[]) {
   int login = 0;
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "r");
    if (acc_open == NULL) {
        printf("�L�k�s���b����Ʈw!!\n");
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
            //���N�\��
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

//���O �P��Ʈw�s�ʪ�user number���o�Ƶ{���ٶ��s�W <<�G�ܤ@>> 1.�n�J���Ҧ^�ǭȬ�int = user number  2.�h�g�@��get user number���Ƶ{��

///���o�ϥΪ̽s��
int get_user_number(char acc[],char pas[]){
    int login = 0;
    FILE *acc_open;
    acc_open = fopen("accountDatabase.txt", "r");
    if (acc_open == NULL) {
        printf("�L�k�s���b����Ʈw!!\n");
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
