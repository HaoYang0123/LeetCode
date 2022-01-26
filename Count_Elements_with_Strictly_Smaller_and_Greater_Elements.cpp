// Leetcode 2148

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left=0, right=nums.size()-1;
        while(left<nums.size() && nums[left] == nums[0]) ++left;
        while(right>=0 && nums[right] == nums[nums.size()-1]) --right;
        if(left<nums.size() && right>=0)
            return right-left+1;
        return 0;
    }
};
