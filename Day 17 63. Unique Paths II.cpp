class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> count(row + 1, vector<int>(col + 1, 0));
        for (int i = 0; i < row; ++i)
            count[i][0] = 1;
        for (int i = 0; i < col; ++i)
            count[0][i] = 1;
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    count[i][j] = 0;
                else
                    count[i][j] = count[i - 1][j] + count[i][j - 1];
            }
        }
        return count[row][col];
    }
};