//Leetcode 1326

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        map<int,int> start2end;
        for(int i=0;i<ranges.size();++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            start2end[start] = max(start2end[start], end);
        }
        if(start2end.find(0) == start2end.end()) return -1;
        int max_end = start2end[0];
        int res = 1;
        while(max_end < n) {
            int cur_end = max_end;
            for(auto ind = start2end.begin(); ind != start2end.end(); ++ind) {
                if(ind->first > max_end) break;
                //if(ind->second < cur_end) start2end.erase(ind->first);
                cur_end = max(cur_end, ind->second);
            }
            if(cur_end == max_end) break;
            ++res;
            max_end = cur_end;
        }
        if(max_end < n) return -1;
        return res;
    }
};
