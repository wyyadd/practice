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
private:
	int diameter = 0;
public:
	int diameterOfBinaryTree(TreeNode* root) {
		walk(root,0);
		return diameter;
	}
	
	int walk(TreeNode*node, int length){
		if(node == nullptr)
			return length-1;
		auto l_length = walk(node->left,length+1);
		auto r_length = walk(node->right,length+1);
		diameter = max(diameter, l_length+r_length-2*length);
		return max(l_length,r_length);
	}
};
