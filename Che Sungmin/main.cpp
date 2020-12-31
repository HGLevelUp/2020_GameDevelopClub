
//C언어 콘솔게임 개발

//======================== 퀴즈 게임 ====================

#include<stdio.h>
#include<windows.h>
#include<conio.h>

//gotoxy 함수
void gotoxy(int x, int y);
void cursor(int n);
void startScreen();
void explanationScreen();
//문제 1
void playScreen();
//문제 2
void Screen00();
//문제 3
void Screen01();
//문제 4
void Screen02();
//문제 5
void Screen03();
//마지막 화면
void lastScreen();
//점수 표시
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
	//콘솔창 크기 조절
	system("mode con cols=80 lines=30");
	cursor(0);
	Render();
}

void gotoxy(int x, int y){
	//매개 변수에서 지정한 x,y 좌표로 커서 이동
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursor(int n){
	// 콘솔의 핸들
	HANDLE hConsole;
	//콘솔 커서 정보 구조체
	CONSOLE_CURSOR_INFO ConsoleCursor;
	//hConsole에 밑에 값을 구해 넣어준다
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//n이 1이면 안보이고 0이면 보이게 만든다.
	ConsoleCursor.bVisible = n;
	//커서 사이즈
	ConsoleCursor.dwSize = 1;

	//콘솔(콘솔 핸들과 구조체) 설정
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void scoreScreen() {
	gotoxy(9, 8);
	printf("┌───────────── 한세 퀴즈 게임!  ───────────┐");
	for (int i = 9; i < 22; i++) {
		gotoxy(9, i);
		printf("│                                                                  │");
	}
	gotoxy(9, 21);
	printf("└─────────────────────────────────┘");
	gotoxy(11, 7);
	if (score < 1) {
		printf("☆ ☆ ☆ ☆ ☆");
	}
	else if (score < 2) {
		printf("★ ☆ ☆ ☆ ☆");
	}
	else if (score < 3) {
		printf("★ ★ ☆ ☆ ☆");
	}
	else if (score < 4) {
		printf("★ ★ ★ ☆ ☆");
	}
	else if (score < 5) {
		printf("★ ★ ★ ★ ☆");
	}
	else if (score < 6) {
		printf("★ ★ ★ ★ ★");
	}
}

void startScreen() {
	system("cls");
	score = 5;
	gotoxy(15, 8);
	printf("┌----------- 한세 퀴즈 게임!  -----------┐");
	for (int i = 9; i < 18; i++) {
		gotoxy(15, i);
		printf("│                                        │");
	}
	gotoxy(15, 18);
	printf("└────────────────────┘");

	gotoxy(30, 11);
	printf(">> 설명   (o 키) \n");
	gotoxy(30, 13);
	printf(">> 시작   (s 키) \n");
	gotoxy(30, 15);
	printf(">> 나가기 (e 키)");

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
			//씬 이동
			explanationScreen();
			break;
		case 's':
			//씬 이동
			playScreen();
			break;
		case 'e':
			//씬 이동
			system("cls");
			gotoxy(25, 15);
			printf("\"퀴즈 게임이 종료 되었습니다\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
	printf("한세사이버고등학교 퀴즈 게임!!\n");
	gotoxy(24, 10);
	printf("- O, X 퀴즈 게임 방식입니다!\n");
	gotoxy(24, 12);
	printf("- 종료는 e키를 눌러주세요");
	gotoxy(24, 14);
	printf("- 다섯개의 문제를 맞춰주세요!");
	gotoxy(24, 16);
	printf("- s를 눌러 다시 시도 하셔도 점수는 깎여있습니다.");
	gotoxy(24, 18);
	printf(">> 확인하셨으면 s를 눌러주세요 <<\n\n");

}

void playScreen() {
	system("cls");
	scoreScreen();
	gotoxy(12, 10);
	printf("문제 1번\n\n");
	gotoxy(12, 11);
	printf("한세사이버보안고등학교의 개교 기념일은 10월 5일이다.\n");
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
			printf("맞았습니다!");
			gotoxy(12, 18);
			printf("n을 눌러 다음 문제로 넘어가 주세요");
			break;
			case 'n':
				Screen00();
				break;
			break;

		case 'x':
			gotoxy(12, 15);
			printf("= X");
			gotoxy(12, 16);
			printf("틀렸습니다!");
			gotoxy(12, 17);
			printf("정답 : 개교 기념일은 10월 5일입니다.");
			gotoxy(12, 20);
			printf("n을 눌러 다음 문제로 넘어가거나 s버튼을 눌러 다시 시도해 주세요");
			score--;
			break;

		case 'e':
			//씬 이동
			system("cls");
			gotoxy(25, 15);
			printf("\"퀴즈 게임이 종료 되었습니다\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
	printf("문제 2번\n\n");
	gotoxy(12, 11);
	printf("한세사이버보안고등학교의 모집 학과는 3개이다.(2019 ~ 2020년 기준)\n");
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
			printf("틀렸습니다!");
			gotoxy(12, 17);
			printf("정답 : 모집 학과는 두개입니다. (게임과, 해킹보안과정)");
			gotoxy(12, 18);
			printf("네트워크 보안과 해킹 보안이 통합되어있습니다.");
			gotoxy(12, 20);
			printf("n을 눌러 다음 문제로 넘어가거나 s버튼을 눌러 다시 시도해 주세요");
			score--;
			break;

		case 'x':
			gotoxy(12, 15);
			printf("= X");
			gotoxy(12, 16);
			printf("맞았습니다!");
			gotoxy(12, 18);
			printf("n을 눌러 다음 문제로 넘어가 주세요");
			break;
			case 'n':
				Screen01();
				break;
			break;

		case 'e':
			//씬 이동
			system("cls");
			gotoxy(25, 15);
			printf("\"퀴즈 게임이 종료 되었습니다\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
	printf("문제 3번\n\n");
	gotoxy(12, 11);
	printf("한세사이버보안고등학교의 주요 지하철은 애오개역, 공덕역, 아현역 \n");
	gotoxy(12, 12);
	printf("그리고 한세역이 있다");
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
			printf("틀렸습니다!");
			gotoxy(12, 17);
			printf("정답 : 한세사이버보안고등학교 근처에 한세역은 존재하지않습니다.");
			gotoxy(12, 20);
			printf("n을 눌러 다음 문제로 넘어가거나 s버튼을 눌러 다시 시도해 주세요");
			score--;
			break;

		case 'x':
			gotoxy(12, 15);
			printf("= X");
			gotoxy(12, 16);
			printf("맞았습니다!");
			gotoxy(12, 18);
			printf("n을 눌러 다음 문제로 넘어가 주세요");
			break;
			case 'n':
				Screen02();
				break;
			break;

		case 'e':
			//씬 이동
			system("cls");
			gotoxy(25, 15);
			printf("\"퀴즈 게임이 종료 되었습니다\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
		printf("문제 4번\n\n");
		gotoxy(12, 11);
		printf("한세사이버보안고등학교는 남녀공학이다\n");
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
				printf("맞았습니다!");
				gotoxy(12, 18);
				printf("n을 눌러 다음 문제로 넘어가거나 s버튼을 눌러 다시 시도해 주세요");
				break;
				case 'n':
					Screen03();
					break;
				break;

			case 'x':
				gotoxy(12, 15);
				printf("= X");
				gotoxy(12, 16);
				printf("틀렸습니다!");
				gotoxy(12, 17);
				printf("정답 : 한세사이버보안고등학교는 남녀공학이 맞습니다");
				gotoxy(12, 20);
				printf("s버튼을 눌러 다시 시도해 주세요");
				score--;
				break;

			case 'e':
				//씬 이동
				system("cls");
				gotoxy(25, 15);
				printf("\"퀴즈 게임이 종료 되었습니다\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
		printf("문제 5번\n\n");
		gotoxy(12, 11);
		printf("한세사이버보안고등학교의 교훈은 착한 마음 갖고 큰 사람 되자이다.\n");
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
				printf("틀렸습니다!");
				gotoxy(12, 17);
				printf("정답 : 교훈은 바른 마음 갖고 큰 사람 되자이다.");
				gotoxy(12, 20);
				printf("n을 눌러 다음 화면으로 넘어가거나 s버튼을 눌러 다시 시도해 주세요");
				score--;
				break;
			case 'x':
				gotoxy(12, 15);
				printf("= X");
				gotoxy(12, 16);
				printf("맞았습니다!");
				gotoxy(12, 18);
				printf("n을 눌러 다음 화면으로 넘어가 주세요");
				break;
				case 'n':
					lastScreen();
					break;
				break;

			case 'e':
				//씬 이동
				system("cls");
				gotoxy(25, 15);
				printf("\"퀴즈 게임이 종료 되었습니다\"\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
			printf("============= ★ ★ ★ ★ ★ =============");
			gotoxy(27, 12);
			printf(" 모두 맞추셨네요 명예 한세인");
			gotoxy(20, 14);
			printf("============= ★ ★ ★ ★ ★ =============");
			break;
		case 4:
			gotoxy(20, 10);
			printf("============= ★ ★ ★ ★ ☆ =============");
			gotoxy(27, 12);
			printf(" 한 문제 틀리셨네요 아까워요");
			gotoxy(20, 14);
			printf("============= ★ ★ ★ ★ ☆ =============");
			break;
		case 3:
			gotoxy(20, 10);
			printf("============= ★ ★ ★ ☆ ☆ =============");
			gotoxy(27, 12);
			printf(" 사실 교훈 이거 만들면서 알았어요");
			gotoxy(20, 14);
			printf("============= ★ ★ ★ ☆ ☆ =============");
			break;
		case 2:
			gotoxy(20, 10);
			printf("============= ★ ★ ☆ ☆ ☆ =============");
			gotoxy(27, 12);
			printf(" 음 다시 한번 시도해 보세요!");
			gotoxy(20, 14);
			printf("============= ★ ★ ☆ ☆ ☆ =============");
			break;
		case 1:
			gotoxy(20, 10);
			printf("============= ★ ☆ ☆ ☆ ☆ =============");
			gotoxy(27, 12);
			printf(" 하나 맞추셨네요 불명예 한세인");
			gotoxy(20, 14);
			printf("============= ★ ☆ ☆ ☆ ☆ =============");
			break;
		case 0:
			gotoxy(20, 10);
			printf("============= ☆ ☆ ☆ ☆ ☆ =============");
			gotoxy(27, 12);
			printf(" 외부인이시네요 외부인 출입 금지 ");
			gotoxy(20, 14);
			printf("============= ☆ ☆ ☆ ☆ ☆ =============");
			break;
		}
	}
