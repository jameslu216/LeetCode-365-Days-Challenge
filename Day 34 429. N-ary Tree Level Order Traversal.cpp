/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;

        vector<int> tmp;
        queue <Node*> q;
        Node *ptr = root;
        q.push(ptr);\
        tmp.push_back(ptr->val);
        ans.push_back(tmp);
        tmp.clear();
        while(!q.empty())
        {
            int queueSize=size(q);
            cout <<queueSize<<endl;
            while(queueSize--)
            {
                ptr = q.front();
                q.pop();
               
                for(Node *child:ptr->children)
                {
                    q.push(child);
                    tmp.push_back(child->val);
                }
            }
            if(!q.empty())  ans.push_back(tmp);
            tmp.clear();
           
        }
        return ans;
    }
};