#include <iostream>

struct Pet
{
	const char* name;

	Pet(const char* _name)  //생성되었을때 호출되는 함수
	{
		name = _name;
		std::cout << name << "생성" << std::endl;
	}

	~Pet() //소멸되었을때 호출되는 함수
	{
		std::cout << name << "소멸" << std::endl;
	}
};

struct Player
{
	const char* name;
	Pet* pet;

	Player(const char* _name)  //생성되었을때 호출되는 함수
	{
		name = _name;
		pet = nullptr;
		std::cout << name << "생성" << std::endl;
	}

	~Player() //소멸되었을때 호출되는 함수
	{
		if (pet != nullptr)
		{
			delete pet;
			pet = nullptr;
		}
		std::cout << name << "소멸" << std::endl;
	}
};


int main() {
	Player* player = new Player("glgl");
	Pet* pet = new Pet("댕댕이");

	player->pet = pet;
	player->pet->name = "멍멍이";

	std::cout << pet->name << std::endl;

	delete player;
	player = nullptr;


	return 0;
}