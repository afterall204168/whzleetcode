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
		if (rt == NULL) return 0; // ���ʵ��սڵ��ˣ�����0
		int L = depth(rt->left); // �����Ϊ�������������
		int R = depth(rt->right); // �Ҷ���Ϊ�������������
		ans = max(ans, L + R + 1); // ����d_node��L+R+1 ������ans
		return max(L, R) + 1; // ���ظýڵ�Ϊ�������������
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
