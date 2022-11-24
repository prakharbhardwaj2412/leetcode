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
// O(n) solution
class Solution {
public:
    int preorderIndex;
    map<int, int> inMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        preorderIndex = 0;
        int preStart = 0, preEnd = preorder.size() - 1;
        
        for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        
        return buildTreeInPre(preorder, preStart, preEnd);
    }
    
    TreeNode* buildTreeInPre(vector<int>& preorder, int preStart, int preEnd) {
        // if there are no elements to construct the tree
        if(preStart > preEnd) return nullptr;
        
        // select the preorder_index element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue); 
        
        root->left = buildTreeInPre(preorder, preStart, inMap[rootValue] - 1);
        root->right = buildTreeInPre(preorder, inMap[rootValue] + 1, preEnd);
        
        return root;
    }
};


// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if(preorder.size() == 0) return nullptr;
//         TreeNode *newNode = new TreeNode(preorder[0]);
//         int i = 0;
//         for(i = 0; i < inorder.size(); i++) if(inorder[i] == preorder[0]) break;
        
//         vector<int> leftIn;
//         vector<int> rightIn;
        
//         for(int j = 0; j < inorder.size(); j++) {
//             if(j < i) leftIn.push_back(inorder[j]);
//             if(j > i) rightIn.push_back(inorder[j]);
//         }
        
//         vector<int> leftPre;
//         vector<int> rightPre;
        
//         for(int j = 1; j < preorder.size(); j++) {
//             if(i > 0) {
//                 leftPre.push_back(preorder[j]);
//                 i--;
//             }
//             else {
//                 rightPre.push_back(preorder[j]);
//             }
//         }
        
//         newNode->left = buildTree(leftPre, leftIn);
//         newNode->right = buildTree(rightPre, rightIn);
        
//         return newNode;
//     }
// };