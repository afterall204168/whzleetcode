#include<iostream>
#include<vector>
#include<stack>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
public:
	stack<TreeNode*> st;           // ���ڵ�ջ���Ƚ����
	TreeNode *p, *pre;
	//������
	BSTIterator(TreeNode* root) {
		p = root;
		TreeNode* dummy = new TreeNode(0);
		pre = dummy;
		while (p || !st.empty()) {         
			if (p) {
				st.push(p);                  
				p = p->left;                  // �ȶ�����������������ջ����
			}
			else {
				p = st.top();                
				pre->right = p;
				pre = p;
				p = p->right;
				st.pop();
			}
		}
		pre->right = NULL;
		p = dummy->right;                    // ���
	}

	/** @return the next smallest number */
	int next() {
		int res = p->val;
		p = p->right;
		return res;
	} 

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (p) {
			return true;
		}
		return false;
	}
};


TreeNode *insert_tree(vector<int>& x, int n, int start) {
	if (x[start] == NULL) { return NULL; }
	TreeNode* root = new TreeNode(0);
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
	vector<int> re = { 7, 3, 15, NULL, NULL, 9, 20 };
	TreeNode* root = insert_tree(re, re.size(), 0);
	BSTIterator iterator(root);
	cout<<iterator.next()<<endl;    // ���� 3
	cout<<iterator.next()<<endl;    // ���� 7
	cout<<iterator.hasNext()<<endl; // ���� true
	cout<<iterator.next()<<endl;    // ���� 9
	cout<<iterator.hasNext()<<endl; // ���� true
	cout<<iterator.next()<<endl;    // ���� 15
	cout<<iterator.hasNext()<<endl; // ���� true
	cout<<iterator.next()<<endl;    // ���� 20
	cout<<iterator.hasNext()<<endl; // ���� false
}