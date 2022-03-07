// Leetcode 2191

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>> new_nums_to_old;
        for(int i=0; i<nums.size(); ++i) {
            int new_v = map_to_int(mapping, nums[i]);
            //cout<<nums[i]<<"\t"<<new_v<<endl;
            new_nums_to_old[new_v].push_back(nums[i]);
        }
        vector<int> res;
        for(auto idx=new_nums_to_old.begin(); idx!=new_nums_to_old.end(); ++idx) {
            vector<int> & olds = idx->second;
            res.insert(res.end(), olds.begin(), olds.end());
        }
        return res;
    }
    
    inline int map_to_int(vector<int> & mapping, int v) {
        if(v == 0) return mapping[0];
        int res = 0;
        int bit = 1;
        while(v > 0) {
            int digit = v % 10;
            int new_digit = mapping[digit];
            res += (bit * new_digit);
            bit *= 10;
            v /= 10;
        }
        return res;
    }
};
