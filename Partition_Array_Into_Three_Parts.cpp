//Leetcode 1020
//O(N)的时间复杂度

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        for(int i=0;i<A.size();++i) sum += A[i];
        if(sum % 3  != 0) return false;
        int mean = sum/3;
        cout<<mean<<endl;
        int i=0;
        int c=0;
        for(;i<A.size()-2;++i) {
            c+=A[i];
            if(c==mean) break;
        }
        c=0;
        ++i;
        for(;i<A.size()-1;++i) {
            c+=A[i];
            if(c==mean) return true;
        }
        return false;
    }
};
