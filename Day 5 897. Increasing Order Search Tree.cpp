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
    TreeNode *head = new TreeNode(0);
    TreeNode *cur = head;
    void inOrderBuild(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrderBuild(root->left);
        TreeNode *newNode = new TreeNode(root->val);
        cur->right = newNode;
        cur = cur->right;
        inOrderBuild(root->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {

        inOrderBuild(root);
        return head->right;
    }
};