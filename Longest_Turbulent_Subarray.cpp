//Leetcode 978
//O(N)的时间复杂度

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()==1) return 1;
        int res=1;
        if(A[1]!=A[0]) res=2;
        int cur = res;
        for(int i=2;i<A.size();++i) {
            if(A[i]>A[i-1]) {
                if(A[i-1]<A[i-2]) ++cur;
                else {
                    if(cur>res) res = cur;
                    cur = 2;
                }
            }
            else if(A[i]<A[i-1]){
                if(A[i-1]>A[i-2]) ++cur;
                else {
                    if(cur>res) res = cur;
                    cur = 2;
                }
            }
            else {
                if(cur>res) res = cur;
                cur = 1;
            }
        }
        if(cur>res) res = cur;
        return res;
    }
};
