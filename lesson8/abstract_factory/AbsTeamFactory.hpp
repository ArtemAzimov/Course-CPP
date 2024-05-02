#ifndef ABS_TEAM_FACTORY_HPP
# define ABS_TEAM_FACTORY_HPP

# include "AbsFighter.hpp"

class AbsTeamFactory
{
public:
	virtual AbsFighter*	getInfighter() = 0;      // * Чистые виртуальные методы
	virtual AbsFighter*	getDistantFighter() = 0; // * которые можно вызвать у конкретных наследников
	virtual AbsFighter*	getMage() = 0;           // * Внимание, через указатель на родителя, ты можешь
	virtual AbsFighter*	getHealer() = 0;		 // * вызывать только публичные методы объявленные у родителя
};

#endif // ABS_TEAM_FACTORY_HPP