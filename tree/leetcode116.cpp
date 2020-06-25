// Leetcode 116
// ����һ����������������ÿ���ڵ��nextָ�붼ָ����һ���ڵ�
// created by wanghaozhi


#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

Node *insert_tree(vector<int>& x, int n, int start) {
	if (x[start] == NULL) { return NULL; }
	Node* root = new Node;
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


void preorderTraverse(Node *T) {
	if (T) {
		cout << T->val << " ";
		preorderTraverse(T->left);
		preorderTraverse(T->right);
	}
}

void inorderTraverse(Node *T) {
	if (T) {
		//cout << T->val << " ";
		preorderTraverse(T->left);
		cout << T->val << " ";
		preorderTraverse(T->right);
	}
}

void postorderTraverse(Node *T) {
	if (T) {
		//cout << T->val << " ";
		preorderTraverse(T->left);
		preorderTraverse(T->right);
		cout << T->val << " ";
	}
}


// ���ö��е����ʣ�ʹ��һ��flag�ڵ�����¼ÿһ�����Ľ�����
class Solution1 {
public:
	Node* connect(Node* root) {
		if (!root)   return root;
		queue<Node*> q;
		Node* flag = new Node;    // ���ڼ�¼ÿ�����Ľ�����
		Node* last = new Node;    // ���ڼ�¼��һ���ڵ㣬����һ���ڵ��next���ӵ�ǰ�ڵ㡣

		q.push(root); // ���������
		q.push(flag); // ��һ���������flag���λ��
		while (q.size() >= 2) { //�����ڵ�������һ��flag����� >2
			Node* now = q.front(); // ȡ����ǰ�ڵ㡣
			q.pop();
			if (now == flag) { // �������ÿ��ĩβ��last��գ��ٴ�����flag
							   //last -> next = NULL;
				last = NULL;
				q.push(flag);
				continue;
			}
			if (last == NULL) { // ˵�����µ�һ��
				last = now;
			}
			else { // ����һ������last�ڵ�
				last->next = now;
				last = now; // ����last�ڵ�
			}
			if (now->left) { //ѹ���µĽڵ㡣
				q.push(now->left);
				q.push(now->right);
			}
		}
		return root;
	}
};


// ��������ʹ��һ��leftmost����¼�����ڵ㣬����ڵ�û��next�ڵ㣬����µ�ǰ�ڵ�Ϊ��ǰ�������ڵ����ڵ㡣
class Solution2 {
public:
	Node* connect(Node* root) {
		if (!root)   return NULL;
		Node* now = new Node;
		Node* leftmost = new Node;
		now = root;
		leftmost = root;
		while (now->left) {
			now->left->next = now->right;           // ��ǰ�ڵ����ڵ��nextָ���ҽڵ�
			if (now->next) {                        //����ǰ�ڵ���ҽڵ��nextָ�� ��һ�ڵ����ڵ�
				now->right->next = now->next->left;
				now = now->next;                    // ���µ�ǰ�ڵ�
			}
			else {
				now = leftmost->left; // ����ǰ�ڵ�û��next�����µ�ǰ�ڵ�Ϊ��ǰ�������ڵ����ڵ㡣
				leftmost = now;
			}
		}
		return root;
	}
};


// �ݹ��㷨������뷨�е�666��
class Solution3 {
public:
	Node* connect(Node* root) {
		if (!root || !root->left)   return root; 
		root->left->next = root->right;    
		Node* now = new Node;
		now = root->left;
		while (now->left) {
			now->right->next = now->next->left;      // ���ѭ����Ŀ���ǽ�ÿһ�����������Ҳ�ڵ�������������ڵ�����
			now = now->right;
		}
		root->left = connect(root->left);
		root->right = connect(root->right);
		return root;
	}
};


int main() {
	Solution3 s3;
	vector<int> a = { 1,2,3,4,5,6,7 };
	int n = a.size();
	Node* root = insert_tree(a, n, 0);
	/*
	preorderTraverse(root);
	cout << endl;
	inorderTraverse(root);
	cout << endl;
	postorderTraverse(root);
	*/
	Node* root1 = s3.connect(root);

}

