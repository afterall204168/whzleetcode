// Leetcode173
// 创建一个迭代器
// created by wanghaozhi 
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//利用stack的特性，，先对某一个节点的所有节点的左节点进行入栈
class BSTIterator {
	stack<TreeNode*> st;
public:

	BSTIterator(TreeNode* root) {
		ldfs(root);
	}

	void ldfs(TreeNode* root) {
		while (root) {
			st.emplace(root);
			root = root->left;
		}
	}

	int next() {
		TreeNode* root = st.top(); st.pop();
		ldfs(root->right);             // 遍历当前节点的右节点的所有左节点
		return root->val;
	}

	bool hasNext() {
		return !st.empty();
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
	vector<int> re = { 7, 3, 15, NULL, NULL, 9, 20 };
	TreeNode* root = insert_tree(re, re.size(), 0);
	BSTIterator iterator(root);
	cout << iterator.next() << endl;    // 返回 3
	cout << iterator.next() << endl;    // 返回 7
	cout << iterator.hasNext() << endl; // 返回 true
	cout << iterator.next() << endl;    // 返回 9
	cout << iterator.hasNext() << endl; // 返回 true
	cout << iterator.next() << endl;    // 返回 15
	cout << iterator.hasNext() << endl; // 返回 true
	cout << iterator.next() << endl;    // 返回 20
	cout << iterator.hasNext() << endl; // 返回 false
}