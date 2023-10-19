#include <iostream>
#include <Windows.h>
#include "GameManager.h"

using namespace std;

GameManager* gameManager;

int main()
{
	while (true)
	{
		system("cls");

		gameManager->Progress();

		Sleep(100);
	}

	return 0;
}