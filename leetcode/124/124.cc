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
	int ans = INT32_MIN;
public:
	int maxPathSum(TreeNode* root) {
		 dfs(root);
		return ans;
	}

	int dfs(TreeNode* root) {
		int value;
		int l;
		int r;
		if(root != nullptr && (root->left == nullptr || root->right == nullptr)){
			value = root->val;
			if(root->left != nullptr){
				l = dfs(root->left);
				value = max(value, value+l);
				ans = max(ans, l);
			}
			if(root->right!= nullptr){
				r = dfs(root->right);
				value = max(value, value+r);
				ans = max(ans, r);
			}
			ans = max(ans,value);
			return value;
		}
		l = dfs(root->left);
		r = dfs(root->right);
		value = max({root->val+l+r, l+root->val, r+root->val,root->val});
		ans = max({value, ans, l, r});
		return max({l+root->value,r+root->value,root->value}); 
	}

};

class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
