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
    string ans="";
public:
    string tree2str(TreeNode* root) {
        if(!root)   return  "";
        ans+=to_string(root->val);
    
        if(root->left)
        {
            ans+="(";
            tree2str(root->left);
            ans+=")";

        }
        if(root->right)
        {
            if(!root->left)
                ans+="()";
            ans+="(";
            tree2str(root->right);
            ans+=")";
        }
        return ans;
    }
};