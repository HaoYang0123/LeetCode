//Leetcode 1006

class Solution {
public:
    int clumsy(int N) {
        //vector<long long> res;
        long long res=0;
        if(N==1) return 1;
        if(N==2) return 2;
        if(N==3) return 6;
        int i=N;
        for(;i>=4;i-=4) {
            long long a=(long long)i;
            long long b=(long long)(i-1);
            long long c=(long long)(i-2);
            long long d=(long long)(i-3);
            long long r = (a*b)/c;
            if(i==N) res += r+d;
            else res -= r-d;
        }
        if(N%4==0) return res;
        if(N%4==1) return res-1;
        if(N%4==2) return res-2;
        return res-6;
    }
};
