//Leetcode 932
//动态规划+分治

class Solution {
public:
    unordered_map<int, vector<int>> dp;
    vector<int> beautifulArray(int N) {
        return dfs(N);
    }
    vector<int> dfs(int N) {
        if(dp.find(N) != dp.end()) return dp[N];
        vector<int> ans(N, 0);
        if(N==1) ans[0]=1;
        else {
            int t=0;
            vector<int> tmp = dfs((N+1)/2), tmp2 = dfs(N/2);
            for(int i=0;i<tmp.size();++i) {
                ans[t++] = 2*tmp[i]-1;
            }
            for(int i=0;i<tmp2.size();++i) {
                ans[t++]= 2*tmp2[i];
            }
        }
        dp[N] = ans;
        return ans;
    }
};
