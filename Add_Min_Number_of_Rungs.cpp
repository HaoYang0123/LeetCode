// Leetcode 1936

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int res = 0, cur = 0;
        for(int i=0; i<rungs.size(); ++i) {
            int d = rungs[i]-cur;
            cur = rungs[i];
            res += (d-1) / dist;
        }
        return res;
    }
};
