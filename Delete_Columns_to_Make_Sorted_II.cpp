//Leetcode 955

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        int l = A[0].length();
        int n = A.size();
        vector<int> is_sorted(n, false); //is_sorted[i]表示当前状态下的A[i]<=A[i+1]
        for(int i = 0; i < l; ++i) {
          int j = 0;
          for(; j < n-1; ++j) {
            if(A[j][i] > A[j+1][i] && !is_sorted[j]) {
              ++res;
              break;
             }
            }
            if(j < n-1) continue; //表示已经删除了第i个字母，则不会更新is_sorted
            for(int j = 0; j < n-1; ++j) {
              if(A[j][i] < A[j+1][i]) is_sorted[j] = true; //注：这里是<不是<=，因为如果是==的话，那么后续的字母仍然不能违反升序条件
             }
            }
           return res;
    }
};
