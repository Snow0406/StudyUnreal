#include <stdio.h>
#include <Windows.h>

#pragma region DoubleBuffer
#define BufferWidth 80
#define BufferHeight 40

HANDLE hBuffer[2];
int screenIndex;

void InitBuffer();
void FlipBuffer();
void ClearBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void ReleaseBuffer();
#pragma endregion

enum Dir
{
	UP,
	DOWN,
};

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,

};

#define BulletCount 20
#define EnemyCount 10

struct Bullet
{
	bool act;
	int x;
	int y;
	Color color;
	const char* shape;
};

typedef struct Obj
{
	bool act;
	int aniIndex;
	Dir dir;
	int x;
	int y;
	Color color;
	const char* shape[10][3];
}Player, Enemy;

Player* player = nullptr;
Enemy* enemies[EnemyCount] = {};
Bullet* bullets[BulletCount] = {};

int spawnTime = 0;

void Initialize();
void Progress();
void Render();
void Release();

int main() {
	InitBuffer();
	Initialize();

	while (true)
	{
		//Todo
		Progress();
		Render();

		FlipBuffer();
		ClearBuffer();

		Sleep(30);
	}

	Release();
	ReleaseBuffer();

	return 0;
}

void Initialize() {
	player = (Player*)malloc(sizeof(Player));
	player->x = 10;
	player->y = 10;
	player->aniIndex = 0;
	player->color = WHITE;
	player->shape[0][0] = "   -----|-----";
	player->shape[0][1] = "*>=====[_]L)";
	player->shape[0][2] = "      -'-`-";
	player->shape[1][0] = "    ----|----";
	player->shape[1][1] = "*>=====[_]L)";
	player->shape[1][2] = "      -'-`-";
	player->shape[2][0] = "     ---|---";
	player->shape[2][1] = "*>=====[_]L)";
	player->shape[2][2] = "      -'-`-";
	player->shape[3][0] = "      --|--";
	player->shape[3][1] = "*>=====[_]L)";
	player->shape[3][2] = "      -'-`-";
	player->shape[4][0] = "       -|-";
	player->shape[4][1] = "*>=====[_]L)";
	player->shape[4][2] = "      -'-`-";
	player->shape[5][0] = "        -";
	player->shape[5][1] = "*>=====[_]L)";
	player->shape[5][2] = "      -'-`-";
	player->shape[6][0] = "       -|-";
	player->shape[6][1] = "*>=====[_]L)";
	player->shape[6][2] = "      -'-`-";
	player->shape[7][0] = "      --|--";
	player->shape[7][1] = "*>=====[_]L)";
	player->shape[7][2] = "      -'-`-";
	player->shape[8][0] = "     ---|---";
	player->shape[8][1] = "*>=====[_]L)";
	player->shape[8][2] = "      -'-`-";
	player->shape[9][0] = "    ----|----";
	player->shape[9][1] = "*>=====[_]L)";
	player->shape[9][2] = "      -'-`-";


	for (int i = 0; i < BulletCount; i++)
	{
		bullets[i] = (Bullet*)malloc(sizeof(Bullet));
		bullets[i]->act = false;
		bullets[i]->x = i;
		bullets[i]->y = 0;
		bullets[i]->color = LIGHTCYAN;
		bullets[i]->shape = "¡Ü";
	}
	for (int i = 0; i < EnemyCount; i++)
	{
		enemies[i] = (Enemy*)malloc(sizeof(Enemy));
		enemies[i]->act = false;
		enemies[i]->x = 0;
		enemies[i]->y = 0;
		enemies[i]->color = LIGHTRED;
		enemies[i]->shape[0][0] = "-----|-----";
		enemies[i]->shape[0][1] = "  (J[_]=====<*";
		enemies[i]->shape[0][2] = "   -'-`-";
	}
}

void Progress() {
	if (GetAsyncKeyState(VK_LEFT))
	{
		player->x--;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		player->x++;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		player->y--;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		player->y++;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		for (int i = 0; i < BulletCount; i++)
		{
			if (!bullets[i]->act)
			{
				bullets[i]->x = player->x + 6;
				bullets[i]->y = player->y + 1;
				bullets[i]->act = true;
				break;
			}
		}
	}

	for (int i = 0; i < BulletCount; i++)
	{
		if (bullets[i]->act)
		{
			bullets[i]->x++;

			if (bullets[i]->x > 38)
			{
				bullets[i]->act = false;
				bullets[i]->x = i;
				bullets[i]->y = 0;
			}
		}
	}

	spawnTime++;
	if (spawnTime > 30)
	{
		spawnTime = 0;
		for (int i = 0; i < EnemyCount; i++)
		{
			if (enemies[i]->act == false)
			{
				enemies[i]->act = true;
				enemies[i]->x = 30;
				enemies[i]->y = rand() % 37;
				enemies[i]->dir = (Dir)(rand() % 2);
				break;
			}
		}
	}

	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemies[i]->act)
		{
			enemies[i]->x--;
			switch (enemies[i]->dir)
			{
			case UP:
				enemies[i]->y--;
				break;
			case DOWN:
				enemies[i]->y++;
				break;
			default:
				break;
			}
			if (enemies[i]->x <= 0 || enemies[i]->y <= 0 || enemies[i]->y >= 37)
			{
				enemies[i]->act = false;
			}

		}
	}


}
void Render() {
	player->aniIndex++;
	if (player->aniIndex >= 10)
	{
		player->aniIndex = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		WriteBuffer(player->x, player->y + i, player->shape[player->aniIndex][i], player->color);
	}

	for (int i = 0; i < BulletCount; i++)
	{
		WriteBuffer(bullets[i]->x, bullets[i]->y, bullets[i]->shape, bullets[i]->color);
	}

	for (int i = 0; i < EnemyCount; i++)
	{
		if (enemies[i]->act)
		{
			for (int j = 0; j < 3; j++)
			{
				WriteBuffer(enemies[i]->x, enemies[i]->y + j, enemies[i]->shape[0][j], enemies[i]->color);
			}
		}

	}
}
void Release() {
	if (player != nullptr)
	{
		free(player);
		player = nullptr;
	}
}

#pragma region DoubleBuffer
void InitBuffer() {
	screenIndex = 0;

	COORD size = { BufferWidth, BufferHeight };

	SMALL_RECT rect = { 0, 0, BufferWidth, BufferHeight };

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;

	SetConsoleCursorInfo(hBuffer[0], &info);
	SetConsoleCursorInfo(hBuffer[1], &info);

}

void FlipBuffer() {
	SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);
	screenIndex = !screenIndex;
}

void ClearBuffer() {
	COORD pos = { 0,0 };
	DWORD dw;

	FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

void WriteBuffer(int x, int y, const char* shape, int color) {
	COORD pos = { x * 2, y };

	SetConsoleCursorPosition(hBuffer[screenIndex], pos);
	SetConsoleTextAttribute(hBuffer[screenIndex], color);

	DWORD dw;
	WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);
}

void ReleaseBuffer() {
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}

#pragma endregion