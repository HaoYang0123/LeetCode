//Leetcode 1130
//动态规划，时间复杂度O(N^2)

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); //dp[i][j]记录从arr[i...j]形成的子数组组成的树得到的最小求和结果
        vector<vector<int>> dp_max(n, vector<int>(n, 0)); //dp[i][j]记录从arr[i...j]中的最大值
        for(int i=0;i<n;++i) {
            int max_v=0;
            for(int j=i;j<n;++j) {
                max_v=max(max_v, arr[j]);
                dp_max[i][j]=max_v;
            }
        }
        return dfs(arr, 0, n-1, dp, dp_max);
    }
    
    int dfs(vector<int> & arr, int start, int end, vector<vector<int>> & dp, vector<vector<int>> & dp_max) {
        if(start==end) return 0; //如果只有一个元素，只能作为叶子结点，叶子结点不进行求和
        if(start == end-1) { //如果只有两个元素，那么直接将两个元素分别作为左、右叶子结点，和等于两者的乘积
            return arr[start] * arr[end];
        }
        if(dp[start][end] != 0) return dp[start][end];
        int min_v=INT_MAX;
        for(int i=start; i<end; ++i) { //将arr[start...end]从中间i位置切割成左、右子树
            //int max1=0,max2=0;
            //for(int j=start;j<=i;++j) max1=max(max1, arr[j]);
            //for(int j=i+1;j<=end;++j) max2=max(max2, arr[j]);
            int max1=dp_max[start][i],max2=dp_max[i+1][end];
            int cur_v=dfs(arr,start,i,dp,dp_max)+dfs(arr,i+1,end,dp,dp_max)+max1*max2; //结果为左、右子树的和，加上当前结点，当前结点为左、右子树中元素最大的值的乘积
            min_v=min(min_v, cur_v);
        }
        dp[start][end] = min_v;
        return min_v;
    }
};
