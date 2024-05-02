#pragma once

#include <iostream>

#include "..\unit_classes\Abs_Melee.hpp"
#include "..\unit_classes\Abs_Range.hpp"
#include "..\unit_classes\Abs_Mage.hpp"
#include "..\unit_classes\Abs_Healer.hpp"
#include "..\AbsTeamFactory.hpp"

class Ork_Melee : public Abs_Melee
{
public:
	void battleCry() const override { std::cout << "Ork Fighter: Seek and destroy!" << std::endl; }
};

class Ork_Range : public Abs_Range
{
public:
	void battleCry() const override { std::cout << "Ork Archer: Ohhhohohohoh!" << std::endl; }
};

class Ork_Mage : public Abs_Mage
{
public:
	void battleCry() const override { std::cout << "Ork Mage: Avadakedavra!" << std::endl; }
};

class Ork_Healer : public Abs_Healer
{
public:
	void battleCry() const override { std::cout << "Ork Healer: You'le all right!" << std::endl; }
};

// ********** FACTORY ****************

class OrkTeamFactory : public AbsTeamFactory
{
public:
	Ork_Melee*	getMelee() override { return new Ork_Melee; }
	Ork_Range*	getRange() override { return new Ork_Range; }
	Ork_Mage*	getMage() override { return new Ork_Mage; }
	Ork_Healer*	getHealer() override { return new Ork_Healer; }
};