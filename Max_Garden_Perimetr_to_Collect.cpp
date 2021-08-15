//Leetcode 1954

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long left = 0, right = 1e6;
        while (left < right){
            long long mid = (left + right) / 2;
            if (squareSum(mid) >= neededApples)
                right = mid;
            else
                left = mid + 1;
        }
        if (squareSum(right) < neededApples) ++right;
        return 8 * right;
    }
    
    inline long long squareSum(long long i){ // sum of 12*i^2
        return i * (i + 1) * (2 * i + 1) * 2;
    }
};
