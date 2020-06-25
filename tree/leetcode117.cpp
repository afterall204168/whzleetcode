// Leetcode 117
// 给定一个二叉树，让每个节点得next指针都指向下一个节点
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

class Solution1 {
public:

	//1、 迭代法，利用队列性质，对每一层root来说，出队的节点的next节点连在队首节点、
	// 每次都要检查节点的左节点和右节点是否存在，存在则push到队列
	Node* connect(Node* root) {

		if (root == nullptr)
		{
			return root;
		}

		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();       //当前层size
			for (int i = 0; i < size; ++i)
			{
				Node* node = q.front();
				q.pop();
				if (i < size - 1)
				{
					node->next = q.front(); //设置next指针
				}
				if (node->left)
				{
					q.push(node->left);
				}

				if (node->right)
				{
					q.push(node->right);
				}
			}
		}

		return root;
	}

};


// 纯迭代方法。
class Solution2 {
public:
	//2、
	Node* connect(Node* root) {

		if (root == nullptr)
		{
			return root;
		}

		Node* level_first = root; //当前层第一个节点
		Node* next_level_first = nullptr; //下一层的第一节点

		while (level_first)
		{
			next_level_first = nullptr;

			Node* cur = level_first; //当前层节点
			Node* node = nullptr; //下一层待连接的节点

			while (cur)
			{
				if (cur->left)
				{
					if (next_level_first == nullptr)
					{
						next_level_first = cur->left;
					}

					if (node == nullptr)
					{
						node = cur->left;
					}
					else if (node->next == nullptr)
					{
						node->next = cur->left;
						node = node->next;
					}
				}

				if (cur->right)
				{
					if (next_level_first == nullptr)
					{
						next_level_first = cur->right;
					}

					if (node == nullptr)
					{
						node = cur->right;
					}
					else if (node->next == nullptr)
					{
						node->next = cur->right;
						node = node->next;
					}
				}

				cur = cur->next;
			}

			level_first = next_level_first;
		}

		return root;
	}

};

int main() {
	Solution2 s1;
	vector<int> a = { 1,2,3,4,5,NULL,7 };
	int n = a.size();
	Node* root = insert_tree(a, n, 0);
	/*
	preorderTraverse(root);
	cout << endl;
	inorderTraverse(root);
	cout << endl;
	postorderTraverse(root);
	*/
	Node* root1 = s1.connect(root);

}