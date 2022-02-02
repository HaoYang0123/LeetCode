// Leetcode 2055

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> dp(n+1, 0);  //dp[i]表示从s[0...i]中的*数量
        vector<int> cands;  //表示candle的索引位置
        for(int i=0; i<n; ++i) {
            int star_num = 0;
            if(s[i] == '*') star_num = 1;
            else cands.push_back(i);
            dp[i+1] = dp[i] + star_num;
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for(int i=0; i<m; ++i) {
            int s=queries[i][0], e=queries[i][1];
            auto idx1 = lower_bound(cands.begin(), cands.end(), s);  //找到第1个大于等于s的candle位置
            auto idx2 = upper_bound(cands.begin(), cands.end(), e);  //找到第1个大于e的candle位置
            if(idx1 == cands.end() || idx2 == cands.begin()) continue;  //没找到
            --idx2;  //最后1个小于等于e的candle位置
            //if(*idx1 == *idx2) continue;  
            //cout<<i<<"\t"<<*idx1<<"\t"<<*idx2<<endl;
            int left = *idx1, right = *idx2;
            if(left >= right) continue;  //表示[s,e]范围内只有1个candle，这无法形成left和right均有candle的条件
            res[i] = dp[right+1] - dp[left];
        }
        return res;
    }
};
