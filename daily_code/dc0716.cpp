// daily code 0716
// leetcode 785


#include<iostream>
#include<vector>
using namespace std;



class Solution {
private:
	static constexpr int UNCOLORED = 0;
	static constexpr int RED = 1;
	static constexpr int GREEN = 2;
	vector<int> color;
	bool valid;

public:
	void dfs(int node, int c, const vector<vector<int>>& graph) {
		color[node] = c;
		int cNei = (c == RED ? GREEN : RED);
		for (int neighbor : graph[node]) {
			if (color[neighbor] == UNCOLORED) {
				dfs(neighbor, cNei, graph);                   // µÝ¹éËÑË÷
				if (!valid) {
					return;
				}
			}
			else if (color[neighbor] != cNei) {
				valid = false;
				return;
			}
		}
	}

	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		valid = true;
		color.assign(n, UNCOLORED);
		for (int i = 0; i < n && valid; ++i) {
			if (color[i] == UNCOLORED) {
				dfs(i, RED, graph);
			}
		}
		return valid;
	}
};

int main() {
	vector<vector<int>> a = { {1, 3},{0, 2},{1, 3},{0, 2} };
	Solution s;
	bool res = s.isBipartite(a);
	cout << res;
}