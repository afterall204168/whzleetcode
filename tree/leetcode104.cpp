/*
Leetcode 104
求解二叉树的深度
递归求解。
created by wanghaozhi
*/
#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode *insert_tree(vector<int>& x, int n, int start) {
	if (x[start] == NULL) { return NULL; }
	TreeNode* root = new TreeNode;
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

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) {
			return 0;
		}
		else {
			int leftDepth = maxDepth(root->left);
			int rightDepth = maxDepth(root->right);
			return max(leftDepth, rightDepth) + 1;
		}
	}
};


int main() {
	// vector形式转化为树
	vector<int> a = { 3,9,20,NULL,NULL,15,7 };
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);

	// 层序遍历
	Solution s1;
	int res = s1.maxDepth(root1);
	preorderTraverse(root1);
	cout << res << endl;
}