// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         vector<int> temp;
//         TreeNode *t=root;
//         queue<TreeNode *> q;
//         if(t)
//         {
//             q.push(t);
//             q.push(NULL);
//             temp.push_back(t->val);
//             res.push_back(temp);
//         }
//         temp.clear();
//         while(!q.empty())
//         {
//             t=q.front();
//             q.pop();
//             if(!t) 
//             {
//                 if(temp.size()) res.push_back(temp);
//                 temp.clear();
//             }
//             if(t)
//             {
//                 if(t->left)
//                 {
//                     q.push(t->left);
//                     temp.push_back(t->left->val);
//                 }
//                 if(t->right)
//                 {
//                     q.push(t->right);
//                     temp.push_back(t->right->val);
//                 }
//             }
//             else if(!q.empty()) q.push(NULL);
//         }
//         return res;
//     }
// };
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            for(int i=0; i<n; i++){
                auto top = q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};