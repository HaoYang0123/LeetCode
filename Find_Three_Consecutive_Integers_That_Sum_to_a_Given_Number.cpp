// Leetcod 2177

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num % 3 == 0) {
            long long one = num / 3;
            vector<long long> res = {one-1, one, one+1};
            return res;
        }
        return vector<long long>();
    }
};
