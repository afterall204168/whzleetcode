// daily code0714
// leetcode120
// 三角形的最短路径和
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>> f(n, vector<int>(n));
		f[0][0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			f[i][0] = f[i - 1][0] + triangle[i][0];
			for (int j = 1; j < i; ++j) {
				f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
			}
			f[i][i] = f[i - 1][i - 1] + triangle[i][i];
		}
		return *min_element(f[n - 1].begin(), f[n - 1].end());
	}
};

class Solution2 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>> f(2, vector<int>(n));
		f[0][0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			int curr = i % 2;
			int prev = 1 - curr;
			f[curr][0] = f[prev][0] + triangle[i][0];
			for (int j = 1; j < i; ++j) {
				f[curr][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
			}
			f[curr][i] = f[prev][i - 1] + triangle[i][i];
		}
		return *min_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
	}
};

class Solution3 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int> f(n);
		f[0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			f[i] = f[i - 1] + triangle[i][i];
			for (int j = i - 1; j > 0; --j) {
				f[j] = min(f[j - 1], f[j]) + triangle[i][j];
			}
			f[0] += triangle[i][0];
		}
		return *min_element(f.begin(), f.end());
	}
};



int main() {
	vector<vector<int>> a = { {1},{2,4},{3,8,5},{4,6,2,7} };
	Solution3 s3;
	int res = s3.minimumTotal(a);
	cout << res << endl;
}