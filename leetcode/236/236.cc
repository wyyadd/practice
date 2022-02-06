/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root == nullptr)
			return nullptr;
		if(root == p || root == q)
			return root;
		auto left_root = lowestCommonAncestor(root->left, p, q);
		auto right_root = lowestCommonAncestor(root->right, p, q);
		if(left_root != nullptr && right_root != nullptr)
			return root;
		if(left_root == nullptr)
			return right_root;
		else
			return left_root;
	}
};
