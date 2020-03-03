//Leetcode 1359

class Solution {
public:
    int countOrders(int n) {
        long long res = 1;
        int MOD = 1000000007;
        for(int i=2;i<=n;++i) { 
        //当i=2时，则i=1已经插入相应位置了，里面有两个元素，新的P有三个位置插入，而D分别三种情况：3+2+1=6
            long long tmp = (i * (2*(i-1)+1)) % MOD; //即从1至2*(i-1)+1个元素求和
            res = (res * tmp) % MOD; //上一轮有res种情况，所以当前情况数量等于res*tmp
        }
        return res;
    }
};
