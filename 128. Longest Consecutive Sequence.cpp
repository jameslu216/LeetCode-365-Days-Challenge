class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (num_set.find(nums[i] - 1) != num_set.end())
                continue;
            else
            {
                int count = 1;
                int cur_num = nums[i] + 1;
                while (num_set.find(cur_num) != num_set.end())
                {
                    cur_num++;
                    count++;
                }
                ans = max(count, ans);
            }
        }
        return ans;
    }
};
