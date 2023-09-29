#include <iostream>
#include <vector>

static std::string convert_to_digital_time(int minutes)
{
    std::string time;
    char digiMinutes[3];
    
    time.append(std::to_string(minutes/60)+":");
    sprintf(digiMinutes, "%02d", minutes%60);
    time.append(digiMinutes);
    
    return time;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter time in minutes as program arg"<<std::endl;
        return EXIT_FAILURE;
    }
    constexpr int TOTAL_MIN_DAY = 24*60;
    try
    {
        std::cout<<"Digital time: "<<convert_to_digital_time(std::stoi(argv[1])%TOTAL_MIN_DAY)<<std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << ": Invalid input argument" << '\n';
    }
    
    return 0;
}