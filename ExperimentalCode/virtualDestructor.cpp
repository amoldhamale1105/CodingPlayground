#include <iostream>

class Base
{
    public:
    Base() {std::cout<<"Invoked base ctor"<<std::endl;}
    virtual ~Base() {std::cout<<"Invoked base dtor"<<std::endl;}

    virtual void greet() {std::cout<<"Base says hello!"<<std::endl;}
};

class Derived1 : public Base
{
    private:
    int *p;
    public:
    Derived1() 
    {
        p = new int[10];
        std::cout<<"Invoked der1 ctor"<<std::endl;
    }
    ~Derived1() 
    {
        delete [] p;
        std::cout<<"Invoked der1 dtor"<<std::endl;
    }

    void greet() override {std::cout<<"Der1 says hello!"<<std::endl;}
};

class Derived2 : public Base
{
    public:
    Derived2() {std::cout<<"Invoked der2 ctor"<<std::endl;}
    ~Derived2() {std::cout<<"Invoked der2 dtor"<<std::endl;}

    void greet() override {std::cout<<"Der2 says hello!"<<std::endl;}
};

int main()
{
    Base* instance = new Derived1;
    instance->greet();
    Derived2* der2 = new Derived2;
    der2->greet();

    delete instance;
    delete der2;

    return 0;
}