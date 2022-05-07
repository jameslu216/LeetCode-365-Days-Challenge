class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int big = INT_MIN;
        int n = nums.size();
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < s3)
                return true;
            while (!s.empty() && nums[i] > s.top())
            {
                big = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};