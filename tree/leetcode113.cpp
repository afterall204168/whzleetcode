/*
Leetcode 113
二叉树的层序遍历, DFS，递归
created by wanghaozhi
*/
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
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root){helper(root, sum);}
        return res;
    }

    void helper(TreeNode* root, int sum){
        int sum1 = sum - root->val;
        temp.push_back(root->val);
        //终止条件
        if(sum1==0 && !root->left && !root->right){
            res.push_back(temp);
        }
        if(root->left){helper(root->left, sum1);}
        if(root->right){helper(root->right, sum1);}
        temp.pop_back();      // 回溯
    }
};


int main() {
	// vector形式转化为树
	vector<int> a = { 5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);
	
	int sum =22;  // 目标和
	
	// 递归
	Solution s1;
	vector<vector<int>> res = s1.pathSum(root1, sum);
	// preorderTraverse(root1);
	
	// 打印 vector
	int l1 = res.size();
	for (int i = 0; i < l1; i++) {
		int l2 = res[i].size();
		cout << '[';
		for (int j = 0; j < l2; j++) {
			cout << res[i][j]<<" ";
		}
		cout << ']' << endl;
	}
}





