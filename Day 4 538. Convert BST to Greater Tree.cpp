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

void inOrderRight(TreeNode *root, int &sum)
{
    if (root->right != nullptr)
        inOrderRight(root->right, sum);
    sum += root->val;
    root->val = sum;
    if (root->left != nullptr)
        inOrderRight(root->left, sum);
}
class Solution
{
public:
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        if (root != nullptr)
            inOrderRight(root, sum);
        return root;
    }
};