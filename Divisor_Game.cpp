//Leetcode 1025
//动态规划，dp[0][n]和dp[1][n]分别存储Alice和Bob在当前牌面为n是否能够赢；
//在当前牌面为n的情况下是否能够赢，枚举i(0-n之间)且n%i==0，使得对手在n-i的情况输，则自己能够赢

class Solution {
public:
    bool divisorGame(int N) {
        vector<vector<int>> dp(2, vector<int>(N+1, 0));//1 means win, -1 means loss
        dp[1][1] = -1;
        dp[0][1] = -1;
        dfs(N, dp, 0);
        //for(int i=1;i<=N;++i) cout<<i<<"\t"<<dp[0][i]<<"\t"<<dp[1][i]<<endl;
        return dp[0][N]==1;
    }
    
    int dfs(int n, vector<vector<int>> & dp, int type) { //type为0表示Alice下，1表示Bob下
        if(dp[type][n] != 0) return dp[type][n];
        int res = -1;
        for(int i=n/2;i>0;--i) {
            if(n%i != 0) continue;
            int new_type = (type==0?1:0);
            if(dfs(n-i, dp, new_type)==-1) {
                res = 1;
                break;
            }
        }
        dp[type][n] = res;
        return res;
    }
};
