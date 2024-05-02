#pragma once

# include <iostream>

#include "..\unit_classes\Abs_Melee.hpp"
#include "..\unit_classes\Abs_Range.hpp"
#include "..\unit_classes\Abs_Mage.hpp"
#include "..\unit_classes\Abs_Healer.hpp"
#include "..\AbsTeamFactory.hpp"

class Human_Melee : public Abs_Melee
{
public:
	void battleCry() const override { std::cout << "Human Swordsman: Die!" << std::endl; }
};

class Human_Range : public Abs_Range
{
public:
	void battleCry() const override { std::cout << "Human Archer: Take this!" << std::endl; }
};

class Human_Mage : public Abs_Mage
{
	void battleCry() const override { std::cout << "Human Mage: Yee gee yest!" << std::endl; }
};

class Human_Healer : public Abs_Healer
{
	void battleCry() const override { std::cout << "Human Healer: Ha! Ha! Ha! Ha! Stayin' alive!" << std::endl; }
};

class HumanFactory : public AbsTeamFactory
{
public:
	Human_Melee* getMelee() override { return (new Human_Melee); } 
	Human_Range* getRange() override { return (new Human_Range); } 
	Human_Mage* getMage() override { return (new Human_Mage); } 
	Human_Healer* getHealer() override { return (new Human_Healer); } 
};