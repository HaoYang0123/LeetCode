//Leetcode 1018
//有一个陷阱：需要防止溢出，因为A的长度是30000。

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int cur=0;
        int n=A.size();
        vector<bool> res(n, false);
        for(int i=0;i<n;++i) {
            cur = cur*2 + A[i];
            cur = (cur % 5); //注：为了避免溢出，将cur保存为除5的余数
            if(cur == 0) res[i] = true;
        }
        return res;
    }
};
