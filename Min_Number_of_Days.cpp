//Leetcode 1568
//答案一定<=2，因为最多只用改两个位置
//比如矩阵中所有元素为1，只需要将左上角中的右边元素和下边元素变为0，那么就会形成两个island
// 1 1 1                1 0 1
// 1 1 1   ======>>>>   0 1 1
// 1 1 1                1 1 1
//所以，可以先判断当前有几个island，如果不是1个（>=2个或者0个），那么直接返回0
//否则，枚举所有grid[i][j]=1的位置，将其变为0，判断变化后的island数量，如果不是1，那么返回1
//否则，直接返回2（因为前面分析了答案一定<=2）

class Solution {
public:
    vector<int> rstep = {0,0,-1,1};
    vector<int> cstep = {-1,1,0,0};
    int n,m;
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cur_island_count = find_island_count(grid);
        if(cur_island_count != 1) return 0; //如果当前island不是1个，那么返回0
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(grid[i][j]==1) {
                    grid[i][j] = 0;
                    cur_island_count = find_island_count(grid);
                    if(cur_island_count != 1) return 1; //如果替换grid[i][j]=0，island不是1，则返回1
                    grid[i][j] = 1; //【注：记得将grid[i][j]还原回去
                }
            }
        }
        return 2; //否则，返回2
    }
    
    inline int find_island_count(vector<vector<int>> & grid) { //计算当前grid状态的island数量
        int res = 0;
        vector<vector<bool>> is_vis(n, vector<bool>(m,false));
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(is_vis[i][j]) continue;
                if(grid[i][j] == 0) continue;
                ++res;
                is_vis[i][j] = true;
                dfs(i, j, grid, is_vis);
            }
        }
        return res;
    }
    
    void dfs(int i,int j, vector<vector<int>> & grid, vector<vector<bool>> & is_vis) {  //使用深度搜索计算island数量
        for(int k=0;k<4;++k) {
            int newi = i + rstep[k];
            int newj = j + cstep[k];
            if(newi < 0 || newi >= n) continue;
            if(newj < 0 || newj >= m) continue;
            if(is_vis[newi][newj]) continue;
            if(grid[newi][newj] == 0) continue;
            is_vis[newi][newj] = true;
            dfs(newi, newj, grid, is_vis);
        }
    }
};
