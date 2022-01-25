// Leetcode 2149

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n, 0);
        int pos_idx=0, neg_idx=1;
        for(int i=0; i<n; ++i) {
            if(nums[i] > 0) {
                res[pos_idx] = nums[i];
                pos_idx += 2;
            }
            else {
                res[neg_idx] = nums[i];
                neg_idx += 2;
            }
        }
        return res;
    }
};
