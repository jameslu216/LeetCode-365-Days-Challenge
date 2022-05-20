class Solution
{
    const int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

public:
    int dfs(vector<vector<int>> &copy, vector<vector<int>> &count, int x, int y)
    {
        int step = 1;
        if (count[x][y] > 0)
            return count[x][y];
        for (int i = 0; i < 4; ++i)
        {
            if (copy[x + dir[i][1]][y + dir[i][0]] > copy[x][y])
            {

                step = max(step, dfs(copy, count, x + dir[i][1], y + dir[i][0]) + 1);
            }
        }
        cout << "x: " << x << " y: " << y << " step: " << step << endl;
        count[x][y] = step;
        return step;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size() + 2;
        int n = matrix[0].size() + 2;
        int ans = -1;
        vector<vector<int>> copy(m, vector<int>(n));
        vector<vector<int>> count(m, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            copy[0][i] = -1;
            copy[m - 1][i] = -1;
        }
        for (int i = 0; i < m; ++i)
        {
            copy[i][0] = -1;
            copy[i][n - 1] = -1;
        }
        for (int i = 1; i < m - 1; ++i)
        {
            for (int j = 1; j < n - 1; ++j)
            {
                copy[i][j] = matrix[i - 1][j - 1];
            }
        }
        //  for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         cout << copy[i][j];
        //     }
        //     cout << endl;
        // }
        for (int i = 1; i < m - 1; ++i)

        {
            for (int j = 1; j < n - 1; ++j)
            {

                ans = max(ans, dfs(copy, count, i, j));
            }
        }

        return ans;
    }
};