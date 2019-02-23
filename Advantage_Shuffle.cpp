//Leetcode 870
//贪心方法：对A排序，然后对于每个B[i]，从左到右查找第一个大于B[i]的元素，如果没使用则使用，否则继续向右查找。如果找不到，则在A中找一个仍没使用的最小的元素。

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n, 0);
        sort(A.begin(), A.end());
        vector<bool> is_used(n, false);
        int min_ind = 0;
        for(int i=0;i<n;++i) {
            int c = B[i];
            auto ind = upper_bound(A.begin(), A.end(), c); //第一个>c的值
            if(ind == A.end()) {
                while(is_used[min_ind]) min_ind++;
                is_used[min_ind] = true;
                res[i] = A[min_ind++];
                continue;
            }
            int A_ind = (ind - A.begin());
            while(A_ind<n) {
                if(!is_used[A_ind]) break;
                ++A_ind;
            }
            if(A_ind >= n) {
                while(is_used[min_ind]) min_ind++;
                is_used[min_ind] = true;
                res[i] = A[min_ind++];
                continue;
            }
            is_used[A_ind] = true;
            res[i] = A[A_ind];
        }
        return res;
    }
};
