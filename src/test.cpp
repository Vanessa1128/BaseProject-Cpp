#include<stdio.h>
#include<stdlib.h>
#include<iostream>
void show_menu();

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


	if(option == 1){

	}
	else if(option == 2){

	}
	else if(option == 3){

	}
	else if(option == 4){

	}

	//switch�g�k �����U�\��
	//1.login
	//2.create account
	//3.quit
	//4.��K�X

    return 0;
}

///////////////////////////////////////////////
///		    �Ƶ{��		  	 ///
///////////////////////////////////////////////

///��ܥ\����
void show_menu() {
    printf("<<�w��ϥΧ�Ǥͨt��>>\n");
    printf("���U�Ʀr���ܪA��\n");
    printf("1.�n�J  2.�s�رb�� 3.�ק�K�X 4.���}�t��\n");
    printf("�п�J�A�ȿﶵ:");
}

///�n�J����///		*true = �n�J���\ *false = �n�J����
bool login(/*�b���K�X*/) {

}

///�Ыرb��///		*true = �Ыئ��\ *false = �Ыإ���
bool create_account(/*�b����T*/) {

}

///���K�X
void mutator(/*����諸¾*/) {

}

//���O �P��Ʈw�s�ʪ�user number���o�Ƶ{���ٶ��s�W <<�G�ܤ@>> 1.�n�J���Ҧ^�ǭȬ�int = user number  2.�h�g�@��get user number���Ƶ{��

