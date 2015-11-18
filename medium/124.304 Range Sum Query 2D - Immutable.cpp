/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    vector<vector<int> > s;
    NumMatrix(vector<vector<int>> &matrix) 
    {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        s = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int x = 0; x < matrix.size(); x++)
        {
            for(int y = 0; y < matrix[x].size(); y++)
            {
                if(x-1 >= 0)
                    s[x][y] += s[x-1][y];
                if(y-1 >= 0)
                    s[x][y] += s[x][y-1];
                if(x-1 >= 0 && y-1 >= 0)
                    s[x][y] -= s[x-1][y-1];
                s[x][y] += matrix[x][y];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int x1 = row1, y1 = col1, x2 = row2, y2 = col2;
        int area = s[x2][y2];
        if(x1-1 >= 0)
            area -= s[x1-1][y2];
        if(y1-1 >= 0)
            area -= s[x2][y1-1];
        if(x1-1 >= 0 && y1-1 >= 0)
            area += s[x1-1][y1-1];
        return area;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

/*
  动态规划。
  先算出s(x,y)为[0,0]至[x,y]的和
  s(x,y) = s(x-1,y)+s(x,y-1)-s(x-1,y-1)+matrix[x][y].
  再计算sumRegion(x1,y1,x2,y2) = s(x2,y2)-s(x1-1,y2)-s(x2,y1-1)+s(x1-1,y1-1).
*/
