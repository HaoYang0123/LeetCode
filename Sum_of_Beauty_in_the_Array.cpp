// Leetcode 2012

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0); //记录从左到当前位置的最大值
        vector<int> suffix(n, 0); //记录从右到当前位置的最小值
        prefix[0] = nums[0];
        for(int i=1; i<n; ++i) prefix[i] = max(prefix[i-1], nums[i]);
        suffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; --i) suffix[i] = min(suffix[i+1], nums[i]);
        int res = 0;
        for(int i=1; i<n-1; ++i) {
            if(nums[i] > prefix[i-1] && nums[i] < suffix[i+1]) res += 2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) res += 1;
        }
        return res;
    }
};
