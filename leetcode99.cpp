/*
Leetcode 99
恢复二叉搜索树
created by wanghaozhi
*/
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
	if (x[start] == NULL) { return NULL;}
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
private:
	TreeNode* first = nullptr;
	TreeNode* second = nullptr;
	TreeNode* pre = new TreeNode(INT_MIN);
	void helper(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		helper(root->left);
		if (first == nullptr&&pre->val>root->val) {
			first = pre;
		}
		if (first != nullptr&&pre->val>root->val) {
			second = root;
		}
		pre = root;
		helper(root->right);
	}
public:
	void recoverTree(TreeNode* root) {
		helper(root);
		int tmp = first->val;
		first->val = second->val;
		second->val = tmp;
	}

};


int main() {
	// vector形式转化为树
	vector<int> a = { 1,3,NULL,NULL,2};
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);

	// 纠正二叉搜索树的两个错误节点
	Solution s1;
	s1.recoverTree(root1);
	preorderTraverse(root1);
}