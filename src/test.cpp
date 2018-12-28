
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string.h>

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
///		    �Ƶ{��		  	 ///
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
    acc_open = fopen("accountDatabase.txt", "w");
    if (acc_open == NULL) {
        printf("�L�k�s���b����Ʈw!!\n");
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
