#include <unordered_map>
#include <algorithm>
#include <ComplexObjectStream.hpp>

std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
    std::unordered_map<int,int> hashMap;
    std::vector<int> intersection;

    for(const int& num : nums1)
    {
        hashMap.insert({num,0});
    }
    for(const int& num : nums2)
    {
        auto itr = hashMap.find(num);
        if (hashMap.find(num) != hashMap.end()){
            intersection.emplace_back(itr->first);
            hashMap.erase(itr);
        }
    }
    
    if (intersection.size() > 1)
        std::sort(intersection.begin(), intersection.end());
    
    return intersection;
}

int main()
{
    std::vector<int> arr1 = {1,2,2,1};
    std::vector<int> arr2 = {2,2};

    std::cout<<"Intersection: "<<intersection(arr1, arr2)<<std::endl;
    return 0;
}