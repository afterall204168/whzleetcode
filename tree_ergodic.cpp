/*
二叉树的前序、中序、后序遍历方法
Created by wanghaozhi
*/

#include<iostream>
#include<vector>
#include<stack>

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

// 递归遍历
class recursion1
{
public:
	vector<int> results;

	// 二叉树的前序遍历
	vector<int> preorder(TreeNode* root) {
		preordertraverse(root);
		return results;
	}

	void preordertraverse(TreeNode* node) {
		if (node == NULL) return;
		results.push_back(node->val);
		preordertraverse(node->left);
		preordertraverse(node->right);
	}


	// 二叉树的中序遍历
	vector<int> inorder(TreeNode* root) {
		inordertraverse(root);
		return results;
	}

	void inordertraverse(TreeNode* node) {
		if (node == NULL) return;
		inordertraverse(node->left);
		results.push_back(node->val);
		inordertraverse(node->right);
	}

	//二叉树的后序遍历
	vector<int> postorder(TreeNode* root) {
		postordertraverse(root);
		return results;
	}

	void postordertraverse(TreeNode* node) {
		if (node == NULL) return;
		postordertraverse(node->left);
		postordertraverse(node->right);
		results.push_back(node->val);
	}
};


// 循环遍历
class iteration1 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) return ans;
		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* top = s.top();
			s.pop();
			ans.emplace_back(top->val);
			if (top->right) s.push(top->right);
			if (top->left) s.push(top->left);
		}
		return ans;
	}

	vector<int> results;
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		//s.push(root);
		TreeNode* cur = root;
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				cur = cur->left;
			}
			TreeNode* top = s.top();
			results.push_back(top->val);
			s.pop();
			if (top->right)cur = top->right;
		}

		return results;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) return ans;
		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* top = s.top();
			s.pop();
			ans.emplace_back(top->val);
			if (top->left) s.push(top->left);
			if (top->right) s.push(top->right);

		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};


int main() {
	
	vector<int> a = { 3,9,20,NULL,NULL,15,7 };
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);
	cout << endl;

	recursion1 r1;
	vector<int> res = r1.postorder(root1);
	int l = res.size();
	for (int i = 0; i < l; i++) {
		cout << res[i] << endl;

	}
}