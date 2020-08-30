//Leetcode 1561

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int count = piles.size()/3;
        int i = 1, res = 0;
        while(count--) {
            res += piles[i];
            i += 2;
        }
        return res;
    }
};
