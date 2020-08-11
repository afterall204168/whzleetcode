##### leetcode 150

```C++
class Solution {
public:
    int ans;
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int str_mid1, str_mid2;
        for (auto v_mate : tokens) {
            if (v_mate == "+") {
                str_mid1 = stk.top();
                stk.pop();
                str_mid2 = stk.top();
                stk.pop();
                stk.push(str_mid2 + str_mid1);
            }
            else if (v_mate == "-") {
                str_mid1 = stk.top();
                stk.pop();
                str_mid2 = stk.top();
                stk.pop();
                stk.push(str_mid2 - str_mid1);
            }
            else if (v_mate == "*") {
                str_mid1 = stk.top();
                stk.pop();
                str_mid2 = stk.top();
                stk.pop();
                stk.push(str_mid2 * str_mid1);
            }
            else if (v_mate == "/") {
                str_mid1 = stk.top();
                stk.pop();
                str_mid2 = stk.top();
                stk.pop();
                stk.push(str_mid2 / str_mid1);
            }
            else stk.push(atoi(v_mate.c_str()));
        }
        ans = stk.top();
        return ans;
    }
};
```

