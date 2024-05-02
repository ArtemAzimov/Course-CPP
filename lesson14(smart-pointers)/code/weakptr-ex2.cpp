#include 
#include 


class Car {
public:
    Car() {
        std::cout << "Car created.\n";
    }
    void start() {
        std::cout << "Car started.\n";
    }
    ~Car() {
        std::cout << "Car destroyed.\n";
    }
};


int main() {
    std::unique_ptr carPtr = std::make_unique();
    std::shared_ptr sharedCarPtr = std::move(carPtr);


    std::weak_ptr<Car> weakCarPtr(sharedCarPtr);

    if(auto lockedCar = weakCarPtr.lock()){
        lockedCar->start();
    }

    return 0;
}