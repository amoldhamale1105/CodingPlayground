#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;



int global_counter = 0;
std::mutex counter_mutex;

void five_thread_fn(){
    for(int i = 0; i<5; i++){
        counter_mutex.lock();
        global_counter++;
        counter_mutex.unlock();
        std::cout << "Updated from five_thread"  << endl;
        std::cout<< "\nGlobal counter val (from 5): " << global_counter << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    //When this thread finishes we wait for it to join
}

void ten_thread_fn(){
    for(int i = 0; i<10; i++){
        counter_mutex.lock();
        global_counter++;
        counter_mutex.unlock();
        std::cout << "Updated from ten_thread"  << endl;
        std::cout<< "\nGlobal counter val (from 10): " << global_counter << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    //When this thread finishes we wait for it to join
}
int main(int argc, char *argv[]) {
    std::cout << "starting thread ten..." << std::endl;
    std::thread ten_thread(ten_thread_fn);

    std::cout << "starting thread five..." << endl;
    std::thread five_thread(five_thread_fn);


    ten_thread.join();
    std::cout << "Ten Thread is done." << std::endl;
    five_thread.join();
    std::cout << "Five Thread is done." << std::endl;
}
