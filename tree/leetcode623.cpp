/*
Leetcode 623
created by wanghaozhi
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>

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
	void dfs(TreeNode* root, int v, int d, int k) {
		if (root == NULL) return;
		if (k == d - 1) {
			TreeNode* lnode = new TreeNode(v);
			TreeNode* rnode = new TreeNode(v);
			lnode->left = root->left;
			rnode->right = root->right;
			root->left = lnode;
			root->right = rnode;
			return;
		}
		dfs(root->left, v, d, k + 1);
		dfs(root->right, v, d, k + 1);
	}
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode* node = new TreeNode(v);
			node->left = root;
			return node;
		}
		dfs(root, v, d, 1);
		return root;
	}
};


int main() {
	vector<int> a = { 4,2,6,3,1,5 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s;
	TreeNode* res = s.addOneRow(root, 1, 2);
	preorderTraverse(res);
}