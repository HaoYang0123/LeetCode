// Leetcode 2201

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> pos2idx(n, vector<int>(n, -1));
        vector<vector<bool>> is_dig(n, vector<bool>(n, false));
        vector<vector<bool>> is_vis(n, vector<bool>(n, false));
        for(int i=0; i<artifacts.size(); ++i) {
            int r1 = artifacts[i][0], c1 = artifacts[i][1];
            int r2 = artifacts[i][2], c2 = artifacts[i][3];
            for(int r=r1; r<=r2; ++r) {
                for(int c=c1; c<=c2; ++c) {
                    pos2idx[r][c] = i;
                }
            }
        }
        for(int i=0; i<dig.size(); ++i) is_dig[dig[i][0]][dig[i][1]] = true;
        int res = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(is_vis[i][j]) continue;
                if(pos2idx[i][j]==-1) continue;
                vector<int> & one_art = artifacts[pos2idx[i][j]];
                int r1 = one_art[0], c1 = one_art[1];
                int r2 = one_art[2], c2 = one_art[3];
                bool is_dig_flag = true;
                for(int r=r1; r<=r2; ++r) {
                    for(int c=c1; c<=c2; ++c) {
                        if(!is_dig[r][c]) {
                            is_dig_flag = false;
                            break;
                        }
                        is_vis[r][c] = true;
                    }
                    if(!is_dig_flag) break;
                }
                if(is_dig_flag) ++res;
            }
        }
        return res;
    }
};
