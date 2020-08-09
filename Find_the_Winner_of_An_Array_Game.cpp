//Leetcode 1535

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()-1) {
            //只有最大的才是答案
            int max_v = INT_MIN;
            for(int i=0;i<arr.size();++i) {
                if(arr[i] > max_v) max_v = arr[i];
            }
            return max_v;
        }
        int i = 0, max_v = INT_MIN;
        for(;i<arr.size();) { 
            //每次找到当前最大的值保留：
            //比如：[2,1,3,5,4,6,7]
            //那么只用枚举2,3,5,6,7
            max_v = max(max_v, arr[i]);
            int j = i+1;
            while(j<arr.size() && arr[j] <= arr[i]) ++j;
            int c = (j-i-1);
            if(i != 0) ++c;
            //cout<<i<<"\t"<<j<<"\t"<<c<<endl;
            if(c>=k) return arr[i];
            i = j;
        }
        return max_v;
    }
};
