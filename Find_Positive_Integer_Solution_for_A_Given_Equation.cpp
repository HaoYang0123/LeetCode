//Leetcode 1237
//枚举x从1-1000，然后二分查找y的值，使得f(x,y)=z（注：因为f函数是严格递增函数，所以可以进行二分查找）

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for(int x=1;x<=1000;++x) {
            int start = 1, end = 1000;
            while(start<=end) {
                int mid = (start+end)/2;
                int z2 = customfunction.f(x,mid);
                if(z2 == z) {
                    vector<int> tmp(2, 0);
                    tmp[0]=x;tmp[1]=mid;
                    res.push_back(tmp);
                    break;
                }
                else if(z2 < z) start = mid + 1;
                else end = mid - 1;
            }
        }
        return res;
    }
};
