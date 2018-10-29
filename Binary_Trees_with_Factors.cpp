//Leetcode 823
//动态规划

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        unsigned long long mod = 1000000007;
        unordered_map<int,int> map;
        unordered_map<unsigned long long, int> dp;
        sort(A.begin(),A.end());
        //map[i]表示值为i的在A的索引号，dp[i]表示以i为根节点的树的个数
        for(int i=0;i<A.size();++i) {
            map[A[i]] = i;
            dp[A[i]] = 0;
        }
        
        unsigned long long res = 0;
        for(int i=A.size()-1;i>=0;--i) {
            res += (unsigned long long)(get_number(A[i],i,A,map,dp,mod));
            res = res % mod;
        }
        return (int)res;
    }
    unsigned long long get_number(int val, int index, vector<int> & A, unordered_map<int,int> & map, unordered_map<unsigned long long,int> & dp, unsigned long long mod) {
        if(dp[val] != 0) return dp[val];
        unsigned long long res = 1;
        for(int i=index-1;i>=0;--i) {
            if(val % A[i] != 0) continue;
            int a = A[i], b = val/A[i];
            if(map.find(b) == map.end()) continue;
            unsigned long long res1 = get_number(a, i, A, map, dp, mod);
            unsigned long long res2 = get_number(b, map[b], A, map, dp, mod);
            res = (unsigned long long)res + ((unsigned long long)res1*(unsigned long long)res2)%((unsigned long long)mod);
            res = res % (unsigned long long)mod;
        }
        dp[val] = res;
        return res;
    }
};
