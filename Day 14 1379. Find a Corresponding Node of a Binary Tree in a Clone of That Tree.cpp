/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    void dfs(TreeNode *cloned, TreeNode *target, TreeNode *&ans, TreeNode *tmp)
    {
        if (tmp == nullptr)
            return;
        if (tmp->val == target->val)
        {
            ans = tmp;
            return;
        }
        dfs(cloned, target, ans, tmp->left);
        dfs(cloned, target, ans, tmp->right);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        TreeNode *ans = nullptr;
        TreeNode *tmp = cloned;
        dfs(cloned, target, ans, tmp);
        return ans;
    }
};