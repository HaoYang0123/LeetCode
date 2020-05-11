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

//方法2：使用优先队列来记录，这样不需要枚举所有路径，然后排序了。优先队列按照从小到大将前k个数据加入队列中即可
class Solution {
public:
    typedef tuple<int,int,int> iii;
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row = mat[0];
        for(int i=1;i<mat.size();++i) {
            row = get_new_row(row, mat[i], k);
        }
        return row[k-1];
    }
    
    inline vector<int> get_new_row(vector<int> & nums1, vector<int> & nums2, int k) {
        priority_queue<iii,vector<iii>,greater<iii>> qs;
        int n = nums1.size(), m = nums2.size();
        if(n == 0 || m == 0) return vector<int>();
        vector<vector<int>> is_vis(n, vector<int>(m, false));
        is_vis[0][0] = true;
        vector<int> res;
        qs.emplace(nums1[0] + nums2[0], 0, 0); //emplace的用法
        while(!qs.empty() && k--) {
            auto [v, i, j] = qs.top(); //auto的用法
            qs.pop();
            res.push_back(v);
            if(k == 0) return res;
            if(i + 1 < n && !is_vis[i+1][j]) {
                is_vis[i+1][j] = true;
                qs.emplace(nums1[i+1]+nums2[j], i+1, j);
            }
            if(j + 1 < m && !is_vis[i][j+1]) {
                is_vis[i][j+1] = true;
                qs.emplace(nums1[i]+nums2[j+1], i, j+1);
            }
        }
        return res;
    }
};
