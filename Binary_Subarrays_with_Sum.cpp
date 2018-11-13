//Leetcode 930
//O(n)复杂度，保存为1的索引，然后两两求和。但是需要判断边界条件，比如S=0的情况

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> one_index;
        for(int i=0;i<A.size();++i) {
            if(A[i] == 1) one_index.push_back(i);
        }
        if(S == 0) {
            int res = 0;
            if(one_index.size() == 0) return (A.size()*(A.size()+1)) / 2;
            for(int i=0;i<one_index.size();++i) {
                int v=one_index[i];
                if(i==0) res += (v*(v+1))/2;
                else {
                    int v2=one_index[i]-one_index[i-1]-1;
                    res += (v2*(v2+1))/2;
                }
            }
            int v=A.size()-1-one_index[one_index.size()-1];
            res += (v*(v+1))/2;
            return res;
        }
        int res = 0;
        for(int i=0;i<=(int)one_index.size()-S;++i) {
            int start=i,end=i+S-1;
            int left=1,right=1;
            if(start-1>=0) left = one_index[start]-one_index[start-1];
            else left = one_index[start] + 1;
            if(end+1<one_index.size()) right = one_index[end+1]-one_index[end];
            else right = A.size() - one_index[end];
            res += left*right;
        }
        return res;
    }
};
