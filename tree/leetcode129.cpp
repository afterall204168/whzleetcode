// Leetcode129
// 
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
public:
	int total_sum = 0;

	void dfs(TreeNode* node, int sum)
	{
		if (node == nullptr)
		{
			return;
		}

		sum = sum * 10 + node->val;

		if (node->left == nullptr && node->right == nullptr) //叶子节点
		{
			total_sum += sum;
			return;
		}

		dfs(node->left, sum);      // 深度优先搜索
		dfs(node->right, sum);
	}

	int sumNumbers(TreeNode* root) {

		dfs(root, 0);
		return total_sum;
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
	vector<int> a = { 10,9,20,NULL,NULL,15,7 };
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);

	// 层序遍历
	Solution s1;
	int res = s1.sumNumbers(root1);
	cout << "the sum is" << res << endl;
}
