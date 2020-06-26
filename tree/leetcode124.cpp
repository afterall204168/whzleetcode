#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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


TreeNode *insert_tree(vector<int>& x, int n, int start) {
	if (x[start] == NULL) { return NULL; }
	TreeNode* root = new TreeNode(0);
	root->val = x[start];
	root->left = NULL;
	root->right = NULL;

	int lnode = 2 * start + 1;
	int rnode = 2 * start + 2;

	if (lnode > n - 1)root->left = NULL;
	else root->left = insert_tree(x, n, lnode);

	if (rnode > n - 1)root->right = NULL;
	else root->right = insert_tree(x, n, rnode);

	return root;
}


void preorderTraverse(TreeNode *T) {
	if (T) {
		cout << T->val << " ";
		preorderTraverse(T->left);
		preorderTraverse(T->right);
	}
}

int main() {
	// vector形式转化为树
	vector<int> a = { -10,9,20,NULL,NULL,15,7 };
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);

	// 层序遍历
	Solution s1;
	int res = s1.maxPathSum(root1);
	cout << "the max sum is" << res << endl;
}
