/*
Leetcode 110
二叉平衡树
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

// 比较每棵树的深度，会存在重复计算的情况
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root){return true;}
        // int left = root_depth(root->left);
        // int right = root_depth(root->right);
        // int a = abs(left-right);
		// 检查当前节点和左右两个子树节点是否满足平衡树的条件
        return abs(root_depth(root->left)-root_depth(root->right))<2&&
        isBalanced(root->left)&&
        isBalanced(root->right);
    }

    int root_depth(TreeNode* root){
        if(!root){return 0;}
        return max(root_depth(root->left),root_depth(root->right))+1;
    }
};

// 
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        return box(root) != -1;
    }
    int box(TreeNode* root){
        if(!root)   return 0;
        int l = box(root -> left);
        if(l == - 1)    return -1;
        int r = box(root -> right);
        if(r == - 1)    return -1;
        return abs(l - r) < 2 ? max(l, r) + 1 : - 1;
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
	// vector形式转化为树
	vector<int> a = { 1,NULL,2,NULL,15 };
	int n = a.size();
	TreeNode* root1 = insert_tree(a, n, 0);
	preorderTraverse(root1);

	// 层序遍历
	Solution s1;
	bool res = s1.isBalanced(root1);
}
