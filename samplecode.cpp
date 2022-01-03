#include<iostream>
#include<string.h>

class PrtArray
{
	public:
		void print_array(void*);

};

int main(int argc, char** argv)
{
	PrtArray pArray;
	char pData[5];

	std::cout<<"printing in function"<<std::endl;
	pArray.print_array(pData);

	std::cout<<"printing outside function"<<std::endl;
	std::cout<<pData<<std::endl;
	return 0;
}

void PrtArray::print_array(void *data)
{
	char result[] = "John Deere";
	
	std::cout<<result<<std::endl;

	data = result;
}

