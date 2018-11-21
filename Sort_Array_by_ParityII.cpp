//Leetcode 922

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        //vector<int> res = A;
        int i=0,j=1;
        while(i<A.size() && j<A.size()) {
          if(A[i] % 2 == 0) { 
            i += 2;
            continue;
          }
          if(A[j] % 2 == 1) { 
            j += 2;
            continue;
          }
          int tmp = A[i];
          A[i] = A[j];
          A[j] = tmp;
        }
        return A;
    }
};
