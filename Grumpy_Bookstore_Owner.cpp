//Leetcode 1052
//O(N)的时间复杂度

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n=customers.size();
        int cur = 0;
        for(int i=0;i<X;++i) {
            if(grumpy[i] == 1) cur += customers[i];
        }
        int max=cur;
        for(int i=1;i<=n-X;++i) {
            if(grumpy[i-1]==1) cur -= customers[i-1];
            if(grumpy[i-1+X]==1) cur += customers[i-1+X];
            if(cur > max) max = cur;
        }
        int res = max;
        for(int i=0;i<n;++i) {
            if(grumpy[i]==0) res += customers[i];
        }
        return res;
    }
};
