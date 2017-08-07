class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; ++i) nums.push_back(i);
        vector<int> curRes;
        vector<vector<int>> res;
        dfs(nums, 0, k, curRes, res);
        return res;
    }
    void dfs(vector<int> & nums, int pos, int k, vector<int> & curRes, vector<vector<int>> & res) {
        if(curRes.size() == k) {
            res.push_back(curRes);
            return;
        }
        if(pos >= nums.size()) return;
        dfs(nums, pos + 1, k, curRes, res);
        vector<int> newRes = curRes;
        newRes.push_back(nums[pos]);
        dfs(nums, pos + 1, k, newRes, res);
    }
};