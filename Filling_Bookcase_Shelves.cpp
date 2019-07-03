//Leetcode 1105
//动态规划，时间复杂度是O(N^2)

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n=books.size();
        vector<int> dp(n+1, INT_MAX); //dp[i]表示放置books[0-i]所需的最小高度
        dp[0] = 0;
        for(int i=1;i<=n;++i) {
            int w=0, h=0; //w表示当前层放置书的宽度，h表示当前层最高书的高度
            for(int j=i;j>0&&w+books[j-1][0]<=shelf_width;--j) { 
                //w+books[j-1]表示books[j-1]可以放在该层上
                w += books[j-1][0];
                h = max(h, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1]+h);
            }
            //cout<<i<<"\t"<<dp[i]<<endl;
            //最后w+books[j-1][0]>shelf_width才会退出for循环，也即books[j-(i-1)]这些书可以被放在同一层
            //枚举这些书找到最小的放置方法:
            //dp[i] = min(dp[i], dp[j-1]+h)，表示将books[j-1]放置在上一层
        }
        return dp[n];
    }
};
