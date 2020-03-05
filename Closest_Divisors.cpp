//Leetcode 1362

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int a = num+1, b = num+2;
        vector<int> res1 = find(a);
        vector<int> res2 = find(b);
        if(res1[1] - res1[0] < res2[1] - res2[0]) return res1;
        return res2;
    }
    
    inline vector<int> find(int num) {
        int a = sqrt(num);
        for(int i=a;i>=1;--i) {
            if(num % i == 0) {
                vector<int> res(2, 0);
                res[0] = i;
                res[1] = num / i;
                return res;
            }
        }
        return vector<int>(2, 0);
    }
};
