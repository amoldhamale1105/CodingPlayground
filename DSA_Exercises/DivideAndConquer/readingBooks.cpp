#include <iostream>
#include <vector>

bool canDistribute(const std::vector<int>& books, int partition, int count)
{
    int students = 0;
    int pages{0};

    for(int i = 0; i < books.size(); i++)
    {
        if (books[i] > partition)
            return false;
        pages += books[i];
        if (pages > partition){
            students++;
            if (students == count)
                return false;
            pages = books[i];
        }
    }
    return true;
}

int minPages(const std::vector<int>& books, int m)
{
    int minPagesVec = books.front();
    int totalPages{0};
    for(int pages: books)
    {
        minPagesVec = std::min(minPagesVec, pages);
        totalPages += pages;
    }

    // Monotonic search space between min and max pages
    int s = minPagesVec;
    int e = totalPages;
    int minimizedMaxPages = 0;

    while (s <= e)
    {
        int mid = (s+e)/2;
        if (canDistribute(books, mid, m)){
            e = mid-1;
            minimizedMaxPages = mid;
        }
        else
            s = mid+1;
    }
    
    return minimizedMaxPages;
}

int main()
{
    std::vector<int> books = {10,20,30,15};
    const int students = 2;
    std::cout<<"Min of maximum pages to be read: "<<minPages(books, students)<<std::endl;
    return 0;
}