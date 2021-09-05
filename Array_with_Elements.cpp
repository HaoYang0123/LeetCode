// Leetcode 1968

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res(n, 0);
        int j=0;
        for(int i=0;i<n;i+=2) res[i] = nums[j++];
        for(int i=1;i<n;i+=2) res[i] = nums[j++];
        return res;
    }
};
