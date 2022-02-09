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
	int ans = 0;
	int originTargetSum;
public:
	int pathSum(TreeNode* root, int targetSum) {
		originTargetSum = targetSum;
		walk(root,targetSum,true);
		return ans;
	}

	void walk(TreeNode* node, int targetSum, bool reset){
		if(node == nullptr)
			return;
		if(node->val == targetSum)
			++ans;
		walk(node->left,targetSum-node->val,false);
		walk(node->right,targetSum-node->val,false);
		if(reset){
			walk(node->left,originTargetSum,true);
			walk(node->right,originTargetSum,true);
		}
	}
};
