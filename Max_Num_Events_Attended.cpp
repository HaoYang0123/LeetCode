//Leetcode 1353

bool cmp(const vector<int> & a, const vector<int> & b) {
    return a[1] < b[1]; //按end_time从低到高排序
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),cmp);
        vector is_vis(events.back()[1]+1, 0);
        int res = 0;
        for(int i=0;i<events.size();++i) {
            for(int j=events[i][0];j<=events[i][1];++j) { //枚举[start-end]较早出现时间的event参加
                if(is_vis[j] != 0) continue;
                is_vis[j] = 1;
                ++res;
                break;
            }
        }
        return res;
    }
};
