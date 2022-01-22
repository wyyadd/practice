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
	vector<TreeNode *> VLR;
public:
    void flatten(TreeNode* root) {
			if(root == nullptr)
				return;
			walk(root);
			for(auto i = VLR.begin(); i != VLR.end() - 1; ++i) {
				(*i)->left = nullptr;
				(*i)->right = *(i+1);
			}
			VLR.back()->left = nullptr;
			VLR.back()->right = nullptr;
    }

		void walk(TreeNode* node){
			// node
			VLR.push_back(node);
			// Left
			if(node->left != nullptr)
				walk(node->left);
			// right
			if(node->right != nullptr)
				walk(node->right);
			return;
		}
};
