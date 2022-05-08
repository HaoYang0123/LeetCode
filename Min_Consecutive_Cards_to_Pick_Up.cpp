// Leetcode 2260

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int>> val2pos;
        for(int i=0; i<cards.size(); ++i) {
            val2pos[cards[i]].push_back(i);
        }
        int res = INT_MAX;
        for(auto idx=val2pos.begin(); idx!=val2pos.end(); ++idx) {
            vector<int> & pos = idx->second;
            for(int i=0; i<pos.size()-1; ++i) {
                res = min(res, pos[i+1]-pos[i]+1);
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};
