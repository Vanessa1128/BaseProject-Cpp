#include<stdio.h>

void show_menu();

int main (void){
	
	int option; //�\��ﶵ 
	
	show_menu();//show���
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
	//switch�g�k �����U�\��
	//1.login
	//2.create account
	//3.quit
	//4.��K�X


}

///////////////////////////////////////////////
///		    �Ƶ{��		  	 ///
///////////////////////////////////////////////

///��ܥ\����
void show_menu() {
    printf("<<�w��ϥΧ�Ǥͨt��>>\n");
    printf("���U�Ʀr���ܪA��\n");
    printf("1.�n�J  2.�s�رb�� 3.���}�t��\n");
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

