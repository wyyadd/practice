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
    vector<int> inorderTraversal(TreeNode* root) {
			vector<int> result;       
			if(root != nullptr)
				walk(result, root);
			return result;
    }

		// inorder LVR
		void walk(vector<int>& result, TreeNode* node){
			// Left
			if(node->left != nullptr)
				walk(result, node->left);
			// node
			result.push_back(node->val);
			// right
			if(node->right != nullptr)
				walk(result, node->right);
			return;
		}
};
