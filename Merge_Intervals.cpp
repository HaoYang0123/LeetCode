//Leetcode 56
//interval的start从小到大排序，然后从左到右扫描，判断如果interval[i][1]>=interval[i+1][0]，则将[i+1]与[i]合并

bool cmp(const vector<int> & a, const vector<int> & b) {
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        //for(int i=0;i<n;++i) cout<<intervals[i][0]<<"\t"<<intervals[i][1]<<endl;
        vector<vector<int>> res;
        int a=intervals[0][0],b=intervals[0][1];
        for(int i=1;i<n;++i) {
            //cout<<intervals[i][0]<<"\t"<<intervals[i][1]<<"\t"<<a<<"\t"<<b<<endl;
            if(intervals[i][0]<=b) b=max(b,intervals[i][1]);
            else {
                vector<int> tmp(2,0);
                tmp[0]=a;
                tmp[1]=b;
                res.push_back(tmp);
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }
        vector<int> tmp(2,0);
        tmp[0]=a;
        tmp[1]=b;
        res.push_back(tmp);
        return res;
    }
};
