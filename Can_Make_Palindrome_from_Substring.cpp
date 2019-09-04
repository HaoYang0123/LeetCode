//Leetcode 1177

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
                int n=s.length();
		vector<vector<int>> dp(n, vector<int>(26,0)); //dp[i]记录从s[0]至s[i]区间内的各字母出现的次数
		vector<int> cur(26,0);
		for(int i=0;i<n;++i) {
			cur[int(s[i]-'a')]++;
			dp[i] = cur;
		}
		int m=queries.size();
		vector<bool> res(m, false);
		for(int i=0;i<m;++i) {
			int start = queries[i][0];
			int end = queries[i][1];
			int k = queries[i][2];
			vector<int> range = dp[end]; //range表示从s[start]至s[end]区间内的各字母出现的次数
			if(start > 0) {
				for(int j=0;j<range.size();++j) range[j] -= dp[start-1][j];
			}
			int odd_num = 0; //记录range区间内出现次数为奇数的次数，奇数的字母必须转化后才能成为回文串。
			for(int j=0;j<range.size();++j) {
				if(range[j] % 2 != 0) ++odd_num;
			}
			if(odd_num/2<=k) res[i] = true; //比如"abc"，奇数次数为3，3/2=1也即至少需要换1个字母（可以是"abc"换成"aba"）才能够成为回文串
		}
		return res;
    }
};
