// Leetcode 827
//超时了，但思路是正确的，找到所有的islands，然后判断两两islands是否可以直接到达
//后来修改了一下思路。上面思路还是两两判断islands是否可以连接，时间开销会更大。可以通过枚举grid[i][j]=0的位置，看看四方向上的位置是哪些岛屿可以连接

// AC代码

class Solution {
public:
    int m,n;
    int largestIsland(vector<vector<int>>& grid) {
        vector<unordered_set<int>> islands;
        m=grid.size();
        n=grid[0].size();  //m==n
        vector<vector<int>> pos2idx(m, vector<int>(n, -1));  //grid[i][j]对应的islands的索引号
        vector<vector<bool>> is_vis(m, vector<bool>(n, false));
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        // (x1+1, y1+1), (x1-1,y1-1), (x1+1, y1-1), (x1-1,y1+1)
        // (x1, y1+2), (x1, y1-2), (x1-2, y1), (x1+2, y1)
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 1 && !is_vis[i][j]) {
                    queue<pair<int,int>> qs;
                    unordered_set<int> one_island;
                    is_vis[i][j] = true;
                    qs.push({i,j});
                    while(!qs.empty()) {
                        pair<int,int> cur=qs.front();
                        qs.pop();
                        int cx = cur.first, cy = cur.second;
                        one_island.insert(get_pos(cx, cy));
                        for(int k=0; k<4; ++k) {
                            int nx = cx + r_step[k];
                            int ny = cy + c_step[k];
                            if(nx < 0 || nx >= m) continue;
                            if(ny < 0 || ny >= n) continue;
                            if(grid[nx][ny] == 0 || is_vis[nx][ny]) continue;
                            is_vis[nx][ny] = true;
                            qs.push({nx,ny});
                        }
                    }
                    islands.push_back(one_island);
                }
            }
        }
        //cout<<"islands num:\t"<<islands.size()<<endl;
        if(islands.size() == 0) return 1;
        if(islands.size() == 1 && islands[0].size() == m*n) return m*n;  //全部为1
        for(int i=0; i<islands.size(); ++i) {
            unordered_set<int> & island = islands[i];
            for(auto idx=island.begin(); idx!=island.end(); ++idx) {
                int x = 0, y = 0;
                get_pos2(*idx, x, y);
                pos2idx[x][y] = i;
            }
        }
        int res = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 1) continue;  //不是空地
                int tmp = 1;
                unordered_set<int> island_idxs;
                for(int k=0; k<4; ++k) {
                    int i2 = i+r_step[k];
                    int j2 = j+c_step[k];
                    if(i2 < 0 || i2 >= m) continue;
                    if(j2 < 0 || j2 >= n) continue;
                    int island_idx = pos2idx[i2][j2];
                    if(island_idx >= 0) island_idxs.insert(island_idx);
                }
                for(auto idx=island_idxs.begin(); idx!=island_idxs.end(); ++idx) {
                    tmp += islands[*idx].size();
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
    
    
    
    inline int get_pos(int x, int y) {
        return x*n+y;
    }
    
    inline void get_pos2(int pos, int & x, int & y) {
        x = pos / n;
        y = pos % n;
    }
};


