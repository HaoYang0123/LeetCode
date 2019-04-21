//Leetcode 1030
//宽度优化搜索

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<vector<bool>> is_vis(R, vector<bool>(C, false));
        is_vis[r0][c0]=true;
        queue<vector<int>> qs;
        vector<int> pos(2, 0);
        pos[0] = r0;
        pos[1] = c0;
        qs.push(pos);
        int r[] = {0,0,1,-1};
        int c[] = {1,-1,0,0};
        while(!qs.empty()) {
            vector<int> cur_pos=qs.front();
            qs.pop();
            res.push_back(cur_pos);
            for(int i=0;i<4;++i) {
                int new_i = cur_pos[0] + r[i];
                int new_j = cur_pos[1] + c[i];
                if(new_i < 0 || new_i >= R) continue;
                if(new_j < 0 || new_j >= C) continue;
                if(is_vis[new_i][new_j]) continue;
                is_vis[new_i][new_j] = true;
                vector<int> new_pos(2, 0);
                new_pos[0] = new_i;
                new_pos[1] = new_j;
                qs.push(new_pos);
            }
        }
        return res;
    }
};
