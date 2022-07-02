class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); ++i)
            total += nums[i];
        const int target = total - x;
        int cur_sum = 0, ans = -1;
        if (target == 0)
            return nums.size();
        else if (target < 0)
            return -1;
        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            // if(cur_sum<target)
            {
                cur_sum += nums[i];
            }
            while (cur_sum > target && i >= j)
            {
                cur_sum -= nums[j++];
            }

            if (cur_sum == target)
            {
                ans = max(ans, i - j + 1);
                // cur_sum-=nums[j++];
            }
        }
        return ans == -1 ? -1 : nums.size() - ans;
    }
};