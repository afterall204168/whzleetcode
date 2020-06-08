/*
Leetcode 103
�������ľ���β������
created by wanghaozhi
*/
#include<iostream>
#include<vector>
#include<queue>
#include<list>

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector <vector <int>> ret;
		if (!root) return ret;

		queue <TreeNode*> q;
		q.push(root);
		int count = 0;

		while (!q.empty()) {
			int currentLevelSize = q.size();
			ret.push_back(vector <int>());
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();            // ���ض����еĶ�ͷ����������ͷ��
				ret.back().push_back(node->val);           // ��node->val �ͽ�vector���һ��Ԫ���С�
				
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}

		return ret;
	}
};

class Solution1 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root)return ans;
		list<TreeNode*> q;
		q.push_back(root);
		bool direction = true;             // �����������

		while (!q.empty()) {
			int size = q.size();
			vector<int> tmp;
			if (direction) {

				for (int i = 0; i<size; i++) {
					TreeNode* node = q.front();                 //  ȡ�б��е�һ��Ԫ��
					q.pop_front();                              //  �����б��е�һ��Ԫ��
					tmp.push_back(node->val);
					if (node->left)q.push_back(node->left);       // ÿ�����б�����������
					if (node->right)q.push_back(node->right);
				}
			}
			else {
				for (int i = size - 1; i >= 0; i--) {
					TreeNode* node = q.back();                   // ���б�β��ȡ����
					q.pop_back();
					tmp.push_back(node->val);
					if (node->right)q.push_front(node->right);   // ÿ�����б�ǰ���������
					if (node->left)q.push_front(node->left);
				}
			}
			ans.push_back(tmp);
			direction = !direction;
		}
		return ans;
	}
};


int main() {
	// vector��ʽת��Ϊ��
	vector<int> a = { 3,9,20,NULL,NULL,15,7 };
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);

	// �������
	Solution1 s1;
	vector<vector<int>> res = s1.zigzagLevelOrder(root1);
	preorderTraverse(root1);

	// ��ӡ vector
	int l1 = res.size();
	for (int i = 0; i < l1; i++) {
		int l2 = res[i].size();
		cout << '[';
		for (int j = 0; j < l2; j++) {
			cout << res[i][j] << " ";
		}
		cout << ']' << endl;
	}
}