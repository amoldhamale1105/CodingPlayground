#include <cstdlib>
#include <iostream>
#include <ctime>
 
int main() 
{
    std::srand(1);   
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
     
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }

    std::srand(2);   
    random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
     
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }

    std::srand(1);   
    random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
     
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }

    std::srand(2);   
    random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
     
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }
}