#include <iostream>
#include <vector>

static std::vector<int> sortingWithComparator(std::vector<int> a, bool flag){
   int n = a.size();
   int first_pos;

   for(int i = 0; i < n-1; i++)
   {
       first_pos = i;

       for(int j = i; j < n; j++)
       {
           if(flag ? (a[j] < a[first_pos]) : (a[j] > a[first_pos]))
               first_pos = j;
       }
       std::swap(a[i], a[first_pos]);
   }
   return a;
}

int main()
{
    std::vector<int> vec = {111,33,5,7,29};
    std::vector<int> sortedList = sortingWithComparator(vec, false);
    for(int x : sortedList)
        std::cout<<x<<" ";
    std::cout<<std::endl;
    return 0;
}
