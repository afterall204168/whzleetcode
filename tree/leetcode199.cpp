// leetcode199
// 二叉树每一层最右边的节点
// 递归和迭代方法，迭代方法利用队列，每个节点都进行了一次入队
// created by wanghaozhi
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		helper(root, 0, res);
		return res;
	}
	void helper(TreeNode* root, int level, vector<int>& res) {
		if (!root) return;
		if (res.size() == level) res.push_back(root->val);
		helper(root->right, level + 1, res);
		helper(root->left, level + 1, res);
	}
};

class Solution2 {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			res.push_back(q.back()->val);
			int size = q.size();
			for (int i = 0; i<size; ++i) {
				TreeNode* t = q.front(); q.pop();
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return res;
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
	vector<int> re = { 1,2,3,NULL,5,NULL,4 };
	TreeNode* root = insert_tree(re, re.size(), 0);

	Solution1 s1;
	vector<int> res;
	res = s1.rightSideView(root);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}