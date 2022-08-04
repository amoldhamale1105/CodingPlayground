#include <iostream>

class Sport
{
	protected:
		virtual void print(){ std::cout<<"I love sports!"<<std::endl; }
};

class Cricket : public Sport
{
	public:
		Cricket(){}
		Cricket(const Cricket&) = delete;
		Cricket& operator=(const Cricket&) = delete;
		void print() { std::cout<<"I love cricket"<<std::endl; }
};

class Badminton : public Sport
{
	public:
		void print() { std::cout<<"I love badminton"<<std::endl; }
};

int main(int argc, char** argv)
{
	Sport *s = new Cricket();
	Cricket *c2 = dynamic_cast<Cricket*>(s);
	c2->print();
	return 0;
}
