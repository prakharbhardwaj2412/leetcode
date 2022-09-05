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
        queue<Node*> Q;
        vector<vector<int>> res;
        if(root) Q.push(root);
        while(!Q.empty())
        {
            int n=Q.size();
            vector<int> temp;
            for(int i=0; i<n; i++)
            {
                Node* t=Q.front();
                Q.pop();
                temp.push_back(t->val);
                for(auto x:t->children)
                {
                    Q.push(x);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};