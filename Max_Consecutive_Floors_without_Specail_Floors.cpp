// Leetcode 2274

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int res = 0;
        special.push_back(bottom-1);
        special.push_back(top+1);
        sort(special.begin(), special.end());
        for(int i=1; i<special.size(); ++i) {
            int tmp = special[i] - special[i-1] - 1;
            res = max(res, tmp);
        }
        return res;
    }
};
