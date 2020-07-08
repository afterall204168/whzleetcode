// leetcode 513
// created by wanghaozhi

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
	int res = 0;
	int maxlevel = 0;
	int findBottomLeftValue(TreeNode* root) {
		helper(root, 1);
		return res;
	}

	void helper(TreeNode* root, int level) {
		if (root == NULL) return;

		helper(root->left, level + 1);

		if (level > maxlevel) {
			maxlevel = level;
			res = root->val;
		}

		helper(root->right, level + 1);
	}
};

int main() {
	vector<int> a = { 1,2,3 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s1;
	int res = s1.findBottomLeftValue(root);
	cout << res << endl;
}