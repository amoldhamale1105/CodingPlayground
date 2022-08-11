#include <iostream>
#include <vector>

static int binarySearch(const std::vector<int>& v, const int& x)
{
    int n = v.size();
    int mid = n/2;
    int retIndex{0};

    //Base case
    if (v[mid] == x)
        return mid;
    else if (n <= 1)
        return -1;
    
    //Rec case
    if (v[mid] > x)
        retIndex = binarySearch(std::vector<int>(v.begin(), v.begin()+mid), x);
    else{
        retIndex = binarySearch(std::vector<int>(v.begin()+mid+1, v.end()), x);
        if (retIndex != -1)
            retIndex += (mid+1);
    }

    return retIndex;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter element to be found and rerun"<<std::endl;
        return -1;
    }
    std::vector<int> vec = {1,3,5,7,9};
    int index = binarySearch(vec, std::stoi(argv[1]));

    if (index != -1)
        std::cout<<"Given element found at index: "<<index<<std::endl;
    else
        std::cout<<"Element not found!"<<std::endl;

    return 0;
}