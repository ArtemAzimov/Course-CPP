#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <string>

// ***** SINGLETON *****

class Logger									// ? Это другой паттерн проектирования, который называется Синглтон
{
private:									     // ? Мы объявляем конструкторы в private, чтобы где-то снаружи нельзя было создать объект этого класса обычным способом
	Logger() = default;							 // ? например, мы теперь в функции main не можем сделать так: Logger logger; или так: Logger* p_logger = new Logger();
	Logger(const Logger&) = delete;				 // ? по сути мы запретили создавать объект любой другой сущности, кроме самого класса Logger
	// Logger& operator = (const Logger&) = delete; // ? Тут мы также запрещаем его копировать

public:
	static Logger& self() {						 // ? Это тот самый метод, с помощью которого можно
		static Logger instance;					 // ? создать объект этого класса Logger (при первом вызове в программе)
		return (instance);						 // ? и обратиться к нему
	}

	void warning(const std::string& message);
	void error(const std::string& message);
};

/*
Так как instance является статическим объектом (строка 18), он существует с тех пор как его создали (при первом вызове метода self) 
и до тех пор, пока программа запущена (как глобальная переменная, но отличие в том, что instance можно получить только через метод self
и только через обращение к классу Logger)

Получается, чтобы получить объект класса Logger, нам нужно вызвать метод self. Это делается с помощью оператора области видимости (::)
получаем instance: Logger::self()
Можем сразу обратиться к его методам: Logger::self().warning("Something went wrong!")

При последующем вызове Logger::self() строка 18 будет пропускаться, так как статический объект instance уже создан
*/

#endif // LOGGER_HPP