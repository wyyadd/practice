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
	unordered_map<TreeNode*,int> t_map;
	unordered_map<TreeNode*,int> f_map;
public:
	// dp(node,true) = max(val+dp(node->left, false)+dp(node->right, false), 
	//																		dp(node->left, true)+dp(node->right, true))
	// dp(node,false) = dp(node->left, true)+dp(node->right, true)
	int rob(TreeNode* root) {
		return steal(root,true);			
	}

	int steal(TreeNode*node, bool canSteal){
		if(node == nullptr)
			return 0;
		if(canSteal && t_map.find(node) != t_map.end())
			return t_map[node];
		if(!canSteal && f_map.find(node) != f_map.end())
			return f_map[node];

		int max_money;
		if(canSteal){
			max_money = max(node->val+steal(node->left,false)+steal(node->right,false),
									steal(node->left,true)+steal(node->right,true));
			t_map.insert(make_pair(node,max_money));
		}
		else{
			max_money = steal(node->left,true)+steal(node->right,true);
			f_map.insert(make_pair(node,max_money));
		}
		return max_money;
	}
};

struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution {
public:
    SubtreeStatus dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode* root) {
        auto rootStatus = dfs(root);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};
