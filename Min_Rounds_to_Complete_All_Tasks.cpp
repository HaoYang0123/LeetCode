// Leetcode 2244

class Solution {
    public:
        int minimumRounds(vector<int>& tasks) {
            unordered_map<int, int> v2num;
            int max_num = 0;
            for(int i=0; i<tasks.size(); ++i) {
                v2num[tasks[i]]++;
                max_num = max(max_num, v2num[tasks[i]]);
            }
            vector<int> dp(max_num+5, 10000);
            dp[2] = 1;
            dp[3] = 1;
            for(int i=4; i<=max_num; ++i) {
                dp[i] = min(dp[i-2]+1, dp[i-3]+1);       
            }
            int res = 0;
            for(auto idx=v2num.begin(); idx!=v2num.end(); ++idx) {
                if(idx->second == 1) return -1;  //如果只有一个元素，那么无法完成
                res += dp[idx->second];
            }
            return res;
        }
    };
