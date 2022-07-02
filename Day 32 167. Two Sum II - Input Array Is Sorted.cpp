class Solution
{
public:
    vector<int>
    twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (true)
        {
            if (numbers[left] + numbers[right] > target)
                right--;
            else if (numbers[left] + numbers[right] < target)
                left++;
            else
                break;
        }

        return {++left, ++right};
    }
};