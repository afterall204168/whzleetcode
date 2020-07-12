#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
	string ans;
public:
	string reformatDate(string date) {
		int n = date.size(), i;
		ans = "";
		for (i = n - 4; i<n; i++)ans += date[i];
		ans += '-';
		for (i = 0; date[i] != ' '; i++);
		i++;
		if (date[i] == 'J')
		{
			ans += '0';
			if (date[i + 1] == 'a')ans += '1';
			else if (date[i + 2] == 'n')ans += '6';
			else ans += '7';
		}
		else if (date[i] == 'F')
		{
			ans += '0';
			ans += '2';
		}
		else if (date[i] == 'M')
		{
			ans += '0';
			if (date[i + 2] == 'r')ans += '3';
			else ans += '5';
		}
		else if (date[i] == 'A')
		{
			ans += '0';
			if (date[i + 1] == 'p')ans += '4';
			else ans += '8';
		}
		else if (date[i] == 'S')
		{
			ans += '0';
			ans += '9';
		}
		else if (date[i] == 'O')
		{
			ans += '1';
			ans += '0';
		}
		else if (date[i] == 'N')
		{
			ans += '1';
			ans += '1';
		}
		else if (date[i] == 'D')
		{
			ans += '1';
			ans += '2';
		}
		ans += '-';
		if (date[1] >= '0'&&date[1] <= '9')for (i = 0; i<2; i++)ans += date[i];
		else
		{
			ans += '0';
			ans += date[0];
		}
		return ans;
	}
};

class Solution2 {
	int s[1005], a[1000005];
public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {
		int i, j, m = 0, ans = 0;
		for (i = 0; i<n; i++)s[i + 1] = s[i] + nums[i];
		for (i = 1; i <= n; i++)for (j = i; j <= n; j++)a[++m] = s[j] - s[i - 1];
		sort(a + 1, a + m + 1);
		for (i = left; i <= right; i++)
		{
			ans += a[i];
			if (ans >= 1000000007)ans -= 1000000007;
		}
		return ans;
	}
};

class Solution3 {
public:
	int minDifference(vector<int>& nums) {
		if (nums.size()<5)return 0;
		sort(nums.begin(), nums.end());
		int n = nums.size(), i, ans = nums[n - 1] - nums[0];
		for (i = 0; i<4; i++)ans = min(ans, nums[i + n - 4] - nums[i]);
		return ans;
	}
};

class Solution4 {
public:
	bool winnerSquareGame(int n) {
		vector<bool> dp(n + 1, false);
		int i, j;
		for (i = 0; i <= n; ++i)//����ʯ�ӵ�����ά��
		{
			for (j = 1; j*j + i <= n; ++j)
			{	//���� j^2 ��ʯ��
				if (!dp[i])//���ֻ�� i ��ʯͷ��ʱ����
					dp[j*j + i] = true;//��ô��j*j+i��ʯͷʱ����Ӯ��
			}
		}
		return dp[n];
	}
};


int main() {
	vector<int> a(5, false);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
}
	