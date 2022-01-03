// Leetcode 1929

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(2*n, 0);
        for(int i=0; i<res.size(); ++i) {
            if(i < n) res[i] = nums[i];
            else res[i] = nums[i-n];
        }
        return res;
    }
};
