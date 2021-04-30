// Leetcode 1823

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> dp(n, false);
        int start = 0;
        for(int i=0;i<n;++i) {
            start = get_index(dp, start, k);
            //cout<<i<<"\t"<<start<<endl;
            dp[start] = true;
        }
        return start + 1;
    }
    
    inline int get_index(vector<bool> & dp, int index, int k) {
        int start = index;
        while(k > 0) {
            if(!dp[start]) {
                --k;
                if(k == 0) {
                    return start;
                }
            }
            ++start;
            if(start == dp.size()) start = 0;
        }
        return 0;
    }
};
