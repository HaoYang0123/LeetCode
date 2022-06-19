// Leetcode 2300

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; ++i) {
            int s = spells[i];
            long long need_p = 0;
            if(success % s == 0) need_p = success / s;
            else need_p = success / s + 1;
            auto idx = lower_bound(potions.begin(), potions.end(), need_p);
            res[i] = potions.end() - idx;
        }
        return res;
    }
};
