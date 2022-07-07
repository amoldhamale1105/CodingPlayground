#include <iostream>

class A{
public:
	void speak(){
		std::cout<<"base speaking"<<std::endl;
	}
};

class B: virtual public A{
	public:
};

class C: virtual public A{
	public:
};

class D: public B, public C{
	
};

int main()
{
	B obj1; C obj2; 
	D obj;
	obj1.speak();
	obj2.speak();
	obj.speak();
	return 0;
}
