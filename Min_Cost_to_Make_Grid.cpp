//Leetcode 1368
//BFS：将其转化为一张图，两个相邻结点的权重只能为0和1，如果箭头方向与相邻关系不一致，则权重为1（相当于要切换箭头）
//然后计算从(0,0)至(n-1,m-1)的最短路径
//使用dijstra算法，计算从(0,0)至各结点的权重，找到最小的权重（使用deque），然后再继续搜索

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        deque<pair<int,int>> qs; //qs.first为当前位置，qs.second为从(0,0)至当前位置的最小距离
        vector<vector<bool>> is_visited(n, vector<bool>(m, false));
        qs.push_back(pair<int,int>(0,0));
        while(!qs.empty()) {
            pair<int,int> & cur = qs.front();
            int curI = cur.first / m, curJ = cur.first % m;
            is_visited[curI][curJ] = true; //将最小距离的设置为已经访问
            int c = cur.second;
            if(curI == n-1 && curJ == m-1) return c;
            qs.pop_front();
            for(int i=0;i<4;++i) {
                int newI = r_step[i] + curI;
                int newJ = c_step[i] + curJ;
                if(newI < 0 || newI >= n) continue;
                if(newJ < 0 || newJ >= m) continue;
                if(is_visited[newI][newJ]) continue;
                int newC = 1;
                if(grid[curI][curJ] == 1 && i == 1) newC = 0;
                else if(grid[curI][curJ] == 2 && i == 0) newC = 0;
                else if(grid[curI][curJ] == 3 && i == 3) newC = 0;
                else if(grid[curI][curJ] == 4 && i == 2) newC = 0;
                int newPos = newI * m + newJ;
                if(newC == 1) //如果newC为1，则push_back插入至队尾【注：我觉得只有权重为0和1的图才能这样做，不然得用优先队列】
                    qs.push_back(pair<int,int>(newPos, c + newC));
                else //如果newC为0，则push_back插入至队首
                    qs.push_front(pair<int,int>(newPos, c + newC));
            }
        }
        return -1;
    }
};
