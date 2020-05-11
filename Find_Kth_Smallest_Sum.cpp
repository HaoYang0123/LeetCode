//Leetcode 1439

//方法1：全枚举，保留当前行中所有路径是的前k条求和情况，时间复杂度为O(n*m*k)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row(mat[0]);
        for(int i = 1; i < mat.size(); ++i) {
            vector<int> nr;  // next row
            for(int j = 0; j < mat[i].size(); ++j)                          
                for(auto pathSum : row) 
                    nr.push_back(mat[i][j] + pathSum); // all possible path ends at [i,j] by far                    
                            
            sort(nr.begin(), nr.end());            
            nr.resize( min(k, int(nr.size())) );
            row=move(nr);         
            //row = vector<int>(nr.begin(), nr.begin() + min(k, int(nr.size())) ); //ok   
            //swap(row, nr); // ok
            //row=nr;        // ok            
        }        
        return row[k-1];
    }
};
