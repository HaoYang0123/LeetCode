//Leetcode 1326
//方法1：使用map从小到大记录所有的interval
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

//方法2：使用vector来存储，效率更高，时间复杂度为O(N)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> intervals;
        for(int i=0;i<ranges.size();++i) {
            if(ranges[i] == 0) continue;
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals.push_back(pair<int,int>(start,end));
        }
        sort(intervals.begin(), intervals.end(), [](auto & a, auto & b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        if(intervals.size() == 0) return -1;
        if(intervals[0].first != 0) return -1;
        int max_end = intervals[0].second;
        int res = 1;
        for(int i=1;i<intervals.size();) {
            int cur_end = max_end;
            while(i<intervals.size() && intervals[i].first <= max_end) {
                cur_end = max(cur_end, intervals[i].second);
                ++i;
            }
            if(cur_end == max_end) break;
            max_end = cur_end;
            ++res;
        }
        if(max_end < n) return -1;
        return res;
    }
};
