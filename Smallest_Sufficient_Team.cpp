//Leetcode 1125
//动态规划，使用dp[i][j]表示从req_skills中第i个skill开始至最后的skill，当前状态是j（通过对所有req_skills的状态得到的二进制数）时，最小需要的people
//刚刚AC，差点超时，可能有更好的算法求解。目前还没有想到

class Solution {
public:
    int res;
    vector<int> res_people;
    vector<int> bit_dp;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        vector<int> is_vis(n, 0);
        unordered_map<string, int> skill2index;
        for(int i=0;i<n;++i) {
            skill2index[req_skills[i]] = i;
        }
        int pn = people.size();
        vector<vector<int>> skill_matrix(n,vector<int>()); //skill_matrix[i]表示拥有第i个skill的people的索引号
        vector<vector<int>> people_matrix(pn, vector<int>());
        for(int i=0;i<pn;++i) {
            for(int j=0;j<people[i].size();++j) {
                string skill = people[i][j];
                auto ind = skill2index.find(skill);
                if(ind == skill2index.end()) continue;
                skill_matrix[ind->second].push_back(i);
                people_matrix[i].push_back(ind->second);
            }
        }
        
        int bit=1;
        for(int i=0;i<n;++i) {
            bit_dp.push_back(bit);
            bit *= 2;
        }
        
        res = INT_MAX;
        vector<int> cur_people;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(131074, vector<int>())); //2^16=65536，保存所有的状态
        dfs(0, cur_people, is_vis, skill_matrix, people_matrix, dp);
        for(int i=0;i<dp[0].size();++i) {
            if(dp[0][i].size()==0) continue;
            if(dp[0][i].size()<res) {
                res = dp[0][i].size();
                res_people = dp[0][i];
            }
        }
        return res_people;
    }
    
    void update_vis(vector<int> & skills, vector<int> & is_vis) {
        for(int i=0;i<skills.size();++i) is_vis[skills[i]] = 1;
    }
    
    int find_next_skill(int i, vector<int> & is_vis) {
        for(int j=i;j<is_vis.size();++j) {
            if(is_vis[j]==0) return j;
        }
        return is_vis.size();
    }
    
    int get_key(vector<int> & is_vis) {
        int key=0;
        for(int i=0;i<is_vis.size();++i) {
            if(is_vis[i]==0) continue;
            key += bit_dp[i];
        }
        return key;
    }
    
    vector<int> dfs(int i, vector<int> & cur_people, vector<int> & is_vis, vector<vector<int>> & skill_matrix, vector<vector<int>> & people_matrix, vector<vector<vector<int>>> & dp) {
        if(i>=is_vis.size()) {
            return vector<int>();
        }
        int key = get_key(is_vis);
        if(dp[i][key].size() > 0) return dp[i][key];
        vector<int> people_index = skill_matrix[i];
        int min_res = INT_MAX;
        vector<int> min_rr;
        for(int j=0;j<people_index.size();++j) {
            int pindex = people_index[j];
            vector<int> new_vis = is_vis;
            update_vis(people_matrix[pindex], new_vis);
            int next_i = find_next_skill(i+1, new_vis);
            vector<int> new_people = cur_people;
            new_people.push_back(pindex);
            vector<int> tmp = dfs(next_i, new_people, new_vis, skill_matrix, people_matrix, dp);
            if(tmp.size() < min_res) {
                min_res = tmp.size();
                min_rr.clear();
                min_rr.push_back(pindex);
                min_rr.insert(min_rr.end(), tmp.begin(), tmp.end());
            }
        }
        dp[i][key] = min_rr;
        return min_rr;
    }
};
