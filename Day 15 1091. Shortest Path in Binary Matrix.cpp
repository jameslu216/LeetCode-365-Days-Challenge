// A good example that when asking shortest , using bfs not dfs
class Solution
{
    const int dir[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid[0].size() + 2;
        queue<pair<int, int>> q;
        vector<vector<int>> copy(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            copy[i][0] = 1;
            copy[i][n - 1] = 1;
            copy[0][i] = 1;
            copy[n - 1][i] = 1;
        }
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < n - 1; ++j)
            {
                copy[i][j] = grid[i - 1][j - 1];
            }
        }
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         cout << copy[i][j];
        //     }
        //     cout << endl;
        // }
        int ans = 0, x = 1, y = 1, curStep = 1;
        if (copy[x][y] == 0)
        {
            q.push({x, y});
            copy[x][y] = 1;
        }

        while (!q.empty())
        {
            ans++; // queue store the point that the current steps are reachable
            int vol = q.size();
            for (int i = 0; i < vol; ++i)
            {
                pair<int, int> tmp = q.front();
                x = tmp.first, y = tmp.second;
                q.pop();
                if (x == n - 2 && y == n - 2)
                    return ans;
                for (int i = 0; i < 8; ++i)
                {
                    if (copy[x + dir[i][1]][y + dir[i][0]] == 0)
                    {
                        copy[x + dir[i][1]][y + dir[i][0]] = 1;
                        q.push({x + dir[i][1], y + dir[i][0]});
                    }
                }
            }
        }

        return -1;
    }
};