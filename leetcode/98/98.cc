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
    bool isValidBST(TreeNode* root) {
			return walk(root, INT64_MIN, INT64_MAX);
		}

    bool walk(TreeNode* root, long min_, long max_) {
			if (root->left != nullptr){
				if(root->left->val <= min_ || root->left->val >= root->val)
					return false;
				if(!walk(root->left, min_, root->val))
					return false;
			}
			if(root->right != nullptr){
				if(root->right->val <= root->val || root->right->val >= max_)
					return false;
				if(!walk(root->right, root->val, max_))
					return false;
			}
			return true;
    }
};
