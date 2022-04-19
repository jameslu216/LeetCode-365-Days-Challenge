/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int ans = 0;
    void inOrder(TreeNode *root, int &count)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, count);
        count--;
        if (count == 0)
        {
            ans = root->val;
            return;
        }
        inOrder(root->right, count);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inOrder(root, k);
        return ans;
    }
};