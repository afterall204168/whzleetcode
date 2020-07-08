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
		if (key < root->val) { // �ҵ�key���ڵ�λ��
			root->left = deleteNode(root->left, key);
			return root;
		}
		if (key > root->val) { // �ҵ�key���ڵ�λ��
			root->right = deleteNode(root->right, key);
			return root;
		}
		// ��key == root -> val�� ���ҵ�Ŀ���ʱ
		//��Ŀ���ֻ��һ������ʱ
		if (!root->left) { // ��û����������ɾ��Ŀ��㣬����������
			TreeNode* temp = root->right;
			delete(root);
			return temp;
		}
		if (!root->right) { // ��û����������ɾ��Ŀ��㣬����������
			TreeNode* temp = root->left;
			delete(root);
			return temp;
		}
		//��Ŀ������Ҷ�������ʱ
		TreeNode* temp = root->right; // �ҵ�����������С��ֵ����������������һֱ�������
		while (temp->left) temp = temp->left;
		swap(root->val, temp->val); // ����ֵ
		root->right = deleteNode(root->right, key); // ���������ɾ��key
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
