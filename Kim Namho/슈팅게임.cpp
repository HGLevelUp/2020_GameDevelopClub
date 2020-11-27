#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

struct _player {
	int x, y;
	int health;
};

struct _enemy {
	int x, y;
	int time;
	int speed;
};

struct _bullet {
	int shooting, x, y;
};

enum _enemystate {
	kill, live
};

enum _gamestate {
	init, run, die
};

_player player;
_enemy enemy;
_bullet bullet;

_enemystate enemystate;
_gamestate gamestate;

time_t curtime, oldtime;

void Init();
void Update();
void Render();

void GetKey();
void gotoXY(int x, int y);
void PlayerRender(int x, int y);
void PlayerState();
void Enemy();
void BulletRender();
void EnemyRender();
void Hit();
void ScorePrint();
void Difficulty();
void PlayerHealth();
void HealthPrint();

int score;

int main() {

	Init();

	while (1) {

			Update();

			Render();
			
	}

}

void Init() {
	curtime = clock();
	player.x = 15;
	player.y = 20;
	player.health = 3;
	bullet.shooting = 0;
	enemystate = kill;
	enemy.speed = 1000;
	gamestate = init;
}

void Update() {
	curtime = clock();

	GetKey();

	Enemy();

	Hit();

	Difficulty();

	PlayerHealth();
}

void Render() {
	gotoXY(0, 0);

	switch (gamestate)
	{
	case init:	printf("게임 시작 혹은 다시하기 q\n총알 발사 k");
		break;
	case run:
		PlayerRender(player.x, player.y);
		BulletRender();
		EnemyRender();
		ScorePrint();
		PlayerHealth();
		HealthPrint();
		break;
	case die: printf("YOU DIED\n 다시하려면 q를 눌러주세요");
		break;
	}



	system("cls");
}


void GetKey() {
	if (_kbhit()) {
		int nKey = _getch();

		switch (nKey) {
		case 'a':if (player.x >= 1)
			player.x--;
			break;
		case 'd':if (player.x <= 80)
			player.x++;
			break;
		case 'k': bullet.shooting = 1;
			break;
		case 'q': gamestate = run;
			break;
		}
		

	}
}



void PlayerHealth() {
	if (player.health == 0) {
		gamestate = die;
	}
}

void BulletRender() {
	if (bullet.shooting == 1) {
		if (curtime - oldtime >= 88) {
			gotoXY(bullet.x, bullet.y);

			printf("↑");

			bullet.y--;

			if (bullet.y < 0)
				bullet.shooting = 0;
		}
	}
	else {
		bullet.x = player.x + 2;
		bullet.y = player.y - 1;
	}
}

void Enemy() {
	switch (enemystate)
	{
	case kill:
		srand(time(NULL));
		enemy.y = 0;
		enemy.x = (rand() % 25);
		enemystate = live;
		break;
	case live: 
		if (curtime - enemy.time >= enemy.speed) {
			enemy.y++;

			enemy.time = curtime;
		}
		if (enemy.y > 20) {
			enemystate = kill;
			player.health--;
		}
		break;
	}
}

void EnemyRender() {
	gotoXY(enemy.x, enemy.y);
	printf("◀▣▶");
}

void gotoXY(int x, int y) {
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void PlayerRender(int x, int y) {
	gotoXY(x, y);
	printf("◁◎▷");
}

void Hit() {
	if (enemy.y == bullet.y) {
		if (enemy.x - 2 < bullet.x && enemy.x + 6 > bullet.x) {
			enemystate = kill;
			
			bullet.shooting = 0;

			score++;
		}
	}
}

void Difficulty() {
	if (enemystate == kill) {
		enemy.speed -= 70;
	}
}

void ScorePrint() {
	gotoXY(70, 19);
	printf("점수 : %d", score);
}

void HealthPrint() {
	gotoXY(70, 20);
	printf("생명 : %d", player.health);
}