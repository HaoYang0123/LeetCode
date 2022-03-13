// Leetcode 2195

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i=0; i<nums.size()-1; ++i) {
            int cur = nums[i], next = nums[i+1];
            int val = next-cur-1;
            if(val <= 0) continue;
            if(k >= val) {
                // 从[cur+1, next-1]加满
                long long tmp = cur+1;
                tmp = ((tmp + next - 1) * val) / 2;
                res += tmp;
                k -= val;
            }
            else {
                //从[cur+1, cur+k]加满
                long long tmp = cur+1;
                tmp = ((tmp + cur + k) * k) / 2;
                res += tmp;
                cout<<cur<<":"<<cur + k<<":"<<res<<endl;
                return res;
            }
            //cout<<cur<<":"<<next<<":"<<res<<endl;
        }
        int cur = nums.back();
        long long tmp = cur+1;
        tmp = ((tmp + cur + k) * k) / 2;
        res += tmp;
        return res;
    }
};
