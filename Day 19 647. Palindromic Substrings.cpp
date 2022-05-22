class Solution
{
public:
    void recursiveFunc(const string &s, int i, int &ans)
    {
        for (int j = 0; j <= i && i + j < s.size(); j += 1)
        {

            if (s[i - j] != s[i + j])
                break;
            ans++;
        }

        for (int j = 0; j <= i && i + 1 + j < s.size(); j += 1)
        {

            if (s[i - j] != s[i + 1 + j])
                break;
            ans++;
        }
    }
    int countSubstrings(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            recursiveFunc(s, i, ans);
        }
        return ans;
    }
};