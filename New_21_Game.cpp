//Leetcode 837
//动态规划，并且避免重复计算

class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp(N+W+1,0); //dp[i]表示从第i个值出发的结果，最终答案是从0出发。
        for(int k=K;k<=N;++k) dp[k]=1.0;
        double S=(N-K+1<W?N-K+1:W); //17-21:1, 16:0.5(17+...+27)/10
        for(int k=K-1;k>=0;--k) {
            //for(int p=k+1;p<=k+W;++p) tmp+=dp[p]; //本来是如此，但避免重复计算，使用S来计算中间值
            //比如dp[16]=(dp[17]+...+dp[27)/W，那么可以将dp[17]+...+dp[27]保存在S中，更新S=S+(dp[16]-dp[27])，这样就直接得到了dp[16]+...+dp[26]的值
            dp[k] = S/W; //dp[16]=5/10,dp[15]=5.5/10
            S+=dp[k]-dp[k+W]; //S=5+(0.5-0),S=5.5+(0.55-0)
        }
        for(int i=0;i<=N;++i) cout<<i<<"\t"<<dp[i]<<endl;
        return dp[0];
    }
};
