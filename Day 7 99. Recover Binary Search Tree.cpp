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

// core idea:think it as an inorder traversal array list
class Solution
{
    TreeNode *firstErrorNode;
    TreeNode *secondErrorNode;
    TreeNode *tmp = new TreeNode(INT_MIN);

    void findIncorrectNode(TreeNode *root)
    {
        if (!root)
            return;
        findIncorrectNode(root->left);

        if (root->val < tmp->val)
        {
            if (firstErrorNode == nullptr)
            {
                firstErrorNode = tmp;
                secondErrorNode = root;
            }
            else
                secondErrorNode = root;
        }
        tmp = root;
        findIncorrectNode(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {

        findIncorrectNode(root);
        swap(firstErrorNode->val, secondErrorNode->val);
    }
};