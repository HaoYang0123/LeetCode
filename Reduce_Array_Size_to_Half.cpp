//Leetcode 1338

bool cmp(const pair<int,int> & a, const pair<int,int> & b) {
    return a.second > b.second;
}

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> val2num;
        for(int i=0;i<arr.size();++i) {
            val2num[arr[i]]++;
        }
        vector<pair<int,int>> data;
        for(auto ind = val2num.begin(); ind != val2num.end(); ++ind) {
            data.push_back(pair<int,int>(ind->first, ind->second));
        }
        sort(data.begin(), data.end(), cmp);
        int res = 0;
        int delete_num = 0, cur_index = 0;
        int half_num = arr.size()/2;
        while(delete_num < half_num) {
            ++res;
            delete_num += data[cur_index++].second;
        }
        return res;
    }
};
