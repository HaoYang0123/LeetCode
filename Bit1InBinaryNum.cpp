class Solution {
public:
     int  NumberOf1(int n) { //计算n的二进位1的个数
         int count = 0;
         while(n != 0) {
             ++count;
             n = (n - 1) & n;
         }
         return count;
     }
};
