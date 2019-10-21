//Leetcode 1227
//方法1：1)乘客1直接坐到自己位置，概率为1/n;2）乘客1不坐自己位置也不坐第n个位置，概率为(n-2)/n，此时，其余n-1个人相当于一个（n-1）子问题
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n==1) return 1.0;
        return 1.0/n+(n-2)*nthPersonGetsNthSeat(n-1)/n;
    }
};

//方法2：
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n==1) return 1.0;
        return 0.5;
    }
};
