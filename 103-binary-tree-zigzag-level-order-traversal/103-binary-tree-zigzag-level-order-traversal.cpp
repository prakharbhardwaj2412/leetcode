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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
    	vector<vector<int>> res;
    	if(!root) return res;
    	q.push(root);
    	bool zigzag=false;
    // 	cout<<zigzag<<" "<<!zigzag<<endl;
    	while(!q.empty())
    	{
    	    
    	    int n=q.size();
    	    vector<int> temp;
    	    for(int i=0; i<n; i++)
    	    {
    	        root=q.front();
    	        q.pop();
    	        temp.push_back(root->val);
    	        if(root->left) q.push(root->left);
    	        if(root->right) q.push(root->right);
    	    }
    	    if(zigzag) reverse(temp.begin(), temp.end());
            res.push_back(temp);
    	    zigzag=!zigzag;
    	}
    	return res;
    }
};