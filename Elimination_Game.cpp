// Leetcode 390

class Solution {
public:
    int lastRemaining(int n) {
        return left2right(n);
    }
    
    inline int left2right(int n) {
        if(n <= 2) return n;
        return 2*right2left(n/2);
    }
    
    inline int right2left(int n) {
        if(n <= 2) return 1;
        if(n % 2 == 1) {  //奇数，1,2,3,4,5，保留2,4，相当于2*(1,2)-->(2,4)
            return 2*left2right(n/2);
        }
        else {  //偶数，1,2,3,4,5,6，保留1,3,5，相当于2*(1,2,3)-1 --> (1,3,5)
            return 2*left2right(n/2) - 1;
        }
    }
};
