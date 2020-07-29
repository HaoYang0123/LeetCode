//Leetcode 1524

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        long long res = 0;
        int sum_even_num = 1, sum_odd_num = 0; //分别表示从左至右求和为偶数的数量和为奇数的数量
        int cur_sum = 0;
        for(int i=0;i<arr.size();++i) {
            cur_sum += arr[i];
            if(cur_sum % 2 == 0) {
                res = (res + sum_odd_num) % MOD;
                ++sum_even_num;
            }
            else {
                res = (res + sum_even_num) % MOD;
                ++sum_odd_num;
            }
        }
        return res;
    }
};
