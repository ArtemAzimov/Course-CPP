#include <thread>
#include <iostream>
#include <vector>
#include <functional>

void handle_thread(int id) {
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    static int commonId = 0;
    commonId++;
    std::cout << "Thread started " << id << " common id: " << commonId << '\n';
}

class Handler {
    public:
    void start(int id) {
        std::cout << "Thread started " << id << " this:" << this << std::endl;
    }
};

int main(){
    try {
        std::cout << "Main thread (count:)" << std::thread::hardware_concurrency() << std::endl;
        
        Handler handler;
        std::thread threadWithClass(std::bind(&Handler::start, &handler, 888));


        threadWithClass.join();

        std::thread thread(handle_thread, 777);
        std::string str = "Test thread started";
        std::thread threadLamda([=](){
            std::cout << "Lamda Started " << std::this_thread::get_id() << std::endl;
            std::cout << "Our str " << str << std::endl;
        });
        str = "Changed thread";

        if (thread.joinable())
        {
            std::cout << "Joinable thread" << std::endl;
            thread.join();
            // thread.detach();
        }
        threadLamda.join();
        
    }
    catch (std::exception &err) {
        std::cerr << "Exception " << err.what() << std::endl;
    }
    catch (...){
        std::cerr << "Exception" << std::endl;
    }
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 1150; i++)
    {
        threads.push_back(std::thread(handle_thread, i));
    }
    
    // thread.detach();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (auto& it: threads) {
        it.join();
    }
    return 0;
}