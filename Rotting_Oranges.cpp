//Leetcode 994

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> rotten; //记录所有坏水果的位置
        int n=grid.size(),m=grid[0].size();
        int fresh_num = 0; //好水果的数目
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(grid[i][j]==2) rotten.push_back(pair<int,int>(i,j));
                else if(grid[i][j]==1) ++fresh_num;
            }
        }
        int res=0;
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        while(fresh_num > 0) {
            if(rotten.size() == 0) break;
            ++res;
            vector<pair<int, int>> new_rotten; //新的被腐蚀掉的水果
            for(int i=0;i<rotten.size();++i) {
                pair<int, int> cur_pos = rotten[i];
                for(int j=0;j<4;++j) {
                    int new_pos_i = cur_pos.first + r_step[j];
                    int new_pos_j = cur_pos.second + c_step[j];
                    if(new_pos_i < 0 || new_pos_i >= n) continue;
                    if(new_pos_j < 0 || new_pos_j >= m) continue;
                    if(grid[new_pos_i][new_pos_j] == 1) {
                        --fresh_num;
                        grid[new_pos_i][new_pos_j] = 2;
                        new_rotten.push_back(pair<int, int>(new_pos_i, new_pos_j));
                    }
                }
            }
            rotten = new_rotten;
        }
        if(fresh_num > 0) return -1;
        return res;
    }
};
