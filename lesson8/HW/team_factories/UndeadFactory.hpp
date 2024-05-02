#pragma once

#include <iostream>

#include "..\unit_classes\Abs_Melee.hpp"
#include "..\unit_classes\Abs_Range.hpp"
#include "..\unit_classes\Abs_Mage.hpp"
#include "..\unit_classes\Abs_Healer.hpp"
#include "..\AbsTeamFactory.hpp"

class Undead_Melee : public Abs_Melee
{
public:
	void battleCry() const override { std::cout << "Undead Ghoul: I'll eat you!" << std::endl; }
};

class Undead_Range : public Abs_Range
{
public:
	void battleCry() const override { std::cout << "Undead Stone-thrower: Headshot!" << std::endl; }
};

class Undead_Mage : public Abs_Mage
{
	void battleCry() const override { std::cout << "Undead Mage: Blood magic!" << std::endl; }
};

class Undead_Healer : public Abs_Healer
{
	void battleCry() const override { std::cout << "Undead Healer: Ha! Ha! Ha! Ha! Stayin'... dead?" << std::endl; }
};

// ******** FACTORY CLASS **********

class UndeadFactory : public AbsTeamFactory // * Конкретная фабрика команды мертвецов
{
public:
	Undead_Melee* getMelee() override { return (new Undead_Melee);}
	Undead_Range* getRange() override { return (new Undead_Range);}
	Undead_Mage* getMage() override { return (new Undead_Mage);}
	Undead_Healer* getHealer() override { return (new Undead_Healer);}
};