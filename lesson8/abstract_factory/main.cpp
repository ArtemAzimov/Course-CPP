#include <iostream>
#include <string>
#include <initializer_list>

#include "TeamCreator.hpp"
#include "AbsTeamFactory.hpp"
#include "Team.hpp"
#include "Logger.hpp"

using std::cout;
using std::endl;
using std::string;

class NewClass
{
	int *array;
	int size;

public:
	NewClass(std::initializer_list<int> list)
	{
		size = list.size();
		array = new int[ size ];

		int* p = array;
		for (auto nbr : list)
		{
			*p = nbr;
			p++;
		}
	}

	void showArray()
	{
		int* p = array;

		for (int i = 0; i < size; i++)
			cout << *p++ << endl;
	}
};

int main()
{
	// NewClass arr = { 1, 2, 3, 4, 5 };
	// arr.showArray();
	// std::exit(0);
	// ? Есть N команд, у каждой команды есть по 4 бойца
	// ? Боец ближнего боя, боец дальнего, магический и хил
	// ? У каждого бойца есть свой боевой клич

	cout << "=CHOOSE-YOUR-TEAM=" << endl;
	cout << "ашуошаоуа" << endl;
	cout << ">: ";

	string team_race;					// * В team_race храним вводимую пользователем строку
	std::getline(std::cin, team_race);  // * std::cin - То, откуда мы берем входные данные (в этом случае, из потока ввда терминала)
										// * team_race - Передается в функцию по ссылке. Внутри ей присваивается строка полученная из первого аргумента (std::cin)

	TeamCreator creator;										// * TeamCreator - вспомогательный класс, которому делегируется отвественность за создание команды
	AbsTeamFactory* factory = creator.createFactory(team_race); // * createFactory - принимает название нужной расы (human/undead or else) и возвращает соответствующий объект фабрики (factory)

	if (factory == nullptr)							// * В случае если createFactory вернул nullptr,
		Logger::self().error("Unknown team name");  // * Выводится ошибка и программа закрывается с кодом ошибки 1
													// * Это реализованно внутри класса-синглтона Logger (синглтон - это еще один паттерн проектирования, также относящийся к порождающим). Приступай к нему в последнюю очередь, когда разберешься с фабрикой

	Team* team = creator.createTeam(factory);	// * createTeam - принимает аргументом указатель на абстрактную фабрику (AbsTeamFactory*), возвращает объект класса Team с заполненными полями бойцов
	team->infighter->battleCry();				// * Вывод боевого клича
	team->distant_fighter->battleCry();			// * уникального для
	team->mage->battleCry();					// * каждого
	team->healer->battleCry();					// * персонажа

	return (0);
}