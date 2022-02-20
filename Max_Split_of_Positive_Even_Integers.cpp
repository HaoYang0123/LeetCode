// Leetcode 2178

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 != 0) return res;
        int c = 2;
        while(finalSum > 2 * c) {
            finalSum -= c;
            res.push_back(c);
            c += 2;
        }
        res.push_back(finalSum);
        return res;
    }
};
