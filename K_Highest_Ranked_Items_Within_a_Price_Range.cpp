// Leetcode 2146


bool myfunction(const vector<int> & a, const vector<int> & b) {
    if(a[3] < b[3]) return true;
    else if(a[3] > b[3]) return false;
    if(a[2] < b[2]) return true;
    else if(a[2] > b[2]) return false;
    if(a[0] < b[0]) return true;
    else if(a[0] > b[0]) return false;
    return a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        queue<pair<int,int>> qs;
        int n = grid.size(), m = grid[0].size(); 
        vector<vector<bool>> is_vis(n, vector<bool>(m, false));
        vector<vector<int>> sorted_res;
        int start_pos = ij2pos(start[0], start[1], m);
        //cout<<"start_pos\t"<<start_pos<<endl;
        is_vis[start[0]][start[1]] = true;
        qs.push({start_pos, 0});
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        int max_k = -1;
        if(grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]) 
            sorted_res.push_back({start[0], start[1], grid[start[0]][start[1]], 0});
        while(!qs.empty()) {
            pair<int,int> cur = qs.front();
            qs.pop();
            vector<int> curij(2, 0);
            pos2ij(cur.first, m, curij);
            if(max_k != -1 && cur.second >= max_k) break;  //【注】：一定得写这句，不然49个case通过，但超时了。这个主要进行剪枝，如果当前的步数已经比所需要的k的最大步数，还大那么这些就直接break了。因为这些就算加进来，也不会排在前k名
            //cout<<curij[0]<<":"<<curij[1]<<"\t"<<cur.second<<endl;
            int cur_step = cur.second;
            for(int i=0; i<4; ++i) {
                int newi = curij[0] + r_step[i];
                int newj = curij[1] + c_step[i];
                if(newi < 0 || newi >= n || newj < 0 || newj >= m || grid[newi][newj] == 0) continue;
                if(is_vis[newi][newj]) continue;
                is_vis[newi][newj] = true;
                qs.push({ij2pos(newi, newj, m), cur_step+1});
                if(grid[newi][newj] >= pricing[0] && grid[newi][newj] <= pricing[1]) {
                    sorted_res.push_back({newi, newj, grid[newi][newj], cur_step+1});
                    if(sorted_res.size() >= k) max_k = cur_step+1;
                }
            }
        }
        sort(sorted_res.begin(), sorted_res.end(), myfunction);
        vector<vector<int>> res;
        for(int i=0; i<sorted_res.size() && i<k; ++i) {
            res.push_back({sorted_res[i][0], sorted_res[i][1]});
        }
        return res;
    }
    
    inline int ij2pos(int i, int j, int m) {
        return i*m+j;
    }
    
    inline void pos2ij(int pos, int m, vector<int> & ij) {
        ij[0] = pos / m;  //i
        ij[1] = pos % m;  //j
    }
};
