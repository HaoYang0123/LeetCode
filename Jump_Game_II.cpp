//Leetcode 45
//O(N)的时间复杂度

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0); //dp[i]表示从0到达i的最小步数
        for(int i=0;i<n;++i) dp[i] = i; //初始化，根据题意可以到达最终位置，那么结果肯定不会超过n
        int cur = 0; //当前位置
        for(int i=1;i<n;) {
            if(nums[cur]+cur>=i) { //假设当前位置cur，加上nums[cur]步数，超过了位置i
                dp[i] = min(dp[i], dp[cur]+1); //则更新位置i的最小步数为dp[cur]+1
                ++i;
            }
            else ++cur; //否则，将当前位置往后移，因为如果不移动当前位置，i及后面的位置一定到达不了
        }
        return dp[n-1];
    }
};
