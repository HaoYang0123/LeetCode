class Solution {
public:
    double Power(double base, int exponent) {
    	double res = 1.0;
        bool isF = false;
        if(exponent < 0) {
            isF = true;
            exponent = -exponent;
        }
        while(exponent != 0) {
            if(exponent % 2 == 1) {
                res *= base;
            }
            base *= base;
            exponent /= 2;
        }
        return (isF ? 1 / res : res);
    }
};
