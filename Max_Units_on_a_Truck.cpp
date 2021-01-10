// Leetcode 1710

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> bt;
        for(int i=0;i<boxTypes.size();++i) {
            bt.push_back(pair<int,int>(boxTypes[i][1], boxTypes[i][0]));
        }
        sort(bt.rbegin(), bt.rend());  //按units数量从高到低排序
        int cur_ind = 0, res = 0;
        while(truckSize > 0 && cur_ind < bt.size()) {
            int cur_size = min(bt[cur_ind].second, truckSize);
            truckSize -= cur_size;
            res += cur_size * bt[cur_ind].first;
            ++cur_ind;
        }
        return res;
    }
};
