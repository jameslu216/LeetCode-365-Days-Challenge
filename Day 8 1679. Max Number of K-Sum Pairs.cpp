class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int ans = 0;
        for (int e : nums)
        {
            if (map[k - e] > 0)
            {
                map[k - e]--;
                ans++;
            }
            else
            {
                map[e]++;
            }
        }
        return ans;
    }
};