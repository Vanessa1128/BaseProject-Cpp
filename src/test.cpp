
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string>

using namespace std;

///�Ƶ{���ŧi��
//////////////////////////////////////////////
void show_menu();///��ܥ\����
bool login(string acc,string pas);///�n�J����
bool create_account(string acc,string pas);///�Ыرb��
void mutator(string pas);///���K�X
int get_user_number(string acc,string pas);///���o�ϥΪ̽s��
//////////////////////////////////////////////
///���c�ŧi
//////////////////////////////////////////////
typedef struct {
	char num[8]; char type[8]; char acc[8];
	char pas[8];
} account_database_title;//�����b���Ʈw���Ĥ@��

typedef struct account{//�b�����c
	int num[8];
	char type;
	char account[20];
	char password[20];

	struct account *next, *previous;
} account_data;
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
        string acc,pas;
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
            printf("\n\t==�w�n�J!!==\n");
        }

        if(validate == false){
            system("CLS");
            printf("\n\t==�n�J����!!==\n");
        }

	}
	else if(option == 2){//�s�رb��

	}
	else if(option == 3){//�ק�K�X

	}
	else if(option == 4){//���}
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
    printf("1.�n�J\t\t2.�s�W�b��\n3.�ק�K�X\t4.���}�t��\n");
    printf("�п�J�A�ȿﶵ:");
}

///�n�J����///		*true = �n�J���\ *false = �n�J����
bool login(string acc,string pas) {
    return true;
}

///�Ыرb��///		*true = �Ыئ��\ *false = �Ыإ���
bool create_account(string acc,string pas) {

}

///���K�X
void mutator(string pas) {

}

//���O �P��Ʈw�s�ʪ�user number���o�Ƶ{���ٶ��s�W <<�G�ܤ@>> 1.�n�J���Ҧ^�ǭȬ�int = user number  2.�h�g�@��get user number���Ƶ{��

///���o�ϥΪ̽s��
int get_user_number(string acc,string pas){

}
