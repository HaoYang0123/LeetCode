//Leetcode 1437

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cur_ind = -1;
        for(int i=0;i<nums.size();++i) {
            if(nums[i] == 1) {
                if(cur_ind != -1) {
                    if(i-cur_ind-1 < k) return false;
                }
                cur_ind = i;
            }
        }
        return true;
    }
};
