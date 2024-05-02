#ifndef ABS_FIGHTER_HPP
# define ABS_FIGHTER_HPP

class AbsFighter                         // * Абстрактный класс, который наследуется классами HumanWarrior, UndeadMage и т.д.
{
	// HP
	// Magicka
	// ...
public:
	virtual void battleCry() const = 0;
};

#endif // ABS_FIGHTER_HPP