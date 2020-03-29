//Leetcode 1389

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> res(n, 0);
        int cur_n = 0;
        for(int i=0;i<n;++i) {
            update(res, cur_n, index[i], nums[i]);
            cur_n++;
        }
        return res;
    }
    inline void update(vector<int> & res, int cur_n, int ind, int value) {
        for(int i=cur_n-1;i>=ind;--i) res[i+1] = res[i];
        res[ind] = value;
    }
};
