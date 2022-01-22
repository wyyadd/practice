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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			TreeNode* root = new TreeNode;
			walk(preorder, inorder, root);
			return root;
    }

		void walk(vector<int>& preorder, vector<int>& inorder, TreeNode* node){
			if(inorder.empty())
				return;
			node->val = preorder[0];
			// get root
			int po = 0;
			while(inorder[po] != preorder[0]) {++po;}
			// recursive
			if(po != 0){
				auto l = new TreeNode;
				node->left = l;
				vector<int> pre(preorder.begin()+1, preorder.begin()+po+1); 
				vector<int> in(inorder.begin(), inorder.begin()+po); 
				walk(pre,in,l);
			}
			if(po != inorder.size()-1){
				auto r = new TreeNode;
				node->right = r;
				vector<int> pre(preorder.begin()+po+1,preorder.end());
				vector<int> in(inorder.begin()+po+1,inorder.end());
				walk(pre,in,r);
			}
		}
};
