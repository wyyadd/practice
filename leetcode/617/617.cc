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
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		TreeNode* root = new TreeNode;	
		if(merge(root1,root2,root))
			root = nullptr;
		return root;
	}

	bool merge(TreeNode* node1, TreeNode* node2, TreeNode* node){
		if(node1 == nullptr && node2 == nullptr){
			delete node;
			return true;
		}
		auto ln = new TreeNode;
		auto rn = new TreeNode;
		node->left = ln;
		node->right = rn;
		if(node1 == nullptr){
			node->val = node2->val;
			if(merge(nullptr,node2->left,ln))
				node->left = nullptr;
			if(merge(nullptr,node2->right,rn))
				node->right = nullptr;
			return false;
		}
		if(node2 == nullptr){
			node->val = node1->val;
			if(merge(node1->left,nullptr,ln))
				node->left = nullptr;
			if(merge(node1->right,nullptr,rn))
				node->right = nullptr;
			return false;
		}
		node->val = node1->val+ node2->val;
		if(merge(node1->left,node2->left,ln))
			node->left = nullptr;
		if(merge(node1->right,node2->right,rn))
			node->right = nullptr;
		return false;
	}
};
