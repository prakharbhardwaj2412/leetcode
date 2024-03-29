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
// There are three solutions for this:
// 1) RECURSIVE APPROACH
// class Solution {
// public:
//     TreeNode* prev = nullptr;
//     void flatten(TreeNode* root) {
//         // =================REVERSE POSTORDER
//         if(!root) return;
//         flatten(root->right); // RIGHT
//         flatten(root->left); // LEFT
//         root->right = prev; // LOGIC
//         root->left = nullptr;
//         prev = root;
//     }
// };

// 2) ITERATIVE APPROACH
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(!root) return;
        
//         stack<TreeNode*> st;
//         st.push(root);
        
//         while(!st.empty()) {
//             TreeNode* curr = st.top(); st.pop();
//             if(curr->right) st.push(curr->right); // RIGHT
//             if(curr->left) st.push(curr->left); // LEFT
            
//             if(!st.empty()) curr->right = st.top(); // LOGIC
//             curr->left = NULL;
//         }
//     }
// };

// 3) MORRIS TRAVERSAL APPROACH
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left != NULL) {
                TreeNode* prev = curr->left;
                while(prev->right) prev = prev->right;
                
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};