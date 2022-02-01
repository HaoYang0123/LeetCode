// Leetcode 2155

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> left_zero(n+1, 0), right_one(n+1, 0);
        //left_zero[i] 从0-(i-1)的0的个数，left_zero[1]是nums[0...0]的0个数、left_zero[2]是nums[0...1]的0个数
        //right_one[i]从(i-(n-1))的1的个数，right_one[n-1]是nums[(n-1)...(n-1)]的1个数
        for(int i=0; i<n; ++i) {
            if(nums[i] == 0) left_zero[i+1] = left_zero[i] + 1;
            else left_zero[i+1] = left_zero[i];
        }
        for(int i=n-1; i>=0; --i) {
            if(nums[i] == 1) right_one[i] = right_one[i+1] + 1;
            else right_one[i] = right_one[i+1];
        }
        vector<int> res;
        int max_sum = 0;
        for(int i=0; i<=n; ++i) {
            int cur = left_zero[i] + right_one[i];
            //cout<<i<<"\t"<<cur<<endl;
            if(cur > max_sum) {
                res.clear();
                res.push_back(i);
                max_sum = cur;
            }
            else if(cur == max_sum) res.push_back(i);
        }
        return res;
    }
};
