//Leetcode 920
//动态规划，dp[i][j]表示总共需要听i首歌，但歌单中有j首歌，选择的种数
//dp[i][j]可以等于听i-1首歌（歌单中有j-1首歌），下一首歌从N-(j-1)中选择一首（即dp[i-1][j-1]*(N-j+1)）
//当然dp[i][j]也可以选择从听过的i-1首歌中（即j首歌中）选择j-K首歌听

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod = 1000000007;
        vector<vector<long long>> dp(L+1, vector<long long>(N+1));
        dp[0][0] = 1;
        for(int i=1;i<=L;++i) {
            for(int j=1;j<=N;++j) {
                dp[i][j] += dp[i-1][j-1]*(N-j+1);
                dp[i][j] += dp[i-1][j] * max(j-K, 0);
                dp[i][j] %= mod;
            }
        }
        return int(dp[L][N]);
    }
};
