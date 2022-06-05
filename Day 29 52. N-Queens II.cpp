class Solution
{
public:
    int ans = 0;
    bool isValid(vector<string> &board, int row, int col)
    {

        for (int i = 1; i <= row; ++i)
        {
            if (col - i >= 0 && board[row - i][col - i] == 'Q')
                return false;
            if (col + i < board.size() && board[row - i][col + i] == 'Q')
                return false;
            if (board[row - i][col] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string> &board, int row)
    {
        if (row == board.size())
        {
            ans++;
            return;
        }
        for (int col = 0; col < board.size(); ++col)
        {
            if (isValid(board, row, col))
            {
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return ans;
    }
};