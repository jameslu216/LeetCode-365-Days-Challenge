class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (n % 2 == 1)
                ans++;
            n /= 2;
        }
        return ans;
    }
};