#pragma once

#include <iostream>

#include "..\unit_classes\Abs_Melee.hpp"
#include "..\unit_classes\Abs_Range.hpp"
#include "..\unit_classes\Abs_Mage.hpp"
#include "..\unit_classes\Abs_Healer.hpp"
#include "..\AbsTeamFactory.hpp"

class Elf_Melee : public Abs_Melee
{
public:
	void battleCry() const override { std::cout << "Elf Melee: Confess and your death would be fast!" << std::endl; }
};

class Elf_Range : public Abs_Range
{
public:
	void battleCry() const override { std::cout << "Elf Archer: Vengeance from the sky!" << std::endl; }
};

class Elf_Mage : public Abs_Mage
{
public:
	void battleCry() const override { std::cout << "Elf Wizard: I'll devour your soul!" << std::endl; }
};

class Elf_Healer : public Abs_Healer
{
public:
	void battleCry() const override { std::cout << "Elf Healer: Bless you!" << std::endl; }
};

// ********** FACTORY ****************

class ElfTeamFactory : public AbsTeamFactory
{
public:
	Elf_Melee*	getMelee() override { return new Elf_Melee; }
	Elf_Range*	getRange() override { return new Elf_Range; }
	Elf_Mage*	getMage() override { return new Elf_Mage; }
	Elf_Healer*	getHealer() override { return new Elf_Healer; }
};