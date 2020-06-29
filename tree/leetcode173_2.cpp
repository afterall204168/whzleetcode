// Leetcode173
// ����һ��������
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

//����stack�����ԣ����ȶ�ĳһ���ڵ�����нڵ����ڵ������ջ
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
		ldfs(root->right);             // ������ǰ�ڵ���ҽڵ��������ڵ�
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
	cout << iterator.next() << endl;    // ���� 3
	cout << iterator.next() << endl;    // ���� 7
	cout << iterator.hasNext() << endl; // ���� true
	cout << iterator.next() << endl;    // ���� 9
	cout << iterator.hasNext() << endl; // ���� true
	cout << iterator.next() << endl;    // ���� 15
	cout << iterator.hasNext() << endl; // ���� true
	cout << iterator.next() << endl;    // ���� 20
	cout << iterator.hasNext() << endl; // ���� false
}