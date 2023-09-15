#include <stdio.h>
#include <Windows.h>

void SetPosition(int x, int y);
void SetColor(int color);
void HideCursor();

#pragma region Enum
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
#pragma endregion

typedef struct Obj
{
	int x;
	int y;
	Color color;
	const char* shape;
}Player;

Player* player = nullptr;

void Initialize();
void Progress();
void Render();
void Release();


bool jump = false;
const float G = 9.81f;
float time = 0.f;

int main() {
	HideCursor();
	Initialize();

	while (true)
	{
		system("cls");

		Progress();
		Render();

		Sleep(50);
	}

	Release();

	return 0;
}

#pragma region GAME
void Initialize() {
	player = (Player*)malloc(sizeof(Player));
	player->x = 10;
	player->y = 10;
	player->color = LIGHTMAGENTA;
	player->shape = "옷";
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
		jump = true;
	}

	if (jump)
	{
		time += 0.05f;
		player->y = 0.5f * G * (time * time);
	}
}
void Render() {
	SetPosition(player->x, player->y);
	SetColor(player->color);
	printf(player->shape);
}
void Release() {
	if (player != nullptr)
	{
		free(player);
		player = nullptr;
	}
}
#pragma endregion

#pragma region WIN_API

//깜박깜박 거리는 커서 없애주는 함수
void HideCursor() {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

//X,Y값 받아서 커서의 좌표를 이동시켜주는 함수
void SetPosition(int x, int y) {
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//color값 받아서 색깔 바꿔주는 아이
void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#pragma endregion