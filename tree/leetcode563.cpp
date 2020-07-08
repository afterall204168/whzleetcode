/*
Leetcode 563
created by wanghaozhi
*/
#include<iostream>
#include<vector>

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
	int helper(TreeNode* root, int &tilt)
	{
		if (root == NULL)  return 0;
		int left = helper(root->left, tilt);
		int right = helper(root->right, tilt);
		tilt += abs(left - right);
		return left + right + root->val;
	}

	int findTilt(TreeNode* root) {
		int tilt = 0;
		helper(root, tilt);
		return tilt;
	}
};

int main() {
	vector<int> a = { 1,2,3 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s;
	int res = s.findTilt(root);
	cout << res << endl;
}