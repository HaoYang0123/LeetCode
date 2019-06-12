//Leetcode 42
//O(N)的时间复杂度及O(1)的空间复杂度

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int res = 0, cur_res = 0;
        int j = 0; 
        int i=0, h=height[0], n=height.size();
        for(;i<n;++i) { //从左往右扫描
            if(height[i] < h) { //如果当前高度比之前的高度低，将累积的水量加入到cur_res中
                cur_res += (h-height[i]);
            }
            else { //否则，cur_res的水量才可以加入到res中，并更新h和j，j表示递增的位置
                res += cur_res;
                cur_res = 0;
                h = height[i];
                j = i;
            }
        }
        cur_res = 0;
        h=height[n-1];
        i=n-1;
        for(;i>=j;--i) { //从右向左扫描，直到j的位置（因为j之前的位置已经处理过），j的含义其实就是数组中的最高位置
            if(height[i] < h) {
                cur_res += (h-height[i]);
            }
            else {
                res += cur_res;
                cur_res = 0;
                h = height[i];
            }
        }
        return res;
    }
};
