#include <iostream>
#include <functional>
#include <vector>

template<typename T = std::function<void()> >
class Observable {
public:
    using Observer = T;

    void addObserver(Observer observer) {
        observers.push_back(observer);
    }

    void notifyObservers(int value) {
        for (const auto& observer : observers) {
            observer(value);
        }
    }

private:
    std::vector<Observer> observers;
};

// Пример использования

class Subscriber {
public:
    void handleEvent() {
        std::cout << "Event handled by Subscriber" << std::endl;
    }
};

int main() {
    Observable<std::function<void(int)>> observable;
    Subscriber subscriber;

    // observable.addObserver(std::bind(&Subscriber::handleEvent, &subscriber));
    observable.addObserver([](int event){
        std::cout << "Event handled by Lamda" << std::endl;
    });

    // Event system
    observable.notifyObservers(0); // Уведомление подписчиков

    return 0;
}
