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

	printf("%d, %d", player->x, player->y);

	return 0;
}