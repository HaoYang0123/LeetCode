//Leetcode 845
//在数组中找最长的“山坡”，容易出错。WA了三次才AC。

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        if(n==0) return 0;
        int flag = 0; //0表示升，1表示降
        int cur = A[0];
        int start = 0, high = 0, res = 0;
        for(int i=1;i<n;++i) {
            if(flag == 0) {
                if(A[i]>cur) {
                    cur = A[i];
                    high = i;
                }
                else if(A[i]<cur) {
                    cur = A[i];
                    if(high>start)
                        flag = 1;
                    else start = i;
                }
                else {
                    cur = A[i];
                    start = i;
                    high = i;
                }
            }
            else {
                if(A[i]<cur) {
                    cur = A[i];
                }
                else {
                    int mon = i - start;
                    //cout<<mon<<endl;
                    if(mon > res) res = mon;
                    if(A[i]>cur)
                        start = i - 1;
                    else start = i;
                    high = i;
                    flag = 0;
                    cur = A[i];
                }
            }
        }
        if(flag == 1) {
            int mon = n - start;
            if(mon > res) res = mon;
        }
        return res;
    }
};
