//Leetcode 201
//O(LogN)的时间复杂度

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m&n == 0) return 0; //如果m和n二进制中没有共同的1，那么返回0
        int shift = 0;
        while(m!=n) {
            m = m>>1;
            n = n>>1;
            shift++;
        }
        return n<<shift;
    }
};
