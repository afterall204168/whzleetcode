#include<iostream>
#include<vector>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		int left = depth(root->left);
		int right = depth(root->right);
		if (left == right) {
			return pow(2, left) + countNodes(root->right);
		}
		else {
			return  pow(2, right) + countNodes(root->left);
		}
	}

	int depth(TreeNode* root) {
		int ans = 0;
		while (root) {
			ans++;
			root = root->left;
		}
		return ans;
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
	vector<int> re = { 1, 2, 3, 4, 5, 6};
	TreeNode* root = insert_tree(re, re.size(), 0);

	Solution s1;
	int res = s1.countNodes(root);
	cout << res << endl;
}