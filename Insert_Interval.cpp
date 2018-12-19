//Leetcode 57
//由于interval是按start从低到高排序，那么newInterval可以插入其中（保持升序关系）。
//然后对于重叠的interval进行合并，如果当前的interval的end大于等于下一个interval的start，那么两者合并
//合并的方式就是将当前的interval的end赋值为当前interval的end与下一个interval的end，两者的较大值

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        bool isInsert = false;
        for(int i=0;i<intervals.size();++i) {
            if(intervals[i].start>newInterval.start) {
                if(!isInsert) {
                    isInsert = true;
                    intervals.insert(intervals.begin()+i, newInterval);
                }
            }
        }
        if(!isInsert) intervals.push_back(newInterval);
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i) {
            if(res.back().end>=intervals[i].start) res.back().end = max(res.back().end, intervals[i].end);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
