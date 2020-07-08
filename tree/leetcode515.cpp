/*
Leetcode 515
created by wanghaozhi
*/
#include<iostream>
#include<vector>
#include<queue>
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
	vector<int> res;
	void dfs(TreeNode* curNode, int level) {
		if (res.size() == level) res.push_back(INT_MIN);
		res[level] = max(res[level], curNode->val);
		if (curNode->left) dfs(curNode->left, level + 1);
		if (curNode->right) dfs(curNode->right, level + 1);
	}
	vector<int> largestValues(TreeNode* root) {
		if (root == NULL) return res;
		dfs(root, 0);
		return res;
	}
};


class Solution2 {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int levelSize = q.size();
			int levelMax = INT_MIN;
			for (int i = 0; i < levelSize; i++) {
				TreeNode* curNode = q.front();
				q.pop();
				levelMax = max(curNode->val, levelMax);
				if (curNode->left) q.push(curNode->left);
				if (curNode->right) q.push(curNode->right);
			}
			res.push_back(levelMax);
		}
		return res;
	}
};


int main() {
	vector<int> a = { 1,3,2,5,3,9 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s;
	vector<int> res = s.largestValues(root);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}