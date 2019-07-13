//Leetcode 57
//由于interval是按start从低到高排序，那么newInterval可以插入其中（保持升序关系）。
//然后对于重叠的interval进行合并，如果当前的interval的end大于等于下一个interval的start，那么两者合并
//合并的方式就是将当前的interval的end赋值为当前interval的end与下一个interval的end，两者的较大值

//阅读方法1的代码，有注释更好理解
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//方法1
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval}; //如果没有interval，直接插入并返回
        vector<vector<int>> res;
        int i=0,n=intervals.size();
        int s=newInterval[0], e=newInterval[1]; //插入的start和end
        while(i<n && intervals[i][1]<s) { //如果当前i的末尾没超过插入的start，说明没有overlap
            res.push_back(intervals[i]);
            ++i;
        }
        if(i>=n) { 
        //如果所有的interval的末尾都没超过插入的start，说明插入的是最后一个interval直接插入并返回
            res.push_back(newInterval);
            return res;
        }
        if(intervals[i][0]>e) {
        //走到i，意味着intervals[i][1]超过了start，但是intervals[i][0]也超过了end
        //意味着intervals[i]在插入的后面
            res.push_back(newInterval);
            while(i<n) res.push_back(intervals[i++]); 
            return res;
        }
        s = min(s, intervals[i][0]);
        e = max(e, intervals[i][1]);
        while(i<n && intervals[i][0]<=e) {
            e = max(e, intervals[i][1]);
            ++i;
        }
        vector<int> tmp(2,0);
        tmp[0]=s;
        tmp[1]=e;
        res.push_back(tmp);
        while(i<n) res.push_back(intervals[i++]);
        return res;
    }
};

//方法2
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
