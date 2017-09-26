//LeetCode 638

class Solution {
public:
    bool isOK(vector<int> & needs) {
        for(int i = 0; i < needs.size(); ++i) {
            if(needs[i] != 0) return false;
        }
        return true;
    }
    int canS(vector<int> & spec, vector<int> & needs) {
        int res = INT_MAX;
        for(int i = 0; i < needs.size(); ++i) {
            int t = INT_MAX;
            if(spec[i] > 0) t = needs[i] / spec[i];
            if(t < res) res = t;
        }
        return res;
    }
    void dfs(vector<int> & price, vector<vector<int>> & special, vector<int> & needs, int & curPrice, int & minPrice) {
        if(isOK(needs)) {
            if(curPrice < minPrice) minPrice = curPrice;
            return;
        }
        for(int i = 0; i < special.size(); ++i) {
            int count = canS(special[i], needs);
            //cout<<curPrice<<"\t"<<i<<"\t"<<count<<endl;
            if(count == INT_MAX || count == 0) continue;
            vector<int> newNeeds(needs);
            for(int j = 0; j < needs.size(); ++j) newNeeds[j] -= count * special[i][j];
            int newPrice = curPrice + count * special[i].back();
            dfs(price, special, newNeeds, newPrice, minPrice);
        }
        int newPrice = curPrice;
        for(int i = 0; i < needs.size(); ++i) {
            newPrice += price[i] * needs[i];
        }
        if(newPrice < minPrice) minPrice = newPrice;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int curPrice = 0, minPrice = INT_MAX;
        dfs(price, special, needs, curPrice, minPrice);
        return minPrice;
    }
};
