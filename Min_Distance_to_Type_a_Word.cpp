//Leetcode 1320

class Solution {
public:
    unordered_map<int, pair<int,int>> c2pos;
    int minimumDistance(string w) {
        initial();
        int n=w.length();
        vector<vector<int>> dp(n,vector<int>(27,0)); //dp[i][j]表示从0至i的最小距离，另一个手指头的位置在j位置
        for(int i=1;i<n;++i) {
            for(int j=0;j<27;++j) {
                dp[i][j] = min(get_dis(w[i]-'A', w[i-1]-'A') + dp[i-1][j], get_dis(j, w[i-1]-'A') + dp[i-1][w[i]-'A']);
            }
        }
        return dp[n-1][26];
    }
    
    inline int get_dis(int c1, int c2) {
        if(c1 == 26) return 0;
        pair<int,int> & pos1 = c2pos[c1];
        pair<int,int> & pos2 = c2pos[c2];
        return abs(pos1.first-pos2.first) + abs(pos1.second-pos2.second);
    }
   
    inline void initial() {
        for(int i=0;i<26;++i) {
            int r_ind = i/6;
            int c_ind = i%6;
            c2pos[i] = pair<int,int>(r_ind, c_ind);
        }
    }
};
