#pragma once

#include <iostream>

#include "AbsFighter.hpp"
#include "AbsTeamFactory.hpp"

class OrkFighter : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "OrkFighter: Destroy! Seal! Kill!" << std::endl; }
};

class OrkArcher : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "OrkArcher: Ohhhohohohoh!" << std::endl; }
};

class OrkMage : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "OrkMage: Avadakedavra!" << std::endl; }
};

class OrkHealer : public AbsFighter
{
public:
	void battleCry() const override { std::cout << "OrkHealer: You'le all right!" << std::endl; }
};

// ********** FACTORY ****************

class OrkTeamFactory : public AbsTeamFactory
{
public:
	AbsFighter*	getInfighter() { return new OrkFighter; }
	AbsFighter*	getDistantFighter() { return new OrkArcher; }
	AbsFighter*	getMage() { return new OrkMage; }
	AbsFighter*	getHealer() { return new OrkHealer; }
};