// Leetcode257
// 将二叉树的所有路径全部写到strin类型的vector
// created by wanghaozhi

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

class Solution {
public:
	vector<string> vec;
	string path;
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root)
		{
			return vec;
		}
		if (!root->left && !root->right)
		{
			path += to_string(root->val);
			vec.push_back(path);
			return vec;
		}
		path += to_string(root->val) + "->";
		string path2 = path;
		binaryTreePaths(root->left);
		path = path2;
		binaryTreePaths(root->right);
		path = path2;
		return vec;
	}
};

int main() {
	vector<int> a = { 1,2,3,NULL,5 };
	TreeNode* root = insert_tree(a, a.size(), 0);
	preorderTraverse(root);

	Solution s1;
	vector<string> res = s1.binaryTreePaths(root);
	cout << endl;
	cout << "print all the path of tree:" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}