##### leetcode599

两个列表最小索引之和

```C++
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> vec;
        unordered_map<string, int> hashmap;
        int MIN = 2000;
        
        for (int i = 0; i < list1.size(); i++)
            hashmap[list1[i]] = i;
        
        for (int i = 0; i < list2.size(); i++) {
            if (hashmap.count(list2[i]) > 0) {
                if (hashmap[list2[i]] + i < MIN) {
                    vec.clear();
                    MIN = hashmap[list2[i]] + i;
                    vec.push_back(list2[i]);
                }
                else if (hashmap[list2[i]] + i == MIN)
                    vec.push_back(list2[i]);
            }
        }
        
        return vec;
    }
};
```

