//Leetcode 945
//O(nLogn)时间复杂度

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for (int i=1;i<A.size();++i) {
            if (A[i]<=A[i-1]) {
                res += (A[i-1]-A[i]+1);
                A[i] = A[i-1] + 1;
            }
        }
        return res;
    }
};
