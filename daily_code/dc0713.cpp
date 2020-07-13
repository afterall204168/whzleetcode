// daily code0713
// leetcode 350
// 第一次提交的时候没有注意到有重复的

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			return intersect(nums2, nums1);
		}
		unordered_map <int, int> m;
		for (int num : nums1) {
			++m[num];
		}
		vector<int> intersection;
		for (int num : nums2) {
			if (m.count(num)) {                 // 如果m中存在num
				intersection.push_back(num);    // 将其push_back到结果中
				--m[num];                       // 将其减一
				if (m[num] == 0) {              // 为0时删去
					m.erase(num);
				}
			}
		}
		return intersection;
	}
};


int main() {
	vector<int> nums1 = { 1,2,2 };
	vector<int> nums2 = { 2,2 };
	Solution s;
	vector<int> res = s.intersect(nums1, nums2);
	for (int re : res) {
		cout << re << endl;
	}
}