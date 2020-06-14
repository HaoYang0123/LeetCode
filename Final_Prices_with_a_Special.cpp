//Leetcode 1475

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> res(n,0);
        for(int i=0;i<n;++i) {
            int j=i+1;
            for(;j<n;++j) {
                if(prices[j]<=prices[i]) break;
            }
            if(j<n) res[i] = prices[i]-prices[j];
            else res[i] = prices[i];
        }
        return res;
    }
};
