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
    int postIndex;
    map<int, int> inMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // recursively use the left and right portions of inorder to construct the left and right subtrees.
        int inStart = 0, inEnd = inorder.size() - 1;
        
        postIndex = postorder.size() - 1;

        // build a hashmap to store value -> its index relations
        for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        
        return buildTreeInPost(postorder, inStart, inEnd);
    }
    
    TreeNode* buildTreeInPost(vector<int>& postorder, int inStart, int inEnd) {
        // if there are no elements to construct the tree
        if(inStart > inEnd) return nullptr;
        
        // select the preorder_index element as the root and increment it
        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue); 
        
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root->right = buildTreeInPost(postorder, inMap[rootValue] + 1, inEnd);
        root->left = buildTreeInPost(postorder, inStart, inMap[rootValue] - 1);
        
        
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