// Leetcode 116
// 给定一个完美二叉树，让每个节点得next指针都指向下一个节点
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


// 利用队列的性质，使用一个flag节点来记录每一层树的结束。
class Solution1 {
public:
	Node* connect(Node* root) {
		if (!root)   return root;
		queue<Node*> q;
		Node* flag = new Node;    // 用于记录每层树的结束。
		Node* last = new Node;    // 用于记录上一个节点，将上一个节点的next连接当前节点。

		q.push(root); // 根推入队列
		q.push(flag); // 第一层结束，用flag标记位置
		while (q.size() >= 2) { //队列内到最后存在一个flag，因此 >2
			Node* now = q.front(); // 取出当前节点。
			q.pop();
			if (now == flag) { // 如果到达每层末尾，last清空，再次推入flag
							   //last -> next = NULL;
				last = NULL;
				q.push(flag);
				continue;
			}
			if (last == NULL) { // 说明是新的一层
				last = now;
			}
			else { // 否则一定存在last节点
				last->next = now;
				last = now; // 更新last节点
			}
			if (now->left) { //压入新的节点。
				q.push(now->left);
				q.push(now->right);
			}
		}
		return root;
	}
};


// 迭代法，使用一个leftmost来记录最左侧节点，如果节点没有next节点，则更新当前节点为当前层的最左节点的左节点。
class Solution2 {
public:
	Node* connect(Node* root) {
		if (!root)   return NULL;
		Node* now = new Node;
		Node* leftmost = new Node;
		now = root;
		leftmost = root;
		while (now->left) {
			now->left->next = now->right;           // 当前节点的左节点的next指向右节点
			if (now->next) {                        //将当前节点的右节点的next指向 下一节点的左节点
				now->right->next = now->next->left;
				now = now->next;                    // 更新当前节点
			}
			else {
				now = leftmost->left; // 若当前节点没有next，更新当前节点为当前层的最左节点的左节点。
				leftmost = now;
			}
		}
		return root;
	}
};


// 递归算法，这个想法有点666，
class Solution3 {
public:
	Node* connect(Node* root) {
		if (!root || !root->left)   return root; 
		root->left->next = root->right;    
		Node* now = new Node;
		now = root->left;
		while (now->left) {
			now->right->next = now->next->left;      // 这个循环的目的是将每一个左子树的右侧节点和右子树的左侧节点相连
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

