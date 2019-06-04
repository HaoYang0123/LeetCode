//Leetcode 1072
//O(N*M)的时间复杂度

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<string, int> mm;
        int res = 0;
        for(int i=0;i<n;++i) {
            string key1 = "", key2 = "";
            for(int j=0;j<m;++j) {
                key1 += (char)(matrix[i][j]-0 + '0'); //将一行的0,1值作为一个字符串
                int t = (matrix[i][j]==0 ? 1 : 0); //考虑一行的0,1转成1,0值的字符串
                key2 += (char)(t-0 + '0');
            }
            //cout<<key1<<"\t"<<key2<<endl;
            mm[key1]++;
            mm[key2]++;
            if(mm[key1] > res) res = mm[key1];
            if(mm[key2] > res) res = mm[key2];
        }
        return res;
    }
};
