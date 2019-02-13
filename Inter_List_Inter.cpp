//Leetcode 986

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval & a, const Interval & b) {
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        sort(A.begin(), A.end(), cmp);
        vector<int> starts(A.size(), 0), ends(A.size(), 0);
        for(int i=0;i<A.size();++i) {
            starts[i] = A[i].start;
            ends[i] = A[i].end;
        }
        vector<Interval> res;
        for(int i=0;i<B.size();++i) {
            int s=B[i].start,e=B[i].end;
            auto ind = lower_bound(starts.begin(),starts.end(),s);
            auto end_ind = ends.begin() + (ind-starts.begin());
            auto old_ind = ind, old_end_ind = end_ind;
            if(ind != starts.begin()) {
                while(end_ind > ends.begin() && *(end_ind-1)>=s) {
                    int new_e = min(*(end_ind-1), e);
                    res.push_back(Interval(s,new_e));
                    --end_ind;
                    --ind;
                }
            }
            ind = old_ind;
            end_ind = old_end_ind;
            if(ind != starts.end()) {
                while(ind < starts.end() && *ind <= e) {
                    int new_e = min(*(end_ind), e);
                    res.push_back(Interval(*ind, new_e));
                    ++ind;
                    ++end_ind;
                }
            }
        }
        return res;
    }
};
