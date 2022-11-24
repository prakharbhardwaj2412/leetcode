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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if(inorder.size() != preorder.size()) return nullptr;
        
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        
        return buildTreeInPre(inorder, inStart, inEnd,
                             preorder, preStart, preEnd, inMap);
    }
    
    TreeNode* buildTreeInPre(vector<int>& inorder, int inStart, int inEnd, vector<int>& preorder, int preStart, int preEnd, map<int, int>& inMap) {
        
        if(inStart > inEnd || preStart > preEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]); 
        
        int elem = inMap[root -> val];
        int nElem = elem - inStart;
        
        root->left = buildTreeInPre(inorder, inStart, elem - 1,
                             preorder, preStart + 1, preStart + nElem, inMap);
        root->right = buildTreeInPre(inorder, elem + 1, inEnd,
                             preorder, preStart + nElem + 1, preEnd, inMap);
        
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