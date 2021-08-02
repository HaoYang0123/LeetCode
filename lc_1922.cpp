class Solution {
public:
    int mod;
    int countGoodNumbers(long long n) {
        mod = 1000000007;
        long long res = __poww(20, n/2);
        if (n % 2 != 0) res *= 5;
        return res % mod;
    }


    long long __poww(long long a,long long b){
        long long ans = 1;
        while(b > 0){
            if(b & 1 != 0){
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
};
