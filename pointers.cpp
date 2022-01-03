#include <iostream>

int main()
{
    const char *str;
    const char *str2 = "ssup";
    const char *str3 = "ssup again";
    //char* temp = const_cast<char*>(str2);
    char* temp = (char*)str2;
    //*temp = 'w';
    std::cout<<temp<<std::endl;
    str = str3;
    std::cout<<str<<std::endl;
    return 0;
}
