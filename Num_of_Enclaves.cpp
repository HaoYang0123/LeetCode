//Leetcode 1020
//深度搜索

class Solution {
public:
    int n,m;
    int numEnclaves(vector<vector<int>>& A) {
        n=A.size();
        m=A[0].size();
        
        for(int i=0;i<n;++i) {
            if(A[i][0]==1) {
                A[i][0]=0;
                dfs(A, i, 0);
            }
            if(A[i][m-1]==1) {
                A[i][m-1]=0;
                dfs(A, i, m-1);
            }
        }
        for(int i=0;i<m;++i) {
            if(A[0][i]==1) {
                A[0][i]=0;
                dfs(A, 0, i);
            }
            if(A[n-1][i]==1) {
                A[n-1][i]=0;
                dfs(A, n-1, i);
            }
        }
        int res=0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(A[i][j]==1) ++res;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>> & A, int i, int j) {
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        for(int k=0;k<4;++k) {
            int new_i = i+r_step[k];
            int new_j = j+c_step[k];
            if(new_i>=0&&new_i<n&&new_j>=0&&new_j<m) {
                if(A[new_i][new_j]==1) {
                    A[new_i][new_j] = 0;
                    dfs(A, new_i, new_j);
                }
            }
        }
    }
};
