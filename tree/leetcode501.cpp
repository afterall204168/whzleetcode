#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> ret;//保存结果
	vector<int> vec;//保存中序遍历树的结果
	vector<int> findMode(TreeNode* root) {
		int cur = 1;//当前结点值出现的次数
		int max = 1;//出现频率最高的次数
		if (!root)
			return ret;
		if (!root->left && !root->right)
		{
			ret.push_back(root->val);
			return ret;
		}
		inOrder(root);
		ret.push_back(vec[0]);//初始化ret
		for (int i = 1; i<vec.size(); i++)
		{
			if (vec[i] == vec[i - 1])
				++cur;
			else
				cur = 1;
			if (cur == max)
				ret.push_back(vec[i]);
			if (cur > max)
			{
				max = cur;
				ret.clear();
				ret.push_back(vec[i]);
			}
		}
		return ret;
	}
	//中序遍历
	void inOrder(TreeNode* root)
	{
		if (root)
		{
			inOrder(root->left);
			vec.push_back(root->val);
			inOrder(root->right);
		}
	}
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

int main() {
	vector<int> a = { 1,NULL,2,2 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s1;
	vector<int> res = s1.findMode(root);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
}