//Leetcode 769
//动态规划，时间复杂度有些高O(n^3)，网上有O(n)的代码

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(n+1,pair<int,int>(0,0)));
        for(int i=0;i<n;++i) {
            int min=arr[i],max=arr[i];
            dp[i][i].first=min;
            dp[i][i].second=max;
            for(int j=i+1;j<n;++j) {
                if(arr[j]>max) {
                    max=arr[j];
                }
                else if(arr[j]<min) {
                    min=arr[j];
                }
                dp[i][j].first=min;
                dp[i][j].second=max;
            }
        }
        vector<vector<int>> dp2(n+1,vector<int>(n+1,0));
        return dfs(dp,dp2,0,n-1);
    }
    
    int dfs(vector<vector<pair<int,int>>> & dp, vector<vector<int>> & dp2, int start, int end) {
        if(start==end) return 1;
        if(dp2[start][end] != 0) return dp2[start][end];
        int res = 1;
        for(int i=start;i<end;++i) {
            int max=dp[start][i].second;
            int min=dp[i+1][end].first;
            if(max<min) {
                int tmp = dfs(dp,dp2,start,i) + dfs(dp,dp2,i+1,end);
                if(tmp>res) res=tmp;
            }
        }
        dp2[start][end] = res;
        return res;
    }
};


//网上O(n)的代码，很简单：
//比如例子[1,0,2,3,4]，当i=1,arr[i]=0时，max=1，那么max==i，则++res（表示可以i=1这个位置切割，因为arr[:i]最大值为i证明可以切割）。
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0,max=arr[0];
        for(int i=0;i<arr.size();++i) {
            max=(max>arr[i]?max:arr[i]);
            if(max==i) ++res;
        }
        return res;
    }
};
