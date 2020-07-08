#include<iostream>
#include<vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)   return NULL;
		if (key < root->val) { // 找到key所在的位置
			root->left = deleteNode(root->left, key);
			return root;
		}
		if (key > root->val) { // 找到key所在的位置
			root->right = deleteNode(root->right, key);
			return root;
		}
		// 当key == root -> val， 即找到目标点时
		//当目标点只有一边子树时
		if (!root->left) { // 若没有左子树，删除目标点，右子树接上
			TreeNode* temp = root->right;
			delete(root);
			return temp;
		}
		if (!root->right) { // 若没有右子树，删除目标点，左子树接上
			TreeNode* temp = root->left;
			delete(root);
			return temp;
		}
		//当目标点左右都有子树时
		TreeNode* temp = root->right; // 找到右子树中最小的值，即进入右子树后一直向左遍历
		while (temp->left) temp = temp->left;
		swap(root->val, temp->val); // 交换值
		root->right = deleteNode(root->right, key); // 进入遍历，删除key
		return root;
	}
};


void preorderTraverse(TreeNode *T) {
	if (T) {
		cout << T->val << " ";
		preorderTraverse(T->left);
		preorderTraverse(T->right);
	}
}

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

int main() {
	vector<int> a = { 5,3,6,2,4,NULL,7 };
	TreeNode* root = insert_tree(a, a.size(), 0);
	preorderTraverse(root);
	cout << endl;

	Solution s1;
	TreeNode* res = s1.deleteNode(root, 3);
	preorderTraverse(res);
}
