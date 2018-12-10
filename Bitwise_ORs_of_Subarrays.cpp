//Leetcode 898
//O(NlogW)=O(32N)的时间复杂度，W为int最大表示范围，所以是32N。

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        set<int> cur,res;
        for(int i=0;i<A.size();++i) {
            set<int> new_s;
            for(auto ind = cur.begin();ind != cur.end();++ind) {
                int n = *ind | A[i];
                res.insert(n);
                new_s.insert(n);
            }
            new_s.insert(A[i]);
            res.insert(A[i]);
            cur = new_s;
        }
        return res.size();
    }
};
