/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
	void GeneratePreorder(string& pre, TreeNode* node){
		pre+=to_string(node->val)+",";
		if(node->left != nullptr)
			GeneratePreorder(pre, node->left);
		if(node->right != nullptr)
			GeneratePreorder(pre, node->right);
		return;
	}

	void GenerateInorder(string& in, TreeNode* node){
		if(node->left != nullptr)
			GenerateInorder(in, node->left);
		in+=to_string(node->val)+",";
		if(node->right != nullptr)
			GenerateInorder(in, node->right);
		return;
	}
		TreeNode* myBuildTree(unordered_map<int,int>& index, const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];

        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(index,preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(index,preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
				unordered_map<int,int> index;
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(index, preorder, inorder, 0, n - 1, 0, n - 1);
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
			string pre,in;
			if(root == nullptr)
				return "0*";
			GeneratePreorder(pre,root);
			GenerateInorder(in,root);
			pre.pop_back();
			in.pop_back();
			return to_string(pre.size())+"*"+pre+in;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
			int po = 0;
			string size;
			while(po < data.size() && data[po] != '*'){
				size += data[po++];
			}
			if(stoi(size) == 0)
				return nullptr;
			vector<int> pre;
			vector<int> in;
			string number;
			for(auto& c:data.substr(po+1,stoi(size))){
				if(c != ',')
					number+=c;
				else{
					pre.push_back(stoi(number));
					number.clear();
				}
			}
			for(auto& c:data.substr(po+stoi(size)+1)){
				if(c != ',')
					number+=c;
				else{
					in.push_back(stoi(number));
					number.clear();
				}
			}
			return buildTree(pre,in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

