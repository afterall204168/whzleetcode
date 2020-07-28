##### leetcode 923

```C++
class Solution {
public:
    const long M=1e9+7;
    int threeSumMulti(vector<int>& A, int target) {
        sort(A.begin(),A.end());//先对数组进行排序
        int ans=0;
        for(int i=0;i!=A.size()-2;++i){
            int p=i+1;//定义左右指针
            int q=A.size()-1;
            int res=target-A[i];
            //这里的条件与之前的三数之和有些不同
            while(A[p]<A[q]){
                if(A[p]+A[q]<res) ++p;
                else if(A[p]+A[q]>res) --q;
                //A[p]+A[q]==res，这种情况下，p向右还有重复元素，q向左还有重复元素
                //保存双指针，向左向右各自找到第一个不想等的元素
                //再次审题可知，这种情况满足条件的数量为(第一个指针已经固定)= (p-pl)(pr-q)
                else{
                    int pl=p;
                    int pr=q;
                    // 这里比较关键
                    while(A[++p]==A[pl]) ;  //先递增 tl  ,p是第一个 A[p]!=A[pl] 的下标
                    while(A[--q]==A[pr]) ;  //先递减 tr  ,q是第一个 A[q]!=A[pr] 的下标
                    ans+=(p-pl)*(pr-q);
                    ans%=M;
                }
            }
            //这里还需要注意一个终止条件，当A[p]==A[q],即上面的while循环结束
            //如果恰好A[p]+A[q]==res,这时又增加了满足条件的数量
            //参考官方题解的三指针法，p,q距离为t,这时可增加数量为 t*(t-1)/2(简单的数学组合);
            if(A[p]==A[q] && A[p]+A[q]==res){
                int t=q-p+1;
                ans+=t*(t-1)/2;
                ans%=M;
            }
        }
        return ans;
    }
};
```

