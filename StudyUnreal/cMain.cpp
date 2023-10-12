#include <iostream>
#include "Player.h"

int main() {
	Player id1;
	
	id1.money = 5000;

	std::cout << id1.GetUserID() << "´ÔÀÇ µ· : " << id1.money << std::endl;

	return 0;
}