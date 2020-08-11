#### vector

###### 1、二维vector初始化

```C++
// 一维vector初始化，长度为10，元素全为0的vector
vector<int> newone(10,0);

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

###### 2、清空vector

```C++
// vector.clear()清空vector
vector<int> res;
res.push_back(3);
res.clear();
// 清空vector,做题的时候不知道这个函数，所以吃了点亏。
```

###### 3、vector中的最大值最小值

```C++
vector<int> temp(10,0);
cout<<*max_element(temp.begin(),temp.end());
cout<<*min_element(temp.begin(),temp.end());
```

