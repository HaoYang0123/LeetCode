//Leetcode 1551

class Solution {
public:
    int minOperations(int n) {
        if(n%2 == 1) { //奇数
            int res = 0;
            for(int i=2;i<n;i+=2) res += i;
            return res;
        }
        //偶数
        int res = 0;
        for(int i=1;i<n;i+=2) res += i;
        return res;
    }
};
