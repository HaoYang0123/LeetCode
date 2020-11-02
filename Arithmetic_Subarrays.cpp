//Leetcode 1630

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), res_n = l.size();
        vector<bool> res(res_n, true);
        for(int i = 0; i < res_n; ++i) {
            int lind = l[i], rind = r[i];
            vector<int> nums2;
            nums2.insert(nums2.end(), nums.begin()+lind, nums.begin()+rind+1);
            res[i] = is_arith(nums2);
        }
        return res;
    }
    
    inline bool is_arith(vector<int> & nums) {
        sort(nums.begin(), nums.end());
        //for(int i=0;i<nums.size();++i) cout<<nums[i]<<'\t';
        //cout<<endl;
        int delta = nums[1] - nums[0];
        for(int i = 1; i < nums.size() - 1; ++i) {
            if(nums[i+1]-nums[i] != delta) return false;
        }
        return true;
    }
};
