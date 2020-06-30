// leetcode230
// 寻找二叉搜索树中的第k小的节点
// created by wanghaozhi

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归的思想很简单，寻找第k个最小值
class Solution {
public:
	int n = 0;
	int res;
	int kthSmallest(TreeNode* root, int k) {
		//递归
		dfs(root, k);
		return res;
	}

	void  dfs(TreeNode* root, int k) {
		if (!root)return;
		dfs(root->left, k);
		n++;
		if (n == k) res = root->val;
		dfs(root->right, k);
	}
};

// 还没细整理，我懒
class Solution2 {
private:
	unordered_map<TreeNode*, int> leftchilds;
	unordered_map<TreeNode*, int> rightchilds;
public:
	int myKthSmallest(TreeNode* root, int k) {
		TreeNode* cur = root;
		int rank = leftchilds[cur] + 1;
		while (k != rank) {
			if (k < rank) {
				cur = cur->left;
				rank -= rightchilds[cur] + 1;
			}
			else {
				cur = cur->right;
				rank += leftchilds[cur] + 1;
			}
		}
		return cur->val;
	}

	int memoTree(TreeNode* root) {
		if (!root) {
			return 0;
		}
		leftchilds[root] = memoTree(root->left);
		rightchilds[root] = memoTree(root->right);
		return leftchilds[root] + rightchilds[root] + 1;
	}

	int kthSmallest(TreeNode* root, int k) {
		if (!root) {
			return 0;
		}
		memoTree(root);
		return myKthSmallest(root, k);
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
	vector<int> re = { 1, 2, 3, 4, 5, 6 };
	TreeNode* root = insert_tree(re, re.size(), 0);

	Solution s1;
	int res = s1.kthSmallest(root, 3);
	cout << res << endl;
}