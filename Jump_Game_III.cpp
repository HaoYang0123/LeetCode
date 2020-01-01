//Leetcode 1306

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> dp(n,-1); //dp[0]=1表示从i位置能够到达value=0，=0表示不能到达
        vector<bool> is_vis(n,false);
        is_vis[start] = true;
        return is_next(arr, dp, is_vis, start);
    }
    
    bool is_next(vector<int> & arr, vector<int> & dp, vector<bool> & is_vis, int start) {
        if(dp[start] != -1) return dp[start];
        if(arr[start] == 0) return true;
        int newpos1 = start + arr[start], newpos2 = start - arr[start];
        if(newpos1 < arr.size() && !is_vis[newpos1]) {
            is_vis[newpos1] = true;
            if(is_next(arr, dp, is_vis, newpos1)) {
                dp[start] = true;
                return true;
            }
        }
        if(newpos2 >= 0 && !is_vis[newpos2]) {
            is_vis[newpos2] = true;
            if(is_next(arr, dp, is_vis, newpos2)) {
                dp[start] = true;
                return true;
            }
        }
        dp[start] = false;
        return false;
    }
};
