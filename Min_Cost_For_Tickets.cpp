//Leetcode 983

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(367, 0); //dp[i]表示从第i天开始的费用。
        int d = days[0]; //第一天开始
        int one_c = costs[0], week_c = costs[1], month_c = costs[2];
        return dfs(d, days, dp, one_c, week_c, month_c);
    }
    
    int dfs(int start_day, vector<int> & days, vector<int> & dp, int one_c, int week_c, int month_c) {
        //cout<<start_day<<endl;
        if(days[days.size()-1] < start_day) return 0;
        if(days[days.size()-1] == start_day) return min(one_c, min(week_c, month_c));
        if(dp[start_day] != 0) return dp[start_day];
        auto ind1 = lower_bound(days.begin(), days.end(), start_day+1);
        int a = 0, b = 0, c = 0;
        if(ind1 != days.end()) a = dfs(*ind1, days, dp, one_c, week_c, month_c);
        int res = a + one_c;
        auto ind2 = lower_bound(days.begin(), days.end(), start_day+7);
        if(ind2 != days.end()) b = dfs(*ind2, days, dp, one_c, week_c, month_c);
        res = min(res, b + week_c);
        auto ind3 = lower_bound(days.begin(), days.end(), start_day+30);
        if(ind3 != days.end()) c = dfs(*ind3, days, dp, one_c, week_c, month_c);
        res = min(res, c + month_c);
        dp[start_day] = res;
        //cout<<start_day<<"\t"<<res<<endl;
        return res;
    }
};
