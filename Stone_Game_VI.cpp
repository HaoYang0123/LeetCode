// Leetcode 1686

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        map<int, vector<int>> sum2idx;
        for(int i=0;i<n;++i) {
            int s = aliceValues[i] + bobValues[i];
            sum2idx[s].push_back(i);
        }
        int a_sum = 0, b_sum = 0, flag = 0;
        for(auto ind = sum2idx.rbegin(); ind != sum2idx.rend(); ++ind) { //rbegin()和rend()表示根据first值（key）从高到低排序（默认是从低排序）
            vector<int> & inds = ind->second;
            for(int i=0; i<inds.size(); ++i) {
                if(flag % 2 == 0) a_sum += aliceValues[inds[i]];
                else b_sum += bobValues[inds[i]];
                ++flag;
            }
        }
        //cout<<a_sum<<"\t"<<b_sum<<endl;
        if(a_sum > b_sum) return 1;
        else if(a_sum < b_sum) return -1;
        return 0;
    }
};
