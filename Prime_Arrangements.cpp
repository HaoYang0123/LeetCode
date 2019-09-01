//Leetcode 1175

class Solution {
public:
    int MOD;
    int numPrimeArrangements(int n) {
        MOD = 1000000007;
        vector<int> is_prime(n+1, true);
        is_prime[1] = false;
        for(int i=2;i<=n;++i) {
            for(int m=2;;++m) {
                int v=i*m;
                if(v>n) break;
                is_prime[v] = false;
            }
        }
        int prime_num = 0, not_num = 0;
        for(int i=1;i<=n;++i) {
            if(is_prime[i])
                ++prime_num;
            else
                ++not_num;
        }
        return (permutate_num(prime_num) * permutate_num(not_num)) % MOD;
    }
    
    long long permutate_num(int c) {
        long long res = 1; //long long防止int溢出，尽管有MOD求余，但是res*i有可能会超出int范围
        for(int i=2;i<=c;++i) res = (res * i) % MOD;
        return res;
    }
};
