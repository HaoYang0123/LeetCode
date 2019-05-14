//Leetcode 1043
//动态规划：dp[i]表示从A数组中第i到结束的最优解
//从第i个元素开始，有K种分割方法：
//方法1：将第i个元素与其它元素分割，后续从i+1开始
//方法2：将第i个和第i+1个元素分割在一起，后续从i+2开始
//...
//方法K：将第i个...第i+K-1个元素分割在一起，后续从i+K开始

class Solution {
public:
    int n;
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        n = A.size();
        vector<int> dp(n, -1);
        return dfs(A, dp, 0, K);
    }
    
    int dfs(vector<int> & A, vector<int> & dp, int i, int K) {
        if(i>=n) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int end = i+K;
        if(end>n) end=n;
        int res = A[i] + dfs(A, dp, i+1, K); //第i个元素单独分割
        int max_v = A[i];
        for(int j=i+1;j<end;++j) {
            if(max_v<A[j]) max_v=A[j];
            int new_v = max_v * (j-i+1) + dfs(A, dp, j+1, K); //将第i到j的元素分割在一起（[i,...,j]的最大值*(j-i+1)为当前的求和）
            if(new_v > res) res = new_v;
        }
        dp[i] = res;
        return res;
    }
};
