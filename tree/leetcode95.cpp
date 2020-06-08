/*
Leetcode 95
Tree theme
binary search trees
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//������
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return{};
		return helper(1, n);
	}
	vector<TreeNode*> helper(int start, int end) {
		if (start > end) return{ nullptr };
		vector<TreeNode*> res;
		for (int i = start; i <= end; i++) {
			auto left = helper(start, i - 1); 
			auto right = helper(i + 1, end);
			for (auto a : left) {
				for (auto b : right) {
					TreeNode* node = new TreeNode(i);
					node->left = a;
					node->right = b;
					res.push_back(node);
				}
			}
		}
		return res;
	}
};


class Solution2 {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> que;
		vector<int> vec;
		que.push(root);//�Ƚ������������������
		while (!que.empty()) //�����зǿս���ѭ��
		{
			TreeNode* p;
			p = que.front();//�ȶ�ȡ���е���Ԫ��
			que.pop();//�������е���Ԫ��
			if (p == NULL)
				continue;//����Ԫ�ش���vec�����ڶ����д���ſ�ָ�룬��Ȼ����ѭ��������ʱp��ֵΪNULL����ִ������Ĳ���������ѭ������
			que.push(p->left);
			que.push(p->right);
			vec.push_back(p->val);
		}
		return vec;

	}
};

int main() {
	Solution s1;
	vector<TreeNode*> t = s1.generateTrees(3);
	// cout<<t;
	Solution2 s2;
	for (int i = 0; i < t.size(); i++) {
		vector<int> l = s2.PrintFromTopToBottom(t[i]);
		for (int j = 0; j < l.size(); j++) {
			cout << l[j];
		}
		cout << endl;
	}
}