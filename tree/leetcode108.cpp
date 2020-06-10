#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int l = nums.size();
		return helper(nums, 0, l - 1);
	}

	TreeNode* helper(vector<int>& nums, int left, int right) {
		if (left>right) { return NULL; }

		int p = (left + right) / 2;
		TreeNode* root = new TreeNode(nums[p]);

		root->left = helper(nums, left, p - 1);
		root->right = helper(nums, p + 1, right);
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


int main() {
	vector<int> a = { -10,-3,0,5,9 };
	Solution s;
	TreeNode* root = s.sortedArrayToBST(a);
	preorderTraverse(root);
}