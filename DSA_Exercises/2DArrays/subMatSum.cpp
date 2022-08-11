#include <iostream>
#include <vector>

static void preprocessMat(std::vector<std::vector<int>>& mat)
{
	int rows = mat.size();
	int cols = mat[0].size();

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                mat[i][j] = mat[i][j] + mat[i][j-1];
            else if (j == 0)
                mat[i][j] = mat[i][j] + mat[i-1][j];
            else
                mat[i][j] = mat[i][j] + (mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1]);
		}
	}
}

static int sum(std::vector<std::vector<int>> v, int sr, int sc, int er, int ec)
{
    int ret;
	preprocessMat(v);
	if (sr == 0 && er == 0)
		ret = v[er][ec];
	else if (sr == 0)
		ret = v[er][ec] - v[er][sc-1];
	else if (sc == 0)
		ret = v[er][ec] - v[sr-1][ec];
	else
		ret = v[er][ec] - (v[sr-1][ec] + v[er][sc-1] - v[sr-1][sc-1]);

	return ret;

}

int main(int argc, char** argv)
{
    if (argc < 5){
        std::cerr<<"Enter exactly 4 integer query params"<<std::endl;
        return -1;
    }

    int startRow = std::stoi(argv[1]);
    int startCol = std::stoi(argv[2]);
    int endRow = std::stoi(argv[3]);
    int endCol = std::stoi(argv[4]);

    std::vector<std::vector<int>> mat = { {1,2,3,4,6},
                                          {5,3,8,1,2},
                                          {4,6,7,5,5},
                                          {2,4,8,9,4}};
    
    int subSum = sum(mat, startRow, startCol, endRow, endCol);
    std::cout<<"subMatrix sum: "<<subSum<<std::endl;
    return 0;
}
