// Leetcode 2090

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n+1, 0);
        for(int i=0; i<n; ++i) sum[i+1] = sum[i] + (long long)nums[i];
        vector<int> res(n, -1);
        int m = 2*k+1;
        for(int i=k; i<n-k; ++i) {
            //cout<<i<<"\t"<<sum[i+k+1]<<"\t"<<sum[i-k]<<endl;
            res[i] = (sum[i+k+1] - sum[i-k]) / m;
        }
        return res;
    }
};
