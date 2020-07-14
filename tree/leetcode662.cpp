/*
Leetcode 662
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
	int widthOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		queue<pair<TreeNode*, unsigned long long>> q;
		int ans = 1;
		q.push({ root, 1 });
		while (!q.empty()) {
			int sz = q.size();
			ans = max(int(q.back().second - q.front().second + 1), ans);
			for (int i = 0; i < sz; i++) {
				TreeNode *node = q.front().first;
				unsigned long long pos = q.front().second;
				q.pop();
				if (node->left) q.push({ node->left, 2 * pos });
				if (node->right) q.push({ node->right, 2 * pos + 1 });   // 记录每一个节点的层序遍历的位置
			}
		}
		return ans;
	}
};


int main() {
	vector<int> a = { 1,2,3,4,5,NULL,7 };
	TreeNode* root = insert_tree(a, a.size(), 0);
	Solution s;
	cout << s.widthOfBinaryTree(root) << endl;
}