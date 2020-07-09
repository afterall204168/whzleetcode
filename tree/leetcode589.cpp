#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution1{
public:
	vector<int> res;
	vector<int> preorder(Node* root) {
		if (!root)   return res;
		res.push_back(root->val);
		for (auto i : root->children) {
			preorder(i);
		}
		return res;
	}
};

class Solution2 {
public:
	vector<int> preorder(Node* root) {
		vector<int> res;
		if (!root)   return res;
		stack<Node*> stk;
		stk.push(root);
		while (!stk.empty()) {
			Node* tmp = stk.top();
			stk.pop();
			res.push_back(tmp->val);
			for (int i = tmp->children.size() - 1; i >= 0; --i) {
				stk.push(tmp->children[i]);
			}
		}
		return res;
	}
};


// N叉树的后序遍历，迭代方法
class Solution3 {
public:
	vector<int> postorder(Node* root) {
		vector<int> a;
		if (!root) return a;

		stack <Node*> stk;
		stk.push(root);

		Node* top;
		vector <Node*>::iterator it;
		while (!stk.empty()) {
			top = stk.top();
			a.push_back(top->val);
			stk.pop();
			for (it = top->children.begin(); it != top->children.end(); it++) {
				stk.push(*it);
			}
		}
		reverse(a.begin(), a.end());           // 翻转vector
		return a;
	}
};
