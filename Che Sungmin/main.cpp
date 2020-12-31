
//C��� �ְܼ��� ����

//======================== ���� ���� ====================

#include<stdio.h>
#include<windows.h>
#include<conio.h>

//gotoxy �Լ�
void gotoxy(int x, int y);
void cursor(int n);
void startScreen();
void explanationScreen();
//���� 1
void playScreen();
//���� 2
void Screen00();
//���� 3
void Screen01();
//���� 4
void Screen02();
//���� 5
void Screen03();
//������ ȭ��
void lastScreen();
//���� ǥ��
void scoreScreen();

void Init() {

}

void Update() {
	
}

void Render() {
	startScreen();

}

int score = 5;

int main() {
	//�ܼ�â ũ�� ����
	system("mode con cols=80 lines=30");
	cursor(0);
	Render();
}

void gotoxy(int x, int y){
	//�Ű� �������� ������ x,y ��ǥ�� Ŀ�� �̵�
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursor(int n){
	// �ܼ��� �ڵ�
	HANDLE hConsole;
	//�ܼ� Ŀ�� ���� ����ü
	CONSOLE_CURSOR_INFO ConsoleCursor;
	//hConsole�� �ؿ� ���� ���� �־��ش�
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//n�� 1�̸� �Ⱥ��̰� 0�̸� ���̰� �����.
	ConsoleCursor.bVisible = n;
	//Ŀ�� ������
	ConsoleCursor.dwSize = 1;

	//�ܼ�(�ܼ� �ڵ�� ����ü) ����
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void scoreScreen() {
	gotoxy(9, 8);
	printf("���������������������������� �Ѽ� ���� ����!  ������������������������");
	for (int i = 9; i < 22; i++) {
		gotoxy(9, i);
		printf("��                                                                  ��");
	}
	gotoxy(9, 21);
	printf("����������������������������������������������������������������������");
	gotoxy(11, 7);
	if (score < 1) {
		printf("�� �� �� �� ��");
	}
	else if (score < 2) {
		printf("�� �� �� �� ��");
	}
	else if (score < 3) {
		printf("�� �� �� �� ��");
	}
	else if (score < 4) {
		printf("�� �� �� �� ��");
	}
	else if (score < 5) {
		printf("�� �� �� �� ��");
	}
	else if (score < 6) {
		printf("�� �� �� �� ��");
	}
}

void startScreen() {
	system("cls");
	score = 5;
	gotoxy(15, 8);
	printf("��----------- �Ѽ� ���� ����!  -----------��");
	for (int i = 9; i < 18; i++) {
		gotoxy(15, i);
		printf("��                                        ��");
	}
	gotoxy(15, 18);
	printf("��������������������������������������������");

	gotoxy(30, 11);
	printf(">> ����   (o Ű) \n");
	gotoxy(30, 13);
	printf(">> ����   (s Ű) \n");
	gotoxy(30, 15);
	printf(">> ������ (e Ű)");

	char move;
	int x = 27;
	int y = 11;
	gotoxy(x, y);
	while (1) {
		move = _getch();
		gotoxy(x, y);
		printf(" ");
		switch (move) {
		case 'o':
			//�� �̵�
			explanationScreen();
			break;
		case 's':
			//�� �̵�
			playScreen();
			break;
		case 'e':
			//�� �̵�
			system("cls");
			gotoxy(25, 15);
			printf("\"���� ������ ���� �Ǿ����ϴ�\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(0);
			break;
		case 'k':
			startScreen();
			break;
		}
	}

			gotoxy(x, y);
			printf("V");
		//if()
	}


void explanationScreen(){
	system("cls");
	gotoxy(24, 8);
	printf("�Ѽ����̹�����б� ���� ����!!\n");
	gotoxy(24, 10);
	printf("- O, X ���� ���� ����Դϴ�!\n");
	gotoxy(24, 12);
	printf("- ����� eŰ�� �����ּ���");
	gotoxy(24, 14);
	printf("- �ټ����� ������ �����ּ���!");
	gotoxy(24, 16);
	printf("- s�� ���� �ٽ� �õ� �ϼŵ� ������ ���ֽ��ϴ�.");
	gotoxy(24, 18);
	printf(">> Ȯ���ϼ����� s�� �����ּ��� <<\n\n");

}

void playScreen() {
	system("cls");
	scoreScreen();
	gotoxy(12, 10);
	printf("���� 1��\n\n");
	gotoxy(12, 11);
	printf("�Ѽ����̹����Ȱ���б��� ���� ������� 10�� 5���̴�.\n");
	gotoxy(12, 13);
	printf("O & X");
	gotoxy(12, 15);
	printf("= ");

	char number = 0;
	while (1) {
		number = _getch();
		int x = 24;
		int y = 16;
		gotoxy(x, y);
		printf(" ");
		switch (number) {
		case 'o':
			gotoxy(12, 15);
			printf("= O");
			gotoxy(12, 16);
			printf("�¾ҽ��ϴ�!");
			gotoxy(12, 18);
			printf("n�� ���� ���� ������ �Ѿ �ּ���");
			break;
			case 'n':
				Screen00();
				break;
			break;

		case 'x':
			gotoxy(12, 15);
			printf("= X");
			gotoxy(12, 16);
			printf("Ʋ�Ƚ��ϴ�!");
			gotoxy(12, 17);
			printf("���� : ���� ������� 10�� 5���Դϴ�.");
			gotoxy(12, 20);
			printf("n�� ���� ���� ������ �Ѿ�ų� s��ư�� ���� �ٽ� �õ��� �ּ���");
			score--;
			break;

		case 'e':
			//�� �̵�
			system("cls");
			gotoxy(25, 15);
			printf("\"���� ������ ���� �Ǿ����ϴ�\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(0);
			break;

		case 's':
			startScreen();
			break;

		}
	}
}

void Screen00() {
	system("cls");
	scoreScreen();
	gotoxy(12, 10);
	printf("���� 2��\n\n");
	gotoxy(12, 11);
	printf("�Ѽ����̹����Ȱ���б��� ���� �а��� 3���̴�.(2019 ~ 2020�� ����)\n");
	gotoxy(12, 13);
	printf("O & X");
	gotoxy(12, 15);
	printf("= ");

	char number = 0;
	while (1) {
		number = _getch();
		int x = 24;
		int y = 16;
		gotoxy(x, y);
		printf(" ");
		switch (number) {
		case 'o':
			gotoxy(12, 15);
			printf("= O");
			gotoxy(12, 16);
			printf("Ʋ�Ƚ��ϴ�!");
			gotoxy(12, 17);
			printf("���� : ���� �а��� �ΰ��Դϴ�. (���Ӱ�, ��ŷ���Ȱ���)");
			gotoxy(12, 18);
			printf("��Ʈ��ũ ���Ȱ� ��ŷ ������ ���յǾ��ֽ��ϴ�.");
			gotoxy(12, 20);
			printf("n�� ���� ���� ������ �Ѿ�ų� s��ư�� ���� �ٽ� �õ��� �ּ���");
			score--;
			break;

		case 'x':
			gotoxy(12, 15);
			printf("= X");
			gotoxy(12, 16);
			printf("�¾ҽ��ϴ�!");
			gotoxy(12, 18);
			printf("n�� ���� ���� ������ �Ѿ �ּ���");
			break;
			case 'n':
				Screen01();
				break;
			break;

		case 'e':
			//�� �̵�
			system("cls");
			gotoxy(25, 15);
			printf("\"���� ������ ���� �Ǿ����ϴ�\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(0);
			break;

		case 's':
			startScreen();
			break;
		}
	}
}

void Screen01() {
	system("cls");
	scoreScreen();
	gotoxy(12, 10);
	printf("���� 3��\n\n");
	gotoxy(12, 11);
	printf("�Ѽ����̹����Ȱ���б��� �ֿ� ����ö�� �ֿ�����, ������, ������ \n");
	gotoxy(12, 12);
	printf("�׸��� �Ѽ����� �ִ�");
	gotoxy(12, 13);
	printf("O & X");
	gotoxy(12, 15);
	printf("= ");

	char number = 0;
	while (1) {
		number = _getch();
		int x = 24;
		int y = 16;
		gotoxy(x, y);
		printf(" ");
		switch (number) {
		case 'o':
			gotoxy(12, 15);
			printf("= O");
			gotoxy(12, 16);
			printf("Ʋ�Ƚ��ϴ�!");
			gotoxy(12, 17);
			printf("���� : �Ѽ����̹����Ȱ���б� ��ó�� �Ѽ����� ���������ʽ��ϴ�.");
			gotoxy(12, 20);
			printf("n�� ���� ���� ������ �Ѿ�ų� s��ư�� ���� �ٽ� �õ��� �ּ���");
			score--;
			break;

		case 'x':
			gotoxy(12, 15);
			printf("= X");
			gotoxy(12, 16);
			printf("�¾ҽ��ϴ�!");
			gotoxy(12, 18);
			printf("n�� ���� ���� ������ �Ѿ �ּ���");
			break;
			case 'n':
				Screen02();
				break;
			break;

		case 'e':
			//�� �̵�
			system("cls");
			gotoxy(25, 15);
			printf("\"���� ������ ���� �Ǿ����ϴ�\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(0);
			break;

		case 's':
			startScreen();
			break;
		}
	}
}

void Screen02() {
		system("cls");
		scoreScreen();
		gotoxy(12, 10);
		printf("���� 4��\n\n");
		gotoxy(12, 11);
		printf("�Ѽ����̹����Ȱ���б��� ��������̴�\n");
		gotoxy(12, 13);
		printf("O & X");
		gotoxy(12, 15);
		printf("= ");

		char number = 0;
		while (1) {
			number = _getch();
			int x = 24;
			int y = 16;
			gotoxy(x, y);
			printf(" ");
			switch (number) {
			case 'o':
				gotoxy(12, 15);
				printf("= O");
				gotoxy(12, 16);
				printf("�¾ҽ��ϴ�!");
				gotoxy(12, 18);
				printf("n�� ���� ���� ������ �Ѿ�ų� s��ư�� ���� �ٽ� �õ��� �ּ���");
				break;
				case 'n':
					Screen03();
					break;
				break;

			case 'x':
				gotoxy(12, 15);
				printf("= X");
				gotoxy(12, 16);
				printf("Ʋ�Ƚ��ϴ�!");
				gotoxy(12, 17);
				printf("���� : �Ѽ����̹����Ȱ���б��� ��������� �½��ϴ�");
				gotoxy(12, 20);
				printf("s��ư�� ���� �ٽ� �õ��� �ּ���");
				score--;
				break;

			case 'e':
				//�� �̵�
				system("cls");
				gotoxy(25, 15);
				printf("\"���� ������ ���� �Ǿ����ϴ�\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
				exit(0);
				break;

			case 's':
				startScreen();
				break;
			}
		}
	}

void Screen03() {
		system("cls");
		scoreScreen();
		gotoxy(12, 10);
		printf("���� 5��\n\n");
		gotoxy(12, 11);
		printf("�Ѽ����̹����Ȱ���б��� ������ ���� ���� ���� ū ��� �����̴�.\n");
		gotoxy(12, 13);
		printf("O & X");
		gotoxy(12, 15);
		printf("= ");
		char number = 0;
		while (1) {
			number = _getch();
			int x = 24;
			int y = 16;
			gotoxy(x, y);
			printf(" ");
			switch (number) {
			case 'o':
				gotoxy(12, 15);
				printf("= O");
				gotoxy(12, 16);
				printf("Ʋ�Ƚ��ϴ�!");
				gotoxy(12, 17);
				printf("���� : ������ �ٸ� ���� ���� ū ��� �����̴�.");
				gotoxy(12, 20);
				printf("n�� ���� ���� ȭ������ �Ѿ�ų� s��ư�� ���� �ٽ� �õ��� �ּ���");
				score--;
				break;
			case 'x':
				gotoxy(12, 15);
				printf("= X");
				gotoxy(12, 16);
				printf("�¾ҽ��ϴ�!");
				gotoxy(12, 18);
				printf("n�� ���� ���� ȭ������ �Ѿ �ּ���");
				break;
				case 'n':
					lastScreen();
					break;
				break;

			case 'e':
				//�� �̵�
				system("cls");
				gotoxy(25, 15);
				printf("\"���� ������ ���� �Ǿ����ϴ�\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
				exit(0);
				break;
			case 's':
				startScreen();
				break;
			}
		}
	}

void lastScreen(){
		system("cls");
		gotoxy(40, 15);
		switch (score){
		case 5:
			gotoxy(20, 10);
			printf("============= �� �� �� �� �� =============");
			gotoxy(27, 12);
			printf(" ��� ���߼̳׿� �� �Ѽ���");
			gotoxy(20, 14);
			printf("============= �� �� �� �� �� =============");
			break;
		case 4:
			gotoxy(20, 10);
			printf("============= �� �� �� �� �� =============");
			gotoxy(27, 12);
			printf(" �� ���� Ʋ���̳׿� �Ʊ����");
			gotoxy(20, 14);
			printf("============= �� �� �� �� �� =============");
			break;
		case 3:
			gotoxy(20, 10);
			printf("============= �� �� �� �� �� =============");
			gotoxy(27, 12);
			printf(" ��� ���� �̰� ����鼭 �˾Ҿ��");
			gotoxy(20, 14);
			printf("============= �� �� �� �� �� =============");
			break;
		case 2:
			gotoxy(20, 10);
			printf("============= �� �� �� �� �� =============");
			gotoxy(27, 12);
			printf(" �� �ٽ� �ѹ� �õ��� ������!");
			gotoxy(20, 14);
			printf("============= �� �� �� �� �� =============");
			break;
		case 1:
			gotoxy(20, 10);
			printf("============= �� �� �� �� �� =============");
			gotoxy(27, 12);
			printf(" �ϳ� ���߼̳׿� �Ҹ� �Ѽ���");
			gotoxy(20, 14);
			printf("============= �� �� �� �� �� =============");
			break;
		case 0:
			gotoxy(20, 10);
			printf("============= �� �� �� �� �� =============");
			gotoxy(27, 12);
			printf(" �ܺ����̽ó׿� �ܺ��� ���� ���� ");
			gotoxy(20, 14);
			printf("============= �� �� �� �� �� =============");
			break;
		}
	}
