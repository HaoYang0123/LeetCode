// Leetcode 1962

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        multiset<int> mm;
        for(int i=0; i<piles.size(); ++i) mm.insert(piles[i]);
        while(k--) {
            auto max_idx = mm.end();
            --max_idx;   //找到最大的值
            int v = *max_idx;
            int remain_v = v - (v/2);
            mm.erase(max_idx);
            mm.insert(remain_v);
        }
        int res = 0;
        for(auto idx=mm.begin(); idx!=mm.end(); ++idx) {
            res += *idx;
        }
        return res;
    }
};
