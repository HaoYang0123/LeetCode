//Leetcode 1508

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> new_nums(n*(n+1)/2, 0);
        int k=0;
        for(int i=0;i<n;++i) {
            int sum = 0;
            for(int j=i;j<n;++j) {
                sum += nums[j];
                new_nums[k++] = sum;
            }
        }
        sort(new_nums.begin(), new_nums.end());
        int res = 0;
        for(int i=left-1;i<right;++i) res += new_nums[i];
        return res;
    }
};
