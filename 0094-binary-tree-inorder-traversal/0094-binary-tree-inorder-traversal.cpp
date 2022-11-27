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
// class Solution {
// public:
//     vector<int> res;
//     vector<int> inorderTraversal(TreeNode* root) {
// //         =======================RECURSIVE INORDER
//         // if(root)
//         // {
//         //     inorderTraversal(root->left);
//         //     res.push_back(root->val);
//         //     inorderTraversal(root->right);
//         // }
//         // return res;
// //         =================================ITERATIVE INORDER=======================
//         stack<TreeNode *> st;
//         TreeNode* t=root;
//         while(t || !st.empty())
//         {
//             if(t)
//             {
//                 st.push(t);
//                 t=t->left;
//             }
//             else
//             {
//                 t=st.top();
//                 st.pop();
//                 res.push_back(t->val);
//                 t=t->right;
//             }
//         }
//         return res;
//     }
// };

// ==========================ALL TRAVERSAL IN ONE SHOT
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<pair<TreeNode*, int>> st;
//         st.push({root, 1});
//         vector<int> pre, in, post;
//         if(root==NULL) return {};
//         while(!st.empty()) {
//             auto it = st.top();
//             st.pop();
//             if(it.second == 1) {
//                 pre.push_back(it.first->val);
//                 it.second++;
//                 st.push(it);
//                 if(it.first->left) st.push({it.first->left, 1});
//             }
//             else if(it.second == 2) {
//                 in.push_back(it.first->val);
//                 it.second++;
//                 st.push(it);
//                 if(it.first->right) st.push({it.first->right, 1});
//             }
//             else 
//                 post.push_back(it.first->val);
//         }
//         return in;

//     }
// };

// ==========================MORRIS TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                
                if(prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return inorder;

    }
};