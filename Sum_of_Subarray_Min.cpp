//Leetcode 907

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        stack<int> sta;
        long long res=0;
        int mod = 1000000007;
        for(int i=0;i<n;++i) {
            int left,right;
            while(!sta.empty()&&(A[sta.top()]>A[i])) sta.pop(); //不能使用>=，因为left和right如果都是>=，会重复计算
            if(sta.empty()) left=-1;
            else left=sta.top();
            sta.push(i);
            right=i+1;
            while(right<n&&A[right]>=A[i]) ++right;
            //cout<<i<<"\t"<<A[i]<<"\t"<<left<<"\t"<<right<<endl;
            res += (((long long)(A[i]) * (long long)(i-left) * (long long)(right-i)) % mod);
            res = res % mod;
        }
        return res;
    }
};
