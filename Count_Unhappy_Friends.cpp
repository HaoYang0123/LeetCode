//Leetcode 1583

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n, 0));
        for(int i=0; i<preferences.size(); ++i) {
            vector<int> & cur_pref = preferences[i];
            for(int j=0; j<cur_pref.size(); ++j) {
                rank[i][cur_pref[j]] = j+1;
            }
        }
        vector<vector<int>> edges(n, vector<int>());
        for(int i=0;i<pairs.size();++i) {
            edges[pairs[i][0]].push_back(pairs[i][1]);
            edges[pairs[i][1]].push_back(pairs[i][0]);
        }
        int res = 0;
        for(int i=0;i<n;++i) {
            if(is_unhappy(i, n, rank, edges)) ++res;
        }
        return res;
    }
    
    inline bool is_unhappy(int x, int n, vector<vector<int>> & rank, vector<vector<int>> & all_edges) {
        vector<int> & edges = all_edges[x];
        for(int i=0; i<edges.size(); ++i) {
            int y = edges[i]; //x and y is pair
            if(y == x) continue;
            for(int u=0; u<n; ++u) {
                if(rank[x][u] >= rank[x][y] || u == x) continue;
                vector<int> & edges2 = all_edges[u];
                for(int j=0; j<edges2.size(); ++j) { //u and v is pair
                    int v = edges2[j];
                    if(rank[u][x] < rank[u][v] && v != y) {
                        //cout<<x<<"\t"<<y<<"\t"<<u<<"\t"<<v<<endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
