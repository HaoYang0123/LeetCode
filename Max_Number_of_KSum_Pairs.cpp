//Leetcode 1679

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> v2c;
        for(int i = 0; i < nums.size(); ++i) {
            v2c[nums[i]]++;
        }
        int res = 0;
        for(auto ind = v2c.begin(); ind != v2c.end(); ++ind) {
            int v = ind->first;
            int v2 = k - v;
            if(v > v2) continue; //只用考虑较小的和较大的求和，防止重复计数
            auto ind2 = v2c.find(v2);
            if(ind2 == v2c.end()) continue;
            if(v != v2) {
                res += min(ind->second, ind2->second);
            }
            else {
                res += ind->second / 2;
            }
        }
        return res;
    }
};
