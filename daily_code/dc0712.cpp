// daily code practice 0712
// leetcode 174
// created by wanghaozhi
// ÓÂÊ¿¾È¹«Ö÷

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int n = dungeon.size(), m = dungeon[0].size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
		dp[n][m - 1] = dp[n - 1][m] = 1;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = m - 1; j >= 0; --j) {
				int minn = min(dp[i + 1][j], dp[i][j + 1]);
				dp[i][j] = max(minn - dungeon[i][j], 1);
			}
		}
		return dp[0][0];
	}
};



int main() {
	vector<vector<int>> data = { { -2,-3,3 },{ -5,-10,1 }, {10,30,-5} };
	Solution s;
	int res = s.calculateMinimumHP(data);
	cout << res << endl;

}