//Leetcode 900
//不能将所有数存起来，会超内存。
//其次存储各数字出现的次数的累加和，需要使用long long（而非int），为了避免超过int表示的最大范围。

class RLEIterator {
public:
    vector<long long> numbers;
    vector<int> values;
    long long start, N;
    RLEIterator(vector<int> A) {
        numbers.resize(A.size()/2);
        values.resize(A.size()/2);
        long long cur = 0;
        for(int i=0;i<A.size();i+=2) {
            if(A[i]<=0) continue;
            cur += (long long)A[i];
            numbers.push_back(cur);
            values.push_back(A[i+1]);
        }
        start = 0;
        N = values.size();
    }
    
    int next(int n) {
        start += (long long)n;
        int s = 0, e = N-1;
        while(s<=e) {
            int mid = (s+e)/2;
            if(numbers[mid] < start) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        if (e == N-1) return -1;
        return values[e+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
