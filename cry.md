```C++
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()){return *max_element(arr.begin(),arr.end());}
        int i=0;
        int count = 0;
        
        
        vector<int> first = arr.begin();
        vector<int> last = arr.begin()+k+1;
        vector<int> temp(first, last);
        
        int mm = *max_element(temp.begin(),temp.end());
        
        if(temp[0]==mm){
            return temp[0];
        }
        if(temp[1]==mm){
            return temp[1];
        }
        distance(vec.begin(), itMax)
        
        /*
        while(i<k){
            count++;
            if(arr[1]>arr[0]){
                arr.push_back(arr[0]);
                arr.erase(arr.begin()+0);
                i=1;
            }
            else{
                arr.push_back(arr[1]);
                arr.erase(arr.begin()+1);
                i++;
            }
        }
        */
        
        return arr[0];
    }
};
```

