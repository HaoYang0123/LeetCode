//Leetcode 1013
//O(N)的时间复杂度，记录数组中除60的余数的个数，然后结果则等于dp[i]*(60-dp[i]) for i from 0 to 59.

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> dp(60, 0); //dp[i]表示time数组中余60为i的个数
        for(int i=0;i<time.size();++i) dp[time[i]%60]++;
        int res = (dp[0]*(dp[0]-1))/2;
        for(int i=1;i<31;++i) {
            if(i==30) res += (dp[30]*(dp[30]-1))/2;
            else res += (dp[i]*dp[60-i]);
        }
        return res;
    }
};
