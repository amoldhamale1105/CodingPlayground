#include <cstdlib>
#include <iostream>
#include <ctime>
 
int main() 
{
    std::srand(1); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll 6-sided dice 20 times
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }

    std::srand(2); // use current time as seed for random generator
    random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll 6-sided dice 20 times
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }

    std::srand(1); // use current time as seed for random generator
    random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll 6-sided dice 20 times
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }

    std::srand(2); // use current time as seed for random generator
    random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll 6-sided dice 20 times
    for (int n=0; n != 5; ++n) {
        std::cout<<std::rand()<<std::endl;
    }
}