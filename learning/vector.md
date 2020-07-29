#### vector

###### 1、二维vector初始化

```C++
// 直接使用初始化方法
// 这种初始化方法将该二维vector初始化全为0的（r,c）二维vector
vector<vector<int>> newOne(r, vector<int>(c, 0));
// 同理全为0
vector<vector<int>> newOne(r, vector<int>(c));


// 利用resize方法
vector<vector<int> > res;
res.resize(r);//r行
for(int k = 0; k < r; ++k){
	res[k].resize(c);//每行为c列
}
```

