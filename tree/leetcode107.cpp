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

// 利用给定的vector构建二叉树
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

// 打印树节点
void preorderTraverse(TreeNode *T) {
	if (T) {
		cout << T->val << " ";
		preorderTraverse(T->left);
		preorderTraverse(T->right);
	}
}

// 递归方法层序遍历
class Solution1 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		int n = getDep(root);
		vector<vector<int>> ans(n, vector<int>());   // 定义一个长度为n的双层空vector
		dfs(root, 0, ans, n - 1);                    // 深度优先搜索
		return ans;                                
	}

	// DFS
	void dfs(TreeNode *root, int depth, vector<vector<int>>& ans, int n) {
		if (root == NULL) return;
		ans[n - depth].push_back(root->val);       // 倒着装 n - depth
		dfs(root->left, depth + 1, ans, n);
		dfs(root->right, depth + 1, ans, n);
	}

	// 递归方法求树的深度
	int getDep(TreeNode *root) { 
		if (root == NULL) return 0;
		return max(getDep(root->left), getDep(root->right)) + 1;   
	}
};


// 利用队列，翻转vector
class Solution2 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector <vector <int>> ret;
		if (!root) return ret;

		queue <TreeNode*> q;
		// 入队
		q.push(root);
		while (!q.empty()) {
			int currentLevelSize = q.size();   // 求队列长度 
			ret.push_back(vector <int>());
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();                // 将队首元素赋值给auto变量，并弹出队首元素
				ret.back().push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}

		// 翻转vector
		int l = ret.size();
		for (int i = 0; i<l / 2; i++) {
			vector<int> temp = ret[l - i - 1];
			ret[l - i - 1] = ret[i];
			ret[i] = temp;
		}

		return ret;
	}
};



int main() {
	vector<int> a = { 3,9,20,NULL,NULL,15,7 };
	TreeNode* root = insert_tree(a, a.size(), 0);



	Solution1 s1;
	Solution2 s2;
	vector<vector<int>> ans = s1.levelOrderBottom(root);
	int m = ans.size();
	for (int i = 0; i < m; i++) {
		cout << '[';
		int n = ans[i].size();
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << ']' << endl;
	}
}