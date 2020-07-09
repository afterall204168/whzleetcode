/*
Leetcode 606
created by wanghaozhi
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string>

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

	void preAccess(TreeNode* t, string & str)
	{
		if (t == NULL) return;
		str += to_string(t->val);
		if (t->left || t->right)
		{
			str += "(";
			preAccess(t->left, str);
			str += ")";
		}
		if (t->right)
		{
			str += "(";
			preAccess(t->right, str);
			str += ")";
		}
	}

	string tree2str(TreeNode* t) {
		string res = "";
		preAccess(t, res);
		return res;
	}
};


int main() {
	vector<int> a = { 1,2,3,4 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s;
	string res = s.tree2str(root);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}