# include <string>
# include <algorithm>
# include "team_factories/HumanFactory.hpp"
# include "team_factories/UndeadFactory.hpp"
# include "team_factories/OrkFactory.hpp"
# include "team_factories/ElfFactory.hpp"
# include "Team.hpp"
# include "Logger.hpp"

class TeamCreator
{
public:
	TeamCreator() = default;
	~TeamCreator() = default;

	AbsTeamFactory* createFactory(const std::string& team_race) const 
	{
		std::string team_uppercase = team_race;                                                 

		std::transform(team_race.begin(), team_race.end(), team_uppercase.begin(), ::toupper);  

		if (team_uppercase == "HUMANS")      
			return ( new HumanFactory{} );  
		if (team_uppercase == "UNDEAD")     
			return ( new UndeadFactory{} ); 
		if (team_uppercase == "ORKS")
			return ( new OrkTeamFactory{} );
		if (team_uppercase == "ELFS")
			return ( new ElfTeamFactory{} );

		return (nullptr);                   
	}

	Team* createTeam(AbsTeamFactory* factory) const		
	{
		Team* team = new Team{};                              
		team->melee = factory->getMelee();            
		team->range = factory->getRange(); 
		team->mage = factory->getMage();                      
		team->healer = factory->getHealer();                  
		return (team);                                        
	}
};