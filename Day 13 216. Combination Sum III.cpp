class Solution
{

    vector<vector<int>> ans;
    vector<int> tmp;

    void solve(int i, int n, int k)
    {
        if ((tmp.size() > 0 && n <= tmp.back()))
            return;
        if (tmp.size() == k - 1)
        {
            if (n > 9)
                return;
            tmp.push_back(n);
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        for (; i <= n; ++i)
        {
            tmp.push_back(i);
            solve(i + 1, n - i, k);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        solve(1, n, k);
        return ans;
    }
};