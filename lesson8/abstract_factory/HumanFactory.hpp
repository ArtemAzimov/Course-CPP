#ifndef HUMAN_FACTORY_HPP
# define HUMAN_FACTORY_HPP

# include <iostream>

# include "AbsFighter.hpp"
# include "AbsTeamFactory.hpp"

class HumanWarrior : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "Human warrior: Die!" << std::endl; }
};

class HumanArcher : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "Human archer: Take this!" << std::endl; }
};

class HumanMage : public AbsFighter
{
	void battleCry() const override { std::cout << "Human mage: Yee gee yest!" << std::endl; }
};

class HumanHealer : public AbsFighter
{
	void battleCry() const override { std::cout << "Human healer: Ha! Ha! Ha! Ha! Stayin' alive!" << std::endl; }
};

// ******** FACTORY CLASS **********

class HumanFactory : public AbsTeamFactory
{
public:
	HumanWarrior*	getInfighter() override			{ return (new HumanWarrior); } // * Обрати внимание на оверрайды
	HumanArcher*	getDistantFighter() override	{ return (new HumanArcher);  } // * Это все унаследованные методы,
	HumanMage*		getMage() override				{ return (new HumanMage);    } // * к которым мы обращаемся через класс-родитель
	HumanHealer*	getHealer() override			{ return (new HumanHealer);  } // * с помощью полиморфизма
																				   // *
};

#endif // HUMAN_FACTORY_HPP