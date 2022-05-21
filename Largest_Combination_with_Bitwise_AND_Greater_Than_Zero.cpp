// Leetcode 2275

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> dp(33, 0);  //一个int元素，转成2进制，dp[i]表示2进制数第i为1的元素数量
        //最终答案就是哪个2进制数位置元素数量最多的则为答案
        for(int i=0; i<candidates.size(); ++i) {
            vector<int> one_bit = get_bit(candidates[i]);
            //cout<<candidates[i]<<endl;
            //for(int j=0; j<one_bit.size(); ++j) cout<<one_bit[j]<<" ";
            //cout<<endl;
            for(int j=0; j<one_bit.size(); ++j) {
                if(one_bit[j] == 1) ++dp[j];
            }
        }
        int res = 0;
        for(int i=0; i<dp.size(); ++i) res = max(res, dp[i]);
        return res;
    }
    
    inline vector<int> get_bit(int a) {
        vector<int> res;
        while(a>0) {
            res.push_back(a%2);
            a/=2;
        }
        return res;
    }
};
