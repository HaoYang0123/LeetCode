// Leetcode 1899

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        int xx = 0, yy = 0, zz = 0;
        int n = triplets.size();
        for(int i=0; i<n; ++i) {
            int tx = triplets[i][0], ty = triplets[i][1], tz = triplets[i][2];
            if(tx == x && ty <= y && tz <= z) {
                ++xx;
            }
            if(ty == y && tx <= x && tz <= z) {
                ++yy;
            }
            if(tz == z && tx <= x && ty <= y) {
                ++zz;
            }
        }
        return xx > 0 && yy > 0 && zz > 0;
    }
};
