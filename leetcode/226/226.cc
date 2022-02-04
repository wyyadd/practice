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
	TreeNode* invertTree(TreeNode* root) {
		dfs(root); 
		return root;
	}

	void dfs(TreeNode* node){
		if(node == nullptr)
			return;
		if(node -> left == nullptr && node -> right == nullptr)
			return;
		swap(node->left,node->right);
		dfs(node->left);
		dfs(node->right);
	}
};
