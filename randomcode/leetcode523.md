##### leetcode523

连续的子数组的和

```C++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
	if (n == 0) { return false; }

	if (k == 0) {
		for (int i = 1; i < n; i++) {
			if (nums[i - 1] == nums[i]&& nums[i] == 0) {
				return true;
			}
		}
		return false;
	}
	else {
    		vector<int> preSum(n + 1);
	    	unordered_map<int, vector<int>> intMap;
	    	preSum[0] = 0;
	    	for (int i = 1; i <= n; i++) {
		    preSum[i] = preSum[i - 1] + nums[i - 1];
        	    intMap[preSum[i] % k].push_back(i);
	    	}
          	intMap[preSum[0] % k].push_back(0);
	
		for (int i = 1; i <= n; i++) {
		    int index = preSum[i] % k;
		    for (auto iter : intMap[index]) {
			if (iter < i - 1) { return true; }
	    	    }
		}
		return false;
	}
    }
};
```

