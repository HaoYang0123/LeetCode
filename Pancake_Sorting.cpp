//Leetcode 969
//使用最大变换数目不超过2*n。时间复杂度为O(N^2)。每次找到当前最大的元素，假设索引为i，那么将0-i的进行反转后，最大元素在0位置，然后将所有当前元素反转
//比如：原始数组为3,2,4,1，最大元素是4，在索引2位置。反转后得到4,2,3,1。再全部反转得到1,3,2,4。
//接下来只用考虑前三个元素(1,3,2)，那么最大元素在索引1位置，反转后得到3,1,2，再全部反转得到2,1,3。
//依次类推。当然在写程序时，两次反转不需要全部模拟出来，可以找到一些规律。

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        int n = A.size();
        for(int i=n;i>=1;--i) {
            int ind = find(A, i);
            if(ind != i-1) {
                res.push_back(ind+1);
                //cout<<ind+1<<endl;
                //write_vec(A);
                int last = A[i-1];
                A[i-1] = i;
                vector<int> tmp;
                if(i-ind-2>0) {
                    tmp.resize(i-ind-2, 0);
                    for(int j=0;j<i-ind-2;++j) tmp[j] = A[j+ind+1];
                }
                //cout<<"I:\t"<<i-ind-1<<endl;
                for(int j=i-2;j>=i-ind-1;--j) A[j] = A[j-i+ind+1];
                for(int j=1;j<=tmp.size();++j) A[j] = tmp[i-ind-2-j];
                A[0] = last;
                res.push_back(i);
                //cout<<i<<endl;
                //write_vec(A);
            }
        }
        return res;
    }
    int find(vector<int> & A, int n) {
        for(int i=0;i<n;++i) {
            if(A[i] == n) return i;
        }
        return -1;
    }
    void write_vec(vector<int> & A) {
        for(int i=0;i<A.size();++i) cout<<A[i]<<"\t";
        cout<<endl;
    }
};
