//Leetcode 1414

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        //将所有小于等于k的Fibonacci数，加入至fib中
        while(fib[fib.size()-1]<=k) {
            fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
        }
        int res = 0;
        while(k > 0) {
            auto ind = upper_bound(fib.begin(), fib.end(), k); //每次找到最大的<=k的fibonacci数
            ++res;
            k -= *(--ind);
            //cout<<"K\t"<<k<<endl;
        }
        return res;
    }
};
