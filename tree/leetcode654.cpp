/*
Leetcode 654
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return dfs(nums, 0, nums.size() - 1);
	}

	TreeNode* dfs(vector<int>& nums, int l, int r) {
		if (l > r) return nullptr;
		int idx = l;
		for (int i = l + 1; i <= r; ++i)
			if (nums[i] > nums[idx]) idx = i;

		TreeNode* root = new TreeNode(nums[idx]);
		root->left = dfs(nums, l, idx - 1);
		root->right = dfs(nums, idx + 1, r);
		return root;
	}
};

int main() {
	vector<int> a = { 3,2,1,6,0,5 };
	Solution s;
	TreeNode* res = s.constructMaximumBinaryTree(a);
	preorderTraverse(res);
}