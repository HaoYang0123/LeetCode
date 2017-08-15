class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curRes;
        vector<vector<int>> res;
        dfs(nums, 0, curRes, res);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    
    void dfs(vector<int> & nums, int pos, vector<int> & curRes, vector<vector<int>> & res) {
        if(pos >= nums.size()) return;
        res.push_back(curRes);
        dfs(nums, pos + 1, curRes, res);
        vector<int> newRes = curRes;
        newRes.push_back(nums[pos]);
        res.push_back(newRes);
        dfs(nums, pos + 1, newRes, res);
    }
};
