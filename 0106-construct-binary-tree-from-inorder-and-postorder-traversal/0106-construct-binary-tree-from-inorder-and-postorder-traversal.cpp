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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart = 0, inEnd = inorder.size() - 1;
        int postStart = 0, postEnd = postorder.size() - 1;
        
        map<int, int> inMap;
        for(int i = 0; i <= inEnd; i++) inMap[inorder[i]] = i;
        return buildTreeInPost(inorder, inStart, inEnd,
                        postorder, postStart, postEnd, inMap);
    }
    
    TreeNode* buildTreeInPost(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& inMap) {
        
        if(is > ie || ps > pe) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int elem = inMap[postorder[pe]];
        int xElem = elem - is;
        
        root->left = buildTreeInPost(inorder, is, elem - 1,
                        postorder, ps, ps + xElem - 1, inMap);
        root->right = buildTreeInPost(inorder, elem + 1, ie,
                        postorder, ps + xElem, pe - 1, inMap);
        return root;
    }
    
};





// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         if(postorder.size() == 0) return nullptr;
        
//         int value = postorder[postorder.size() - 1];
//         TreeNode* newNode = new TreeNode(value);
        
//         int i = 0;
//         for(i = 0; i < inorder.size(); i++) if(inorder[i] == value) break;
        
//         vector<int> leftIn;
//         vector<int> rightIn;
//         vector<int> leftPost;
//         vector<int> rightPost;
        
//         for(int j = 0; j < inorder.size(); j++) {
//             if(j < i) leftIn.push_back(inorder[j]);
//             if(j > i) rightIn.push_back(inorder[j]);
//         }
        
//         for(int j = 0; j < postorder.size()-1; j++) {
//             if(j < i) leftPost.push_back(postorder[j]);
//             if(j >= i) rightPost.push_back(postorder[j]);
//         }
        
//         newNode->left = buildTree(leftIn, leftPost);
//         newNode->right = buildTree(rightIn, rightPost);
        
//         return newNode;
//     }
// };