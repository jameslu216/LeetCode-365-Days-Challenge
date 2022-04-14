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
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* currentNode= q.front();
        q.pop();
        if(currentNode->val==val)
        {
            return currentNode;
            break;
        }
        if(currentNode->left!=nullptr)
        {
            q.push(currentNode->left);
        }
        if(currentNode->right!=nullptr)
        {
            q.push(currentNode->right);
        }
    }
    return nullptr;
    }
};