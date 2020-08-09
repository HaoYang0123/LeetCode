//Leetcode 1536

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeroAtEnd(n, 0); //每一行中从末尾开始连续0的个数
        for(int i=0;i<n;++i) {
            int cur_zero = 0;
            for(int j=n-1;j>=0;--j) {
                if(grid[i][j] != 0) break;
                ++cur_zero;
            }
            zeroAtEnd[i] = cur_zero;
        }
        
        int res = 0; 
        //最终要求：
        //zeroAtEnd[0] >= (n-1)
        //zeroAtEnd[1] >= (n-2)
        //zeroAtEnd[i] >= (n-1-i)
        for(int i=0;i<n;++i) {
            if(zeroAtEnd[i] < (n-1-i)) { //如果第i行的连续0数量小于(n-1-i)，则需要置换
                int j = i+1;
                while(j<n && zeroAtEnd[j] < (n-1-i)) ++j; //找到最近的j，满足i行的要求
                if(j == n) return -1; //如果没找到j，则说明不能置换，那么直接返回-1
                while(j > i) {
                    swap(zeroAtEnd[j], zeroAtEnd[j-1]);
                    --j;
                    ++res;
                }
            }
        }
        return res;
    }
};
