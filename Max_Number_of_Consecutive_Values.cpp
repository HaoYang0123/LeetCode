// Leetcode 1798

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int x = 0;  //目前只能覆盖[0, x]
        for(int i = 0; i< coins.size(); ++i) {
            int y = coins[i];
            if(y > x+1) return x+1;  //如果y比x+1大，那么就不能继续往后覆盖了
            //当前能够覆盖[0, x]，当前最小值是y，如果y<=x+1，那么当前就可以覆盖至[0, x+y]
            x += y;  
        }
        return x+1;
    }
};
