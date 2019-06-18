//Leetcode 1090
//贪心算法，O(NlogN)的时间复杂度。对values从大到小排序，从大到小获取元素
//如果当前元素的label超过use_limit，则不能取该元素；继续往后走，直到取完num_wanted个元素。

bool cmp(pair<int, int> & a, pair<int, int> & b) {
    return a.first > b.first;
}

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> data;
        int n = values.size();
        for(int i=0;i<n;++i) {
            data.push_back(pair<int,int>(values[i], labels[i]));
        }
        sort(data.begin(), data.end(), cmp);
        //for(int i=0;i<n;++i) cout<<data[i].first<<"\t"<<data[i].second<<endl;
        unordered_map<int, int> label_map; //label_map[k]表示labels为k的已经有多少，超过use_limit就不能再选了
        int res = 0;
        for(int i=0;i<n&&num_wanted>0;++i) {
            int l = data[i].second;
            label_map[l] += 1;
            if(label_map[l] <= use_limit) {
                res += data[i].first;
                --num_wanted;
            }
        }
        return res;
    }
};
