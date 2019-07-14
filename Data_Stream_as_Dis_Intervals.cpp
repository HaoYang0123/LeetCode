//Leetcode 352

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> intervals;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> tmp(2,0);
        tmp[0]=tmp[1]=val;
        if(intervals.size() == 0) { //没有元素，直接插入
            intervals.push_back(tmp);
            return;
        }
        int n=intervals.size();
        auto cmp = [](const vector<int> & a, const vector<int> & b) { return a[0] < b[0]; };
        auto ind = lower_bound(intervals.begin(), intervals.end(), tmp, cmp);
        if(ind == intervals.begin()) { //如果intervals均比val大
            if(intervals[0][0]==val+1||intervals[0][0]==val) { //第1个interval包含了val
                intervals[0][0]=min(intervals[0][0], val);
                return;
            }
            intervals.insert(ind, tmp);
            return;
        }
        if(ind == intervals.end()) { //如果intervals均比val小
            if(intervals[n-1][1]>=val-1) { //最后1个interval包含val
                intervals[n-1][1]=max(intervals[n-1][1], val);
                return;
            }
            intervals.insert(ind, tmp);
            return;
        }
        int cur = ind - intervals.begin();
        if(intervals[cur-1][1]>=val||(intervals[cur][0]<=val&&intervals[cur][1]>=val)) { //上1个interval和当前interval包含val
            return;
        }
        if(intervals[cur-1][1]==val-1&&intervals[cur][0]==val+1) { //上1个interval和当前interval与val（val作为桥梁）将两个interval连接
            intervals[cur-1][1] = intervals[cur][1];
            intervals.erase(ind);
            return;
        }
        if(intervals[cur-1][1]==val-1) { //上1个interval包含val
            intervals[cur-1][1] = val;
            return;
        }
        if(intervals[cur][0]==val+1) { //当前interval包含val
            intervals[cur][0]=val;
            return;
        }
        intervals.insert(ind, tmp);
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
