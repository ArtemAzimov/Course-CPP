#ifndef COMMAND_CREATOR_HPP
# define COMMAND_CREATOR_HPP

# include <string>
# include <algorithm>
# include "HumanFactory.hpp"
# include "UndeadFactory.hpp"
# include "OrkFactory.hpp"
# include "Team.hpp"
# include "Logger.hpp"

class TeamCreator
{
public:
	TeamCreator() = default;
	~TeamCreator() = default;

	AbsTeamFactory* createFactory(const std::string& team_race) const // * Возвращает соответствующую агрументу конкретную фабрику
	{
		std::string team_uppercase = team_race;                                                 // * Здесь мы будем хранить team_race в ВЕРХНЕМ РЕГИСТРЕ

		std::transform(team_race.begin(), team_race.end(), team_uppercase.begin(), ::toupper);  // * Перевод в ВЕРХНИЙ РЕГИСТР строки team_race и сохранение ее в team_uppercase

		if (team_uppercase == "HUMAN")      // * Если выбрана команда human
			return ( new HumanFactory{} );  // * Выделяем память под объект класса HumanFactory и возвращаем указатель на него
		if (team_uppercase == "UNDEAD")     // * Аналогично
			return ( new UndeadFactory{} ); // *
		if (team_uppercase == "ORK")
			return ( new OrkTeamFactory{} );

		return (nullptr);                   // * Если аргумент не совпал ни с одним известным названием команды, возвращаем nullptr 
	}

	Team* createTeam(AbsTeamFactory* factory) const		// * Получаем указатель на фабрику и с ее помощью создаем команду Team
	{
		Team* team = new Team{};                              // * Выделяем память под структуру Team
		team->infighter = factory->getInfighter();            // * Используем фабрику и инициализируем все поля структуры Team
		team->distant_fighter = factory->getDistantFighter(); // *
		team->mage = factory->getMage();                      // *
		team->healer = factory->getHealer();                  // *
		return (team);                                        // * Возвращаем созданную команду
	}
};

#endif // COMMAND_CREATOR_HPP