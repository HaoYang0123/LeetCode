//Leetcode 1004
//O(N)的时间复杂度，使用两个指针i和j，分别记录头和尾。并使用z记录从i到j之间包含0的个数
//当当前0的个数<=K时，继续++j；否则，记录当前的最大值（res = max(res, j-i)），并移动i直到遇到下一个0
//最后，仍然要执行一步res = max(res,j-i)，因为有可能A中所有0的个数也没超过K，导致res=0，或者最大的长度是从某位置到达A的末尾情况。

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0;
        int z = 0; //i到j的0的个数
        int n = A.size();
        int res = 0;
        while(i<n&&j<n) {
            if(A[j] == 1) {
                ++j;
            }
            else {
                ++z;
                //cout<<"Z\t"<<z<<endl;
                if(z>K) {
                    int tmp = (j-i);
                    //cout<<j<<"\t"<<i<<endl;
                    if(tmp > res) res = tmp;
                    while(i<n && A[i]==1) ++i;
                    ++i;
                    --z;
                }
                ++j;
            }
        }
        int tmp = (j-i);
        if(tmp > res) res = tmp;
        return res;
    }
};
