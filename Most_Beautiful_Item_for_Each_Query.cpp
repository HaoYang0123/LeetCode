// Leetcode 2070

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());  //按第1个数字，从小到大排序
        vector<int> res(queries.size(), 0);
        map<int, vector<int>> q2idx;
        for(int i=0; i<queries.size(); ++i) q2idx[queries[i]].push_back(i);
        int i = 0, cur_max = 0;
        for(auto ind=q2idx.begin(); ind != q2idx.end(); ++ind) {
            int qv = ind->first;
            vector<int> & idx_list = ind->second;
            for(int j = 0; j < idx_list.size(); ++j) {
                int idx = idx_list[j];
                while(i < items.size() && items[i][0] <= qv) {
                    cur_max = max(cur_max, items[i][1]);
                    ++i;
                }
                res[idx] = cur_max;
            }
        }
        return res;
    }
};
