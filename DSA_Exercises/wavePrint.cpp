#include <iostream>
#include <vector>

static std::vector<int> WavePrint(int m, int n, std::vector<std::vector<int>> arr)
{
    bool colTraversalDirectionUp{false};
	std::vector<int> wavePrint;
	int row{0};

	for(int col = n-1; col >= 0; col--)
	{
		if(colTraversalDirectionUp){
			row = m-1;
			while(row >= 0){
				wavePrint.emplace_back(arr[row][col]);
				row--;
			}
		}
		else{
			row = 0;
			while(row < m){
				wavePrint.emplace_back(arr[row][col]);
				row++;
			}
		}
		colTraversalDirectionUp = !colTraversalDirectionUp;
	}

	return wavePrint;
}

int main(int argc, char** agrv)
{
    std::vector<std::vector<int>> arr = { {1,2,3,4},
                                          {5,6,7,8},
                                          {9,10,11,12},
                                          {13,14,15,16}};
    
    std::vector<int> wavePrintedArr = WavePrint(arr.size(), arr[0].size(), arr);

    for(const int& num : wavePrintedArr)
    {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
