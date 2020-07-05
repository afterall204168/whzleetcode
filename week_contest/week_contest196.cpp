// leetcode week contest 196
// created by wanghaozhi
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;



// leetcode 5452
// first problem in week contest
// 判断一个数列经过变换后是否属于等差数列
// 先排序然后在判断
class Solution1 {
public:
	bool canMakeArithmeticProgression(vector<int>& arr) {
		if (arr.size() == 2) return true;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size() - 2; ++i)
		{
			if (arr[i] - arr[i + 1] != arr[i + 1] - arr[i + 2])
				return false;
		}
		return true;
	}
};


// leetcode 5453
// second problem in week contest
// 蚂蚁的最短路程，可以将蚂蚁碰头后相交换，将交换后的蚂蚁看作是原来那只，
// 因此数组中最大的数就为所走的最远路程。
class Solution2 {
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		int lmax = left.empty() ? 0 : *max_element(left.begin(), left.end());
		int rmin = right.empty() ? 0 : (n - *min_element(right.begin(), right.end()));
		return max(lmax, rmin);
	}
};


// leetcode 5454
// third problem in week contest
// 寻找矩阵中全为一的子矩阵
// 先利用left矩阵，用left矩阵的每一个元素存储前面有几个1.
class Solution3 {
public:
	int numSubmat(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();
		vector<vector<int> > left(n, vector<int>(m));
		int now = 0;
		for (int i = 0; i<n; i++) {
			now = 0;
			for (int j = 0; j<m; j++) {
				if (mat[i][j] == 1) now++;
				else now = 0;
				left[i][j] = now;
			}
		}
		int ans = 0, minx;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				minx = 0x3f3f3f3f;
				for (int k = i; k >= 0; k--) {
					minx = min(left[k][j], minx);
					ans += minx;
				}
			}
		}
		return ans;
	}
};


// leetcode 5455
// forth problem in week contest
// 寻找矩阵中全为一的子矩阵
// 先利用left矩阵，用left矩阵的每一个元素存储前面有几个1.
class Solution4 {
public:
	string minInteger(string num, int k) {
		// 如果可以调整的次数超过num.size() * (num.size() - 1) / 2, 那么意味着总是可以将其调整到最小数值。
		if (k > num.size() * (num.size() - 1) / 2) {//先排除特殊情况
			sort(num.begin(), num.end());
			return num;
		}
		if (k <= 0) return num;

		//正常情况
		int a;//记录最小值下标
		char min;//记录最小值
		int j;
		for (int i = 0; i<num.size(); i++)
		{
			min = num[i];
			a = i;
			for (j = i; j<num.size() && j<i + k + 1; j++)//选在符合条件区间的最小值
			{
				if (num[j]<min)
				{
					min = num[j];
					a = j;
				}
			}
			for (int t = a; t>i; t--)//交换
			{
				if (k>0)
				{
					char c;
					c = num[t];
					num[t] = num[t - 1];
					num[t - 1] = c;
					k--;
				}
				else return num;
			}
		}
		return num;
	}
};



int main() {
	// solution2
	int n = 7;
	vector<int> left = {};
	vector<int> right = { 1,2 };
	Solution2 s2;
	int res2 = s2.getLastMoment(7, left, right);
	cout << "the last moment is " << res2 << endl;

	// solution3
	vector<vector<int>> mat;
	vector<int> row1 = { 1,1 };
	vector<int> row2 = { 1,1 };
	vector<int> row3 = { 1,1 };
	mat.push_back(row1);
	mat.push_back(row2);
	mat.push_back(row3);
	Solution3 s3;
	int res3 = s3.numSubmat(mat);
	cout << "the number of submat is " << res3 << endl;

	// solution4
	string num = "9438957234785635408";
	int k = 23;
	Solution4 s4;
	string res4 = s4.minInteger(num, k);
	cout << "the min string is " << res4 << endl;

}