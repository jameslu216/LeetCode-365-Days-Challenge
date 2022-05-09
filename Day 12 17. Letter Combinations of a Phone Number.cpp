class Solution
{
public:
    vector<string> ans;
    map<int, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void solve(const string targetString, string curString, int curLength)
    {
        if (curLength == targetString.length())
        {
            ans.push_back(curString);
            return;
        }
        for (int i = 0; i < map[targetString[curLength]].size(); ++i)
        {
            solve(targetString, curString + map[targetString[curLength]][i], curLength + 1);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() != 0)
            solve(digits, "", 0);
        return ans;
    }
};