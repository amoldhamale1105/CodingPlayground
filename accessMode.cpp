#include <iostream>

class Base
{
	public:
		void greet(){std::cout<<"hello from base!"<<std::endl;}
	protected:
		void proGreet() {std::cout<<"protected hello from base"<<std::endl;}
	private:
		void priGreet() {std::cout<<"sshhhh.. private hello from base!"<<std::endl;}
};

class Derived: protected Base 
{
	public:
		using Base::proGreet;
};

int main()
{
	Derived d;
	d.proGreet();
	return 0;
}
