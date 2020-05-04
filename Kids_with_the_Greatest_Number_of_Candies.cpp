//Leetcode 1431

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_value = 0;
        for(int i=0;i<candies.size();++i) max_value = max(max_value, candies[i]);
        max_value -= extraCandies;
        vector<bool> res(candies.size(), false);
        for(int i=0;i<candies.size();++i) {
            if(candies[i] >= max_value) res[i] = true;
        }
        return res;
    }
};
