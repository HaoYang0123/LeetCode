//只允许一次购买，相当于在数组中找最大的连续子序列和
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curProfit = 0, maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i) {
            curProfit += prices[i] - prices[i - 1];
            if(curProfit < 0) curProfit = 0;
            if(curProfit > maxProfit) maxProfit = curProfit;
        }
        return maxProfit;
    }
};

//允许多次购买，但购买下一个股票得卖掉持有的股票，相当于计算所有的上升值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); ++i) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};

//允许两次购买，同样购买下一个股票得卖掉持有的股票。没看太懂什么意思
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i = 0; i < prices.size(); ++i) {           // Assume we only have 0 money at first
            release2 = max(release2, hold2 + prices[i]);   // The maximum if we've just sold 2nd stock so far.
            hold2 = max(hold2, release1 - prices[i]);      // The maximum if we've just buy  2nd stock so far.
            release1 = max(release1, hold1 + prices[i]);   // The maximum if we've just sold 1nd stock so far.
            hold1 = max(hold1, -prices[i]);                // The maximum if we've just buy  1st stock so far.
        }
        return release2;  //Since release1 is initiated as 0, so release2 will always higher than release1.
    }
};
