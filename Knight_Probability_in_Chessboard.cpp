//Leetcode 688

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) { //动态规则
        vector<vector<double>> dp(N, vector<double>(N, 0)); //dp[i][j]记录当前落在(i,j)坐标下的概率。
        dp[r][c] = 1.0;
        int r_step[]={-1,-2,-2,-1,1,2,2,1};
        int c_step[]={-2,-1,1,2,2,1,-1,-2};
        for(int k=0;k<K;++k) {
            vector<vector<double>> dp2(N, vector<double>(N, 0));
            for(int i=0;i<N;++i) {
                for(int j=0;j<N;++j) {
                    for(int s=0;s<8;++s) {
                        int nI = i+r_step[s], nJ = j+c_step[s];
                        if(nI>=0&&nI<N&&nJ>=0&&nJ<N)
                            dp2[i][j] += dp[nI][nJ];
                    }
                    dp2[i][j]/=8.0; //dp2[i][j]记录下一步落在(i,j)坐标下的概率，除以8是因为有八种情况，八种情况是等概率事件
                }
            }
            dp = dp2;
        }
        double res=0.0;
        for(int i=0;i<N;++i) {
            for(int j=0;j<N;++j) {
                res+=dp[i][j];
            }
        }
        return res;
    }
};
