//Leetcode 822
//时间复杂度O(N)

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        map<int, set<int>> mm;
        int n=fronts.size();
        for(int i=0;i<n;++i) {
            int f=fronts[i], b=backs[i];
            mm[f].insert(b);
        }
        int res = INT_MAX;
        //Flip得到的最小值
        for(auto ind = mm.begin(); ind != mm.end(); ++ind) {
            set<int> s = ind->second;
            int key = ind->first;
            if(s.find(key) == s.end()) {
                res = key;
                break;
            }
        }
        //不Flip得到的最小值
        int res2 = INT_MAX;
        //sort(backs.begin(), backs.end());
        for(int i = 0; i < n; ++i) {
            if(mm.find(backs[i]) == mm.end()) {
                res2 = min(res2, backs[i]);
            }
        }
        res = min(res, res2);
        if(res == INT_MAX) res = 0;
        return res;
    }
};
