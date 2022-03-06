#include <iostream>

class Exception : public std::runtime_error
{
    public:
    Exception() : runtime_error("Undefined operation. Division by zero attempted"){}
};

template <typename T>
static float divide(const T& dividend, const T& divisor)
{
    if(divisor == 0)
        throw Exception();
    return dividend/divisor;
}

int main(int argc, char* argv[])
{
    if(argc < 3){
        std::cerr<<"Invalid number of args to program. Enter exactly 2 args"<<std::endl;
        return 0;
    }

    float num1 = std::stof(argv[1]);
    float num2 = std::stof(argv[2]);
    try{
        float result = divide(num1, num2);
        std::cout<<"division result: "<<result<<std::endl;
    }
    catch(const Exception& e){
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }

    std::cout<<"printed just before returning from main"<<std::endl;
    return 0;
}
