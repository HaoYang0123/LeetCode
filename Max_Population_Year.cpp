// Leetcode 1854

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int,int> y2n;
        for(int i=0; i<logs.size(); ++i) {
            int s = logs[i][0], e = logs[i][1];
            for(int j=s; j<e; ++j) y2n[j]++;
        }
        int res = -1, max_p = INT_MIN;
        for(auto ind=y2n.begin(); ind != y2n.end(); ++ind) {
            int y = ind->first, p = ind->second;
            if(p > max_p) {
                max_p = p;
                res = y;
            }
            else if(p == max_p) {
                res = min(res, y);
            }
        }
        return res;
    }
};
