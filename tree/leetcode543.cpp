/*
Leetcode 543
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
	int ans;
	int depth(TreeNode* rt) {
		if (rt == NULL) return 0; // 访问到空节点了，返回0
		int L = depth(rt->left); // 左儿子为根的子树的深度
		int R = depth(rt->right); // 右儿子为根的子树的深度
		ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
		return max(L, R) + 1; // 返回该节点为根的子树的深度
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		ans = 1;
		depth(root);
		return ans - 1;
	}
};

int main() {
	vector<int> a = { 1,2,3,4,5 };
	TreeNode* root = insert_tree(a, a.size(), 0);
	
	Solution s;
	int res = s.diameterOfBinaryTree(root);
	cout << res << endl;
}
