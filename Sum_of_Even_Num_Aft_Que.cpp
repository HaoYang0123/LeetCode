//Leetcode 985

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size();
        vector<bool> is_even(n, false);
        int sum = 0;
        for(int i=0;i<n;++i) {
            if(A[i] % 2 == 0) {
                is_even[i] = true;
                sum += A[i];
            }
        }
        vector<int> res(queries.size(), 0);
        for(int i=0;i<queries.size();++i) {
            int val = queries[i][0];
            int ind = queries[i][1];
            if(is_even[ind]) { //之前是偶数
                if(val % 2 == 0) { //增加的也是偶数，那么sum = sum + val
                    sum += val;
                    A[ind] += val;
                }
                else { //增加的是奇数，那么sum = sum-A[ind]，并且更新is_even
                    sum -= A[ind];
                    A[ind] += val;
                    is_even[ind] = false;
                }
            }
            else { //之前的是奇数
                if(val % 2 == 0) { //增加的是偶数，那么sum和is_even均不更新
                    A[ind] += val;
                }
                else { //增加的是奇数，那么sum = sum + (A[ind] + val)，并更新is_even
                    sum += (A[ind] + val);
                    A[ind] += val;
                    is_even[ind] = true;
                }
            }
            res[i] = sum;
        }
        return res;
    }
};
