// week contest 197
// 
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>

using namespace std;


class Solution1 {
public:
	int numIdenticalPairs(vector<int>& nums) {
		map<int, int> mp;           
		for (int x : nums) ++mp[x];      // 只出现一次的数字在最后的map中为1
		int ans = 0;
		for (pair<int, int> p : mp) {
			int x = p.second;
			// cout << x << endl;
			ans += x * (x - 1) / 2;
		}
		return ans;
	}
};


class Solution2 {
public:
	int numSub(string s) {
		int len = s.length();
		int l = 0;
		int ans = 0;
		for (; l < len;) {
			int r = l;
			while (r < len && s[r] == '1') ++r;
			long long x = r - l;
			ans += (int)((1LL * (1 + x) * x / 2) % 1000000007);   // 1LL表示将其转换为long long形式
			ans %= 1000000007;
			l = r + 1;
		}
		return ans;
	}
};


class Solution3 {
public:
	int n, m;
	double d[20005];
	bool vis[20005];
	vector<pair<int, double> >E[20005];
	void SPFA(int s) {
		memset(vis, 0, sizeof vis);       // 应该是给两个数组赋0
		memset(d, 0, sizeof d);

		queue<int> q;
		d[s] = 1;                         
		q.push(s); vis[s] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop(); vis[u] = 0;
			int sz = E[u].size();
			for (int i = 0; i < sz; ++i) {
				double tmp = d[u] * E[u][i].second; int v = E[u][i].first;    
				if (d[v] < tmp) {
					d[v] = tmp;
					if (!vis[v]) { q.push(v); vis[v] = 1; }                // 遍历到所有节点
				}
			}
		}
	}
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		for (int i = 0; i < n; ++i) E[i].clear();      // clear()函数 删除在vector中的所有元素
		m = edges.size();                              // 得到edge的大小
		int u, v;
		double w;                                      
		for (int i = 0; i < m; ++i) {
			u = edges[i][0]; v = edges[i][1]; w = succProb[i];   // 将每一条edge的起点存入u，终点存入v，概率存入w
			E[u].push_back(make_pair(v, w));                     // 并push_back到vector E中
			E[v].push_back(make_pair(u, w));
		}
		SPFA(start);
		return d[end];
	}
};


class Solution4 {
public:
	const double eps = 1e-8;
	const double delta = 0.98;
	const double T = 100;
	const double INF = 999999999;

	struct Point {
		double x, y;
	}p[105];                        // 定义结构体变量

	int n;
	int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };
	double dis(Point a, Point b) { return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); }
	double getSum(Point p[], Point s) {
		double ans = 0;
		for (int i = 0; i<n; i++) {
			ans += dis(p[i], s);
		}
		return ans;
	}

	double Search(Point p[]) {
		Point s = p[0];
		double res = INF;
		double t = T;
		while (t>eps) {
			bool flag = true;
			while (flag) {
				flag = false;
				for (int i = 0; i<4; i++) {
					Point next;
					next.x = s.x + dir[i][0] * t;
					next.y = s.y + dir[i][1] * t;       // 遍历所有情况
					double ans = getSum(p, next);
					if (ans<res) {
						res = ans;
						s = next;
						flag = true;
					}
				}
			}
			t = t * delta;
		}
		return res;
	}

	double getMinDistSum(vector<vector<int>>& positions) {
		n = positions.size();
		for (int i = 0; i<n; i++) {
			p[i].x = positions[i][0];
			p[i].y = positions[i][1];
		}
		return Search(p);
	}
};


int main() {

	// solution 1
	vector<int> a1 = { 1,2,3,4,3,2,4 };
	Solution1 s1;
	int res1 = s1.numIdenticalPairs(a1);
	cout<<res1;

	//solution 3
	vector<int> a[5];
	
}