//Leetcode 1470

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2*n, 0);
        for(int i=0;i<n;++i) {
            res[i*2] = nums[i];
            res[i*2+1] = nums[n+i];
        }
        return res;
    }
};
