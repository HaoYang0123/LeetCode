//Leetcode 823 
//没有AC，但思路没啥问题呀！

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int mod = 10^9+7;
        unordered_map<int,int> map, dp; 
        vector<int> dp2(A.size(),1);
        //map[i]表示值为i的在A的索引号，dp[i]表示以i为根节点的树的个数
        for(int i=0;i<A.size();++i) {
            map[A[i]] = i;
            dp[A[i]] = 0;
        }
        sort(A.begin(),A.end());
        
        for(int i=0;i<A.size();++i) {
            for(int j=0;j<i;++j) {
                if(A[i]%A[j]==0) {
                    int right=A[i]/A[j];
                    if(map.find(right) != map.end()) {
                        dp2[i] = (dp2[i] + dp2[j]*dp2[map[right]]) % mod;
                    }
                }
            }
        }
        
        unsigned long long res = 0;
        for(int i=A.size()-1;i>=0;--i) {
            res += (unsigned long long)(get_number(A[i],i,A,map,dp,mod));
            res = res % mod;
        }
        for(int i=0;i<A.size();++i) {
            //cout<<A[i]<<"\t"<<dp[A[i]]<<"\t"<<dp2[A[i]]<<endl;
            if(dp[A[i]] != dp2[i]) cout<<i<<"\t"<<dp[A[i]]<<"\t"<<dp2[i]<<endl;
        }
        return res;
    }
    int get_number(int val, int index, vector<int> & A, unordered_map<int,int> & map, unordered_map<int,int> & dp, int mod) {
        if(dp[val] != 0) return dp[val];
        unsigned long long res = 1;
        for(int i=index-1;i>=0;--i) {
            if(val % A[i] != 0) continue;
            int a = A[i], b = val/A[i];
            if(map.find(b) == map.end()) continue;
            int res1 = get_number(a, i, A, map, dp, mod);
            int res2 = get_number(b, map[b], A, map, dp, mod);
            res += ((unsigned long long)res1*(unsigned long long)res2)%(mod);
            res = res % mod;
        }
        dp[val] = res;
        return res;
    }
};
