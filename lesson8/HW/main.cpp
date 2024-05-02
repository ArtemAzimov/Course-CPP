#include <iostream>
#include <string>

#include "TeamCreator.hpp"
#include "AbsTeamFactory.hpp"
#include "Team.hpp"
#include "Logger.hpp"

using std::cout, std::endl, std::string, std::cin, std::getline;

int main()
{
	cout << "=CHOOSE-YOUR-TEAM=" << endl;
	cout << "Humans | Undead | Orks | Elfs" << endl;
	cout << ">: ";

	string team_race;					
	getline(cin, team_race);  
										

	TeamCreator creator;										
	AbsTeamFactory* factory = creator.createFactory(team_race); 

	if (factory == nullptr)							
		Logger::self().error("Error: Unknown team name");  

	Team* team = creator.createTeam(factory);	
	team->melee->battleCry();				
	team->range->battleCry();			
	team->mage->battleCry();					
	team->healer->battleCry();					

	return (0);
}

//g++ *.cpp -I ..\hdrs\ -o out