// TLE代码
class Solution {
public:
    int m,n;
    int largestIsland(vector<vector<int>>& grid) {
        vector<unordered_set<int>> islands;
        m=grid.size();
        n=grid[0].size();  //m==n
        vector<vector<bool>> is_vis(m, vector<bool>(n, false));
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        // (x1+1, y1+1), (x1-1,y1-1), (x1+1, y1-1), (x1-1,y1+1)
        // (x1, y1+2), (x1, y1-2), (x1-2, y1), (x1+2, y1)
        int r_step2[] = {1,-1,1,-1,0,0,-2,2};
        int c_step2[] = {1,-1,-1,1,2,-2,0,0};
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 1 && !is_vis[i][j]) {
                    queue<pair<int,int>> qs;
                    unordered_set<int> one_island;
                    is_vis[i][j] = true;
                    qs.push({i,j});
                    while(!qs.empty()) {
                        pair<int,int> cur=qs.front();
                        qs.pop();
                        int cx = cur.first, cy = cur.second;
                        one_island.insert(get_pos(cx, cy));
                        for(int k=0; k<4; ++k) {
                            int nx = cx + r_step[k];
                            int ny = cy + c_step[k];
                            if(nx < 0 || nx >= m) continue;
                            if(ny < 0 || ny >= n) continue;
                            if(grid[nx][ny] == 0 || is_vis[nx][ny]) continue;
                            is_vis[nx][ny] = true;
                            qs.push({nx,ny});
                        }
                    }
                    islands.push_back(one_island);
                }
            }
        }
        //cout<<"islands num:\t"<<islands.size()<<endl;
        if(islands.size() == 0) return 1;
        if(islands.size() == 1 && islands[0].size() == m*n) return m*n;  //全部为1
        int res = 0;
        vector<vector<unordered_set<int>>> can_con(m, vector<unordered_set<int>>(n, unordered_set<int>()));
        for(int i=0; i<islands.size(); ++i) {
            unordered_set<int> & one = islands[i];
            res = max(res, int(one.size())+1);
            for(int j=i+1; j<islands.size(); ++j) {
                unordered_set<int> & two = islands[j];
                vector<pair<int,int>> can_con_pos;
                if(can_connect(one, two, r_step2, c_step2, can_con_pos)) {
                    //如果两个islands相连
                    for(int k=0; k<can_con_pos.size(); ++k) {
                        pair<int,int> & one = can_con_pos[k];
                        can_con[one.first][one.second].insert(i);
                        can_con[one.first][one.second].insert(j);
                    }
                }
            }
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                unordered_set<int> & one = can_con[i][j];
                int tmp = 0;
                for(auto idx=one.begin(); idx!=one.end(); ++idx) 
                    tmp += islands[*idx].size();
                res = max(res, tmp+1);
            }
        }
        return res;
    }
    
    inline bool can_connect(unordered_set<int> & one, unordered_set<int> & two, int r_step2[], int c_step2[], vector<pair<int,int>> & can_con_pos) {
        for(auto idx=one.begin(); idx!=one.end(); ++idx) {
            int x1 = 0, y1 = 0;
            get_pos2(*idx, x1, y1);
            // (x1+1, y1+1), (x1-1,y1-1), (x1+1, y1-1), (x1-1,y1+1)
            // (x1, y1+2), (x1, y1-2), (x1-2, y1), (x1+2, y1)
            for(int k=0; k<8; ++k) {
                int x2 = x1 + r_step2[k];
                int y2 = y1 + c_step2[k];
                if(x2 < 0 || x2 >= m) continue;
                if(y2 < 0 || y2 >= n) continue;
                int pos2 = get_pos(x2, y2);
                if(two.find(pos2) != two.end()) {
                    if(k==0) {
                        can_con_pos.push_back({x1+1,y1});
                        can_con_pos.push_back({x1,y1+1});
                    }
                    else if(k==1) {
                        can_con_pos.push_back({x1-1,y1});
                        can_con_pos.push_back({x1,y1-1});
                    }
                    else if(k==2) {
                        can_con_pos.push_back({x1+1,y1});
                        can_con_pos.push_back({x1,y1-1});
                    }
                    else if(k==3) {
                        can_con_pos.push_back({x1-1,y1});
                        can_con_pos.push_back({x1,y1+1});
                    }
                    else if(k==4) {
                        can_con_pos.push_back({x1,y1+1});
                    }
                    else if(k==5) {
                        can_con_pos.push_back({x1,y1-1});
                    }
                    else if(k==6) {
                        can_con_pos.push_back({x1-1,y1});
                    }
                    else {
                        can_con_pos.push_back({x1+1,y1});
                    }
                }
            }
        }
        return can_con_pos.size() > 0;
    }
    
    inline int get_pos(int x, int y) {
        return x*n+y;
    }
    
    inline void get_pos2(int pos, int & x, int & y) {
        x = pos / n;
        y = pos % n;
    }
};
