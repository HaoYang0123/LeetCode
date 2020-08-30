//Leetcode 1562

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<vector<int>> pos2se(n, vector<int>(2,-1)); //pos2se[i]表示第i个位置的连续1的最左边和最右边的位置
        int res = -1;
        int count = 0; //当前step下，有多个连续1的数量等于m的子序列的数目
        for(int i=0;i<n;++i) {
            int c = arr[i]-1;
            if(c-1<0 || pos2se[c-1][0] == -1) { //左边没有1
                pos2se[c][0] = c;
            }
            else { //左边有1，最需要将左边的1进行合并
                if(pos2se[c-1][1]-pos2se[c-1][0]+1 == m) --count; //如果左边1的数量等于m，现在要合并，相当于将count减1
                pos2se[c][0] = pos2se[c-1][0];
            }
            if(c+1>=n || pos2se[c+1][0] == -1) { //右边没有1
                pos2se[c][1] = c;
            }
            else { //右边有1，最需要将右边的1进行合并
                if(pos2se[c+1][1]-pos2se[c+1][0]+1 == m) --count; //如果右边的1数量等于m，同样也需要将count减1
                pos2se[c][1] = pos2se[c+1][1];
            }
            pos2se[pos2se[c][0]][1] = pos2se[c][1]; //更新最左边的1的位置对应的右边位置为当前c的最右边位置
            pos2se[pos2se[c][1]][0] = pos2se[c][0]; //同上
            if(pos2se[c][1]-pos2se[c][0]+1 == m) ++count;
            if(count > 0) res = i+1;
            //cout<<i+1<<"\t"<<count<<endl;
        }
        return res;
    }
};
