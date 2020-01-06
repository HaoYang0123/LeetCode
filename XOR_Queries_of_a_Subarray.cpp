//Leetcode 1310
//arr[i] ^ ... arr[j] = (arr[0] ^ ... arr[j]) ^ (arr[0] ^ ...arr[i-1])

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for(int i=1;i<n;++i) dp[i] = dp[i-1] ^ arr[i];
        vector<int> res(queries.size(),0);
        for(int i=0;i<queries.size();++i) {
            if(queries[i][0]==0) res[i] = dp[queries[i][1]];
            else res[i] = dp[queries[i][1]] ^ dp[queries[i][0]-1];
        }
        return res;
    }
};
