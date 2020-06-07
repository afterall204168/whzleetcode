/*
leetcode 105
��ǰ��������������й��������

�ݹ��ѭ���ķ�����ѭ���ķ�����Ϊ���ӡ�

created By wanghaozhi

*/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
	unordered_map<int, int> index;

public:
	TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
		if (preorder_left > preorder_right) {
			return nullptr;
		}

		// ǰ������еĵ�һ���ڵ���Ǹ��ڵ�
		int preorder_root = preorder_left;
		// ����������ж�λ���ڵ�
		int inorder_root = index[preorder[preorder_root]];

		// �ȰѸ��ڵ㽨������
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		// �õ��������еĽڵ���Ŀ
		int size_left_subtree = inorder_root - inorder_left;
		// �ݹ�ع����������������ӵ����ڵ�
		// ��������С��� ��߽�+1 ��ʼ�� size_left_subtree����Ԫ�ؾͶ�Ӧ����������С��� ��߽� ��ʼ�� ���ڵ㶨λ-1����Ԫ��
		root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
		// �ݹ�ع����������������ӵ����ڵ�
		// ��������С��� ��߽�+1+�������ڵ���Ŀ ��ʼ�� �ұ߽硹��Ԫ�ؾͶ�Ӧ����������С��� ���ڵ㶨λ+1 �� �ұ߽硹��Ԫ��
		root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		// �����ϣӳ�䣬�������ǿ��ٶ�λ���ڵ�
		for (int i = 0; i < n; ++i) {
			index[inorder[i]] = i;
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};

class Solution1 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!preorder.size()) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[0]);
		stack<TreeNode*> stk;
		stk.push(root);
		int inorderIndex = 0;
		for (int i = 1; i < preorder.size(); ++i) {
			int preorderVal = preorder[i];
			TreeNode* node = stk.top();                                // ���stackջ��ջ��Ԫ��
			if (node->val != inorder[inorderIndex]) {
				node->left = new TreeNode(preorderVal);
				stk.push(node->left);
			}
			else {
				while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
					node = stk.top();
					stk.pop();
					++inorderIndex;
				}
				node->right = new TreeNode(preorderVal);
				stk.push(node->right);
			}
		}
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
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };

	Solution1 s1;
	TreeNode* root2 = s1.buildTree(preorder, inorder);
	preorderTraverse(root2);
}