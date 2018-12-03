//Leetcode 901
//动态规划。dp[i]+=dp[j] if data[j]<=data[i] for every j<=i, update j=j-dp[j]

class StockSpanner {
public:
    vector<int> dp, data;
    StockSpanner() {
        
    }
    
    int next(int price) {
        data.push_back(price);
        if(data.size()==1) {
            dp.push_back(1);
            return 1;
        }
        int res=1;
        int i=data.size()-2;
        while(i>=0&&data[i]<=price) {
            res += dp[i];
            i -= dp[i];
        }
        dp.push_back(res);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
