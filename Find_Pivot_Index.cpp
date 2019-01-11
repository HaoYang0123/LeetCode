//Leetcode 724
//O(n)的时间复杂度，左边求和、右边求和分别用cur与sum-nums[i]-cur表示

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();++i) sum += nums[i];
        int cur = 0; //左边的值
        for(int i=0;i<nums.size();++i) {
            if(cur == sum - nums[i] - cur) //sum-nums[i]-cur为右边的值
                return i;
            cur += nums[i];
        }
        return -1;
    }
};
