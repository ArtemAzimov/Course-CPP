#pragma once

#include "unit_classes\Abs_Melee.hpp"
#include "unit_classes\Abs_Range.hpp"
#include "unit_classes\Abs_Mage.hpp"
#include "unit_classes\Abs_Healer.hpp"

class AbsTeamFactory
{
public:
	virtual Abs_Melee*	getMelee() = 0;
	virtual Abs_Range*	getRange() = 0;
	virtual Abs_Mage*	getMage() = 0;
	virtual Abs_Healer*	getHealer() = 0;
};