// Leetcode 1905
//BFS搜索

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<bool>> is_vis(m, vector<bool>(n, false));
        int res = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid2[i][j] == 0) continue;
                //如果是1，那么就BFS搜索得到一个island
                if(is_vis[i][j]) continue;
                //cout<<i<<"\t"<<j<<endl;
                if(bfs(grid1, grid2, m, n, i, j, is_vis)) ++res;
            }
        }
        return res;
    }
    
    inline bool bfs(vector<vector<int>> & grid1, vector<vector<int>> & grid2, int m, int n, int i, int j, vector<vector<bool>> & is_vis) {
        //BFS搜索，搜索从(i,j)开始的island，只要判断island（grid2）中的所有元素在grid1中为1，那么是sub_island
        is_vis[i][j] = true;
        queue<pair<int,int>> qs;
        qs.push({i,j});
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        bool flag = true;
        if(grid1[i][j] == 0)
            flag = false;
        while(!qs.empty()) {
            pair<int,int> cur = qs.front();
            //cout<<"cur\t"<<cur.first<<"\t"<<cur.second<<endl;
            qs.pop();
            for(int k=0; k<4; ++k) {
                int newi = cur.first+r_step[k];
                int newj = cur.second+c_step[k];
                if(newi < 0 || newi >= m || newj < 0 || newj >= n || grid2[newi][newj] == 0) continue;
                if(is_vis[newi][newj]) continue;
                is_vis[newi][newj] = true;
                if(grid1[newi][newj] == 0) flag = false;
                qs.push({newi,newj});
            }
        }
        return flag;
    }
};
