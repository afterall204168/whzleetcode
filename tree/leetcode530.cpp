/*
Leetcode 530
created by wanghaozhi
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>
#include<algorithm>
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
	int getMinimumDifference(TreeNode* root) {
		std::vector<int> arr;
		dfs(root, arr);
		int min = abs(arr[1] - arr[0]);
		for (int index = 2; index <= arr.size() - 1; index++)
		{
			min = (abs(arr[index] - arr[index - 1]) < min) ? (abs(arr[index] - arr[index - 1])) : min;
		}
		return min;
	}

private:
	void dfs(TreeNode* root, std::vector<int>& arr)
	{
		if (nullptr == root)
		{
			return;
		}
		dfs(root->left, arr);
		arr.push_back(root->val);
		dfs(root->right, arr);
	}
};

int main() {
	vector<int> a = { 1,2,NULL,3 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s;
	int res = s.getMinimumDifference(root);
	cout << res << endl;
}