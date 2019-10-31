//Leetcode 1237
//方法1：枚举x从1-1000，然后二分查找y的值，使得f(x,y)=z（注：因为f函数是严格递增函数，所以可以进行二分查找）
//方法1的时间复杂度为O(N*logN)

//方法2：可以将x和y从1-1000，形成的矩阵，矩阵从左到右、从上到下严格递增
//所以可以直接先让x=1,y=1000（即矩阵的左下角），计算当前f(x,y)，如果>z，则--y（因为比y大的不用考虑）；如果<z，则++x；
//方法2的时间复杂度更小，为O(2*N)

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

//方法2：
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int x=1,y=1000;
        vector<vector<int>> res;
        while(x<=1000 && y>=1) {
            int f = customfunction.f(x,y);
            //cout<<x<<"\t"<<y<<"\t"<<f<<endl;
            if(f>z) --y;
            else if(f<z) ++x;
            else {
                vector<int> tmp(2,0);
                tmp[0]=x;tmp[1]=y;
                --y; //或者++x
                res.push_back(tmp);
            }
        }
        return res;
    }
};
