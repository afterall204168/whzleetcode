/*
Leetcode 572
created by wanghaozhi
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

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


// DFS暴力解法
class Solution1 {
public:
	bool check(TreeNode *o, TreeNode *t) {
		if (!o && !t) return true;
		if ((o && !t) || (!o && t) || (o->val != t->val)) return false;
		return check(o->left, t->left) && check(o->right, t->right);
	}

	bool dfs(TreeNode *o, TreeNode *t) {
		if (!o) return false;
		return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
	}

	bool isSubtree(TreeNode *s, TreeNode *t) {
		return dfs(s, t);
	}
};


// DFS 序列上做串匹配
class Solution2 {
public:
	vector <int> sOrder, tOrder;
	int maxElement, lNull, rNull;

	void getMaxElement(TreeNode *o) {
		if (!o) return;
		maxElement = max(maxElement, o->val);
		getMaxElement(o->left);
		getMaxElement(o->right);
	}

	void getDfsOrder(TreeNode *o, vector <int> &tar) {
		if (!o) return;
		tar.push_back(o->val);
		if (o->left) getDfsOrder(o->left, tar);
		else tar.push_back(lNull);
		if (o->right) getDfsOrder(o->right, tar);
		else tar.push_back(rNull);
	}

	bool kmp() {
		int sLen = sOrder.size(), tLen = tOrder.size();
		vector <int> fail(tOrder.size(), -1);
		for (int i = 1, j = -1; i < tLen; ++i) {
			while (j != -1 && tOrder[i] != tOrder[j + 1]) j = fail[j];
			if (tOrder[i] == tOrder[j + 1]) ++j;
			fail[i] = j;
		}
		for (int i = 0, j = -1; i < sLen; ++i) {
			while (j != -1 && sOrder[i] != tOrder[j + 1]) j = fail[j];
			if (sOrder[i] == tOrder[j + 1]) ++j;
			if (j == tLen - 1) return true;
		}
		return false;
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		maxElement = INT_MIN;
		getMaxElement(s);
		getMaxElement(t);
		lNull = maxElement + 1;
		rNull = maxElement + 2;

		getDfsOrder(s, sOrder);
		getDfsOrder(t, tOrder);

		return kmp();
	}
};


// 树哈希
class Solution3 {
public:
	static constexpr int MAX_N = 1000 + 5;
	static constexpr int MOD = int(1E9) + 7;

	bool vis[MAX_N];
	int p[MAX_N], tot;
	void getPrime() {
		vis[0] = vis[1] = 1; tot = 0;
		for (int i = 2; i < MAX_N; ++i) {
			if (!vis[i]) p[++tot] = i;
			for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
				vis[i * p[j]] = 1;
				if (i % p[j] == 0) break;
			}
		}
	}

	struct Status {
		int f, s; // f 为哈希值 | s 为子树大小
		Status(int f_ = 0, int s_ = 0)
			: f(f_), s(s_) {}
	};

	unordered_map <TreeNode *, Status> hS, hT;

	void dfs(TreeNode *o, unordered_map <TreeNode *, Status> &h) {
		h[o] = Status(o->val, 1);
		if (!o->left && !o->right) return;
		if (o->left) {
			dfs(o->left, h);
			h[o].s += h[o->left].s;
			h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
		}
		if (o->right) {
			dfs(o->right, h);
			h[o].s += h[o->right].s;
			h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
		}
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		getPrime();
		dfs(s, hS);
		dfs(t, hT);

		int tHash = hT[t].f;
		for (const auto [&k, v] : hS) {
			if (v.f == tHash) {
				return true;
			}
		}

		return false;
	}
};


int main() {
	vector<int> a1 = { 3,4,5,1,2 };
	vector<int> a2 = { 4,1,2 };
	TreeNode* root1 = insert_tree(a1, a1.size(), 0);
	TreeNode* root2 = insert_tree(a2, a2.size(), 0);

	Solution1 s1;
	bool res = s1.isSubtree(root1, root2);
	cout << res << endl;
}
