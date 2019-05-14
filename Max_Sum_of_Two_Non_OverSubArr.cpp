//Leetcode 1031
//枚举L在左M在右的情况，及L在右M在左的情况

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n=A.size();
        vector<int> s(n, 0);
        s[0] = A[0];
        for(int i=1;i<n;++i) s[i]+=s[i-1]+A[i];
        int res=0;
        for(int i=0;i<=n-L;++i) {
            int v=s[i+L-1];
            if(i>0) v-=s[i-1];
            for(int j=i+L;j<=n-M;++j) {
                int v2 = s[j+M-1] - s[j-1];
                if(v+v2>res) res=v+v2;
            }
        }
        for(int i=0;i<=n-M;++i) {
            int v=s[i+M-1];
            if(i>0) v-=s[i-1];
            for(int j=i+M;j<=n-L;++j) {
                int v2 = s[j+L-1] - s[j-1];
                if(v+v2>res) res=v+v2;
            }
        }
        return res;
    }
};
