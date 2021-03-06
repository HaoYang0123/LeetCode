//Leetcode 907
//方法1：左边使用stack记录升序，接近超时，时间复杂度O(N^2)
//方法2：左边和右边均使用stack记录，O(N)复杂度。

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

//方法2：
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        stack<int> sta;
        long long res=0;
        int mod = 1000000007;
        vector<int> lll(n,-1), rrr(n, n);
        for(int i=0;i<n;++i) {
            int left;
            while(!sta.empty()&&(A[sta.top()]>A[i])) sta.pop(); //不能使用>=，因为left和right如果都是>=，会重复计算
            if(sta.empty()) left=-1;
            else left=sta.top();
            sta.push(i);
            lll[i] = left;
        }
        while(!sta.empty()) sta.pop();
        for(int i=n-1;i>=0;--i) {
            int right;
            while(!sta.empty()&&(A[sta.top()]>=A[i])) sta.pop();
            if(sta.empty()) right=n;
            else right=sta.top();
            sta.push(i);
            //cout<<i<<"\t"<<right<<endl;
            rrr[i] = right;
        }
        for(int i=0;i<n;++i) {
            //cout<<i<<"\t"<<lll[i]<<"\t"<<rrr[i]<<"\t"<<((long long)(A[i]) * (i-lll[i]) * (rrr[i]-i)) % mod<<endl;
            res += ((long long)(A[i]) * (i-lll[i]) * (rrr[i]-i)) % mod;
            res = res % mod;
        }
        return res;
    }
};
