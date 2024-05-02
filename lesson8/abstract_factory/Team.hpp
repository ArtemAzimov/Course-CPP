#ifndef TEAM_HPP
# define TEAM_HPP

# include "AbsFighter.hpp"

struct Team
{
	AbsFighter* infighter;
	AbsFighter* distant_fighter;
	AbsFighter* mage;
	AbsFighter* healer;
};

#endif // TEAM_HPP