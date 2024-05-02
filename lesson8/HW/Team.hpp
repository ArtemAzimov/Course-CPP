#pragma once

#include "unit_classes\Abs_Melee.hpp"
#include "unit_classes\Abs_Range.hpp"
#include "unit_classes\Abs_Mage.hpp"
#include "unit_classes\Abs_Healer.hpp"

struct Team
{
	Abs_Melee* melee;
	Abs_Range* range;
	Abs_Mage* mage;
	Abs_Healer* healer;
};