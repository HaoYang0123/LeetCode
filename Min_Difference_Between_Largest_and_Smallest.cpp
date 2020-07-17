//Leetcode 1509

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //排序后，变化3个元素：只能变化最左边、最右边的元素
        if(nums.size()<=4) return 0;
        vector<int> res(4,0);
        for(int i=0;i<=3 && i<nums.size();++i) {
            res[i] = nums[nums.size()-4+i] - nums[i];
        }
        sort(res.begin(), res.end());
        return res[0];
    }
};
