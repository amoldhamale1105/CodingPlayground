#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vec)
{
    stream<<"[";
    for(const int& num : vec)
    {
        stream << num << " ";
    }
    stream<<'\b'<<"]";
    return stream;
}

std::vector<int> kRotate(const std::vector<int>& a, const int& k)
{
    std::vector<int> rotatedVec = a;
	int n = a.size();
	for(int i = 0; i < n; i++)
	{
		rotatedVec[(i + k) % n] = a[i];
	}

	return rotatedVec;
}

int main(int argc, char* argv[])
{
    if (argc < 2){
        std::cerr<<"Please enter the number of rotations as program arg"<<std::endl;
        return -1;
    }

    std::vector<int> vec = {1, 3, 5, 7, 9};
    std::cout<<"rotated array: "<<kRotate(vec, std::stoi(argv[1]))<<std::endl;

    return 0;
}