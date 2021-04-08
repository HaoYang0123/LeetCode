// Leetcode 1817

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> user2min;
        for(int i=0;i<logs.size();++i) {
            user2min[logs[i][0]].insert(logs[i][1]);
        }
        unordered_map<int, int> UAM2num;
        for(auto ind = user2min.begin(); ind != user2min.end(); ++ind) {
            int UAM = ind->second.size();
            UAM2num[UAM]++;
        }
        vector<int> res(k, 0);
        for(int i=0;i<k;++i) res[i] = UAM2num[i+1];
        return res;
    }
};
