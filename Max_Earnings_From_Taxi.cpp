// Leetcode 2008

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n+1, 0);
        map<int, vector<int>> end2pos;
        for(int i=0; i<rides.size(); ++i) end2pos[rides[i][1]].push_back(i);
        long long res = 0;
        int old_end = 0;
        for(auto ind = end2pos.begin(); ind != end2pos.end(); ++ind) {
            vector<int> & curpos = ind->second;
            int cur_end = ind->first;
            for(int i=0; i<curpos.size(); ++i) {
                int rid_i = curpos[i];
                long long one = rides[rid_i][1] - rides[rid_i][0] + rides[rid_i][2];
                dp[cur_end] = max(dp[cur_end], one + dp[rides[rid_i][0]]);
            }
            dp[cur_end] = max(dp[cur_end], dp[old_end]);
            if(ind != end2pos.end()) {
                auto ind2 = ind;
                ++ind2;
                int next_end = ind2->first;
                for(int i=cur_end; i<next_end; ++i) dp[i] = dp[cur_end];
            }
            old_end = cur_end;
            res = max(res, dp[cur_end]);
            //cout<<cur_end<<"\t"<<curpos.size()<<"\t"<<dp[cur_end]<<endl;
        }
        return res;
    }
};
