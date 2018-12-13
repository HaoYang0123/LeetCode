//Leetcode 956
//一个数组，选择两堆不相交的元素，使两堆求和值相等。可以看做如下问题：
//一个数组，每个元素有三种变化，变为正，变为负，或变为0，使得所有元素求和为0.
//比如[1,2,3,4,6],则可以变为[+1,+2,+3,0,-6]，那么最终正数求和则为答案，比如+1+2+3=6
//动态规划dp[i][s]表示从第i个值开始，后面求和等于-s的最大的值。

class Solution {
public:
    int NINF;
    int tallestBillboard(vector<int>& rods) {
        NINF = INT_MIN / 3;
        vector<vector<int>> memo(rods.size(), vector<int>(10002,-1));
        return (int)dp(rods, memo, 0, 5000);
    }
    int dp(vector<int>& rods, vector<vector<int>> & memo, int i, int s) {
        if(i==rods.size()) return s==5000? 0 : NINF;
        if(memo[i][s] != -1) return memo[i][s];
        int ans = dp(rods, memo, i+1, s); //不使用rods[i]，即rods[i]直接变为0
        ans = max(ans, dp(rods, memo, i+1, s-rods[i])); //使用rods[i]，将rods[i]变为负
        ans = max(ans, rods[i]+dp(rods, memo, i+1, s+rods[i])); //使用rods[i]，将rods[i]变为正
        memo[i][s] = ans;
        return ans;
    }
};
