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

// RECURSION
// class Solution {
// public:
//     int maxDepth(Node* root) {
//         if(!root) return 0;
//         int maxh=0;
//         for(auto it : root->children) {
//             maxh = max(maxh, maxDepth(it));
//         } 
//         return maxh+1;
        
//     }
// };

// LEVEL ORDER TRAVERSAL TO FIND HEIGHT
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*> q;
        int height=0;
        q.push(root);
        while(!q.empty()) {
            int ln = q.size();
            for(int i=0; i<ln; i++) {
                auto node=q.front();
                q.pop();
                for(auto it : node->children) if(it) q.push(it);
            }
            height++;
        }
        return height;
        
    }
};