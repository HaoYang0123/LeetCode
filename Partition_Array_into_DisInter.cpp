//Leetcode 915
//O(n)时间复杂度

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> left(n, 0), right(n, 0); //left[i]存储[0,i]中最大值，right[i]存储[i,n-1]中最小值
        left[0] = A[0];
        right[n-1] = A[n-1];
        for(int i=1;i<n;++i) {
            left[i] = max(left[i-1],A[i]);
        }
        for(int i=n-2;i>=0;--i) {
            right[i] = min(right[i+1], A[i]);
        }
        int i=0;
        for(;i<n-1;++i) {
            if(left[i]<=right[i+1]) {
                return i+1;
            }
        }
        return n;
    }
};
