/*
Leetcode 508
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
public:
	int sum = 0;
	unordered_map<int, int> map;
	void dfs(TreeNode* root) {
		if (root != NULL) {
			visit(root);
			map[sum]++;
			sum = 0;
			dfs(root->left);
			dfs(root->right);
		}
	}
	void visit(TreeNode* root) {
		if (root != NULL) {
			sum += root->val;
			visit(root->left);
			visit(root->right);
		}
	}
	static bool cmp(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {
		dfs(root);
		vector<pair<int, int>> res;
		vector<int> ans;
		for (unordered_map<int, int>::iterator p = map.begin(); p != map.end(); p++)
			res.push_back(make_pair(p->first, p->second));
		sort(res.begin(), res.end(), cmp);
		if (res.size() == 1)
			ans.push_back(res[0].first);
		if (res.size() == 0)
			return ans;
		for (int i = 0; i < res.size() - 1; i++) {
			ans.push_back(res[i].first);
			if (res[i + 1].second != res[i].second)
				break;
			if (i + 1 == res.size() - 1)
				ans.push_back(res[i + 1].first);
		}
		return ans;
	}
};

int main() {
	vector<int> a = { 5,2,-5 };
	TreeNode* root = insert_tree(a, a.size(), 0);

	Solution s1;
	vector<int> res = s1.findFrequentTreeSum(root);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}