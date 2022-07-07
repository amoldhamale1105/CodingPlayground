#include <iostream>

class Entity
{
	public:
		Entity()
		{
			std::cout<<"entity created!"<<std::endl;
		}
		~Entity()
		{
			std::cout<<"entity destroyed"<<std::endl;
		}
		virtual void print()
		{
			std::cout<<"entity says hello!"<<std::endl;
		}
};

class Player : public Entity
{
	public:
		Player()
		{
			std::cout<<"player created!"<<std::endl;
		}
		~Player()
		{
			std::cout<<"player destroyed"<<std::endl;
		}
		void print() override
		{
			std::cout<<"player says hello!"<<std::endl;
		}
};

int main(int argc, char** argv)
{
	Player *p = new Player();
	Entity *e = p;
	e->print();
	delete e;	
	return 0;
}
