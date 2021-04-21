// Leetcode 1829

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int c = (1<<maximumBit) - 1;
        //cout<<c<<endl;
        vector<int> res(n, 0);
        for(int i=0;i<n;++i) {
            c = c ^ nums[i];
            res[n-i-1] = c;
        }
        return res;
    }
};
