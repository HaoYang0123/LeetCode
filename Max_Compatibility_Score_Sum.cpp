// Leetcode 1947

class Solution {
public:
    vector<vector<int>> score;
    int std_n;
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        std_n = students.size();
        for(int i=0; i<students.size(); ++i) {
            vector<int> tmp;
            for(int j=0; j<mentors.size(); ++j) {
                tmp.push_back(get_score(students[i], mentors[j]));
            }
            score.push_back(tmp);
        }
        vector<bool> is_vis(std_n, false);
        return dfs(0, 0, is_vis);
    }
    
    int dfs(int ind, int cur, vector<bool> & is_vis) {
        if(ind >= std_n) return cur;
        int max_score = 0;
        for(int i=0; i<std_n; ++i) {
            if(is_vis[i]) continue;
            is_vis[i] = true;
            int new_s = cur + score[ind][i];
            int tmp_score = dfs(ind+1, new_s, is_vis);
            max_score = max(max_score, tmp_score);
            is_vis[i] = false;
        }
        return max_score;
    }
    
    inline int get_score(vector<int> & aw, vector<int> & aw2) {
        int res = 0;
        for(int i=0; i<aw.size(); ++i) {
            if(aw[i] == aw2[i]) res++;
        }
        return res;
    }
};
