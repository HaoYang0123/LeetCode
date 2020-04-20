//Leetcode 1411

class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1000000007;
        long long x = 6, y = 6; 
        //x表示当前行（3个元素）颜色不一样的个数；比如：红、黄、绿
        //y表示当前行颜色第1个和第3个颜色一样 的个数；比如：红、黄、红
        //只有这两种情况；第一行：x和y分别为6，总共为12种情况
        for(int i=1;i<n;++i) {
            //可以画一下例子：比如当前是：红、黄、绿（不一样颜色）
            //下一步同样也是不一样颜色的情况数量有2种：绿、红、黄；黄、绿、红
            //如果考虑到当前是：红、黄、红
            //下一步同样也是不一样颜色的情况数量也有2种：绿、红、黄；黄、红、绿
            //所以，newx = 2*x+2*y
            long long newx = 2 * (x+y) % MOD;
            long long newy = (2 * x + 3 * y) % MOD;
            x = newx;
            y = newy;
        }
        return (x+y) % MOD;
    }
};
