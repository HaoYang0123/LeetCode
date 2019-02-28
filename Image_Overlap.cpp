//Leetcode 835
//O(N^4)时间复杂度
//枚举A中所有1的位置与B中所有1的位置的相对位置情况，比如：A[x1][y1]与B[x2][y2]的相对位置表示为(x2-x1)与(y2-y1)，记录该相对位置+1
//最终相对位置最多的计数表示结果

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        unordered_map<int, int> mm;
        int res = 0;
        for(int i=0;i<N*N;++i) {
            int x1 = i / N, y1 = i % N;
            if(A[x1][y1] == 0) continue;
            for(int j=0;j<N*N;++j) {
                int x2 = j / N, y2 = j % N;
                if(B[x2][y2] == 0) continue;
                //pair<int, int> pos(x2-x1, y2-y1);
                int pos = (x2-x1)*100 + (y2-y1);
                mm[pos]++;
                res = max(res, mm[pos]);
            }
        }
        return res;
    }
};
