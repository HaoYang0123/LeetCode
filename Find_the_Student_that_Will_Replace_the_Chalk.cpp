// Leetcode 1894

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0; i<chalk.size(); ++i) sum += (long long)chalk[i];
        int remain = k % sum;
        int cur_sum = 0;
        for(int i=0; i<chalk.size(); ++i) {
            cur_sum += chalk[i];
            if(cur_sum > remain) return i;
        }
        return -1;
    }
};
