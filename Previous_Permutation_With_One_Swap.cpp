//Leetcode 1053

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n=A.size();
        int i=n-1;
        for(;i>0;--i) {
            if(A[i]<A[i-1]) break;
        }
        if(i==0) return A;
        int ind = lower_bound(A.begin()+i,A.end(),A[i-1])-A.begin(); //第一个大于等于A[i-1]的索引位置
        --ind; //最后一个小于A[i-1]的索引位置
        int t=A[ind];
        while(ind>=i) { //需要找到第一个小于A[i-1]的索引位置，比如: 3,1,1,3，ind指向的是第二个1，通过while循环找到第一个1，然后交换得到：1,3,1,3
            if(A[ind]==t) --ind;
            else break;
        }
        A[ind+1] = A[i-1];
        A[i-1] = t;
        return A;
    }
};
