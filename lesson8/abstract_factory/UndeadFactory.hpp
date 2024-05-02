#ifndef UNDEAD_FACTORY_HPP
# define UNDEAD_FACTORY_HPP

# include <iostream>

# include "AbsFighter.hpp"
# include "AbsTeamFactory.hpp"

class UndeadWarrior : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "Undead warrior: I'll eat you!" << std::endl; }
};

class UndeadStoneThrower : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "Undead stone thrower: Headshot!" << std::endl; }
};

class UndeadMage : public AbsFighter
{
	void battleCry() const override { std::cout << "Undead mage: Blood magic!" << std::endl; }
};

class UndeadHealer : public AbsFighter
{
	void battleCry() const override { std::cout << "Undead healer: Ha! Ha! Ha! Ha! Stayin'... dead?" << std::endl; }
};

// ******** FACTORY CLASS **********

class UndeadFactory : public AbsTeamFactory // * Конкретная фабрика команды мертвецов
{
public:
	UndeadWarrior*		getInfighter() override			{ return (new UndeadWarrior);      } // * Обрати внимание на оверрайды
	UndeadStoneThrower*	getDistantFighter() override	{ return (new UndeadStoneThrower); } // * Это все унаследованные методы,
	UndeadMage*			getMage() override				{ return (new UndeadMage);         } // * к которым мы обращаемся через класс-родитель
	UndeadHealer*		getHealer() override			{ return (new UndeadHealer);       } // * с помощью полиморфизма
};																							 // *

#endif // UNDEAD_FACTORY_HPP