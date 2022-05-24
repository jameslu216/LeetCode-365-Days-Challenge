class Solution
{
public:
    void init(int &left, int &right)
    {
        left = 0;
        right = 0;
    }
    int longestValidParentheses(string s)
    {
        int ans = 0;
        int leftway = 0, rightway = 0;
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (right > left)
            {
                init(left, right);
            }
            else if (right == left)
                leftway = max(leftway, min(right, left) * 2);
        }
        init(left, right);
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left > right)
            {

                init(left, right);
            }
            else if (right == left)
                leftway = max(leftway, min(right, left) * 2);
        }
        ans = max(leftway, rightway);
        return ans;
    }
};