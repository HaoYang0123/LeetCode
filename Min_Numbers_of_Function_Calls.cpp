//Leetcode 1558

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, max_v = -1;
        for(int i=0;i<nums.size();++i) {
            max_v = max(max_v, nums[i]);
        }
        bool is_ok = false;
        for(int i = 0; i<nums.size(); ++i) {
            if(nums[i] == max_v) {
                if(is_ok) res += get_step2(nums[i]);
                else {
                    res += get_step(nums[i]);
                    is_ok = true;
                }
            }
            else res += get_step2(nums[i]);
        }
        return res;
    }
    
    inline int get_step(int n) {
        int res = 0;
        while(n > 0) {
            if(n % 2 == 1) --n;
            else n = n/2;
            ++res;
        }
        return res;
    }
    
    inline int get_step2(int n) {
        int res = 0;
        while(n > 0) {
            if(n % 2 == 1) {
                --n;
                ++res;
            }
            else n = n/2;
        }
        return res;
    }
};
