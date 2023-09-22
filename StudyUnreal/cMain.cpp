#include <stdio.h>
#include <Windows.h>

struct Player
{
	int x; int y;
};

int main() {

	Player* player = (Player*)malloc(sizeof(Player));
	player->x = 0;
	player->y = 10;
	int num[] = { 1, 2, 3, 4, 5 };
	printf("%d", num[1]);

	return 0;
}