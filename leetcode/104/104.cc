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
	int depth = 0;
public:
    int maxDepth(TreeNode* root) {
	//		walk(root,0);
	//		return depth;
				if(root == nullptr)
					return 0;
				return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

		void walk(TreeNode* root, int d){
			if(d > depth)
				depth = d;
			if(root == nullptr)		
				return;
			walk(root->left, d+1);
			walk(root->right, d+1);
		}
};
