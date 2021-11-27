// Leetcode 519

class Solution {
public:
    int m,n,total;
    unordered_map<int,int> p2p;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m*n;
        reset();
        srand(time(NULL));
    }
    
    vector<int> flip() {
        int x = rand() % total;
        --total;
        vector<int> res(2, 0);
        if(p2p.find(x) != p2p.end()) {  //此位置已经为1，则用p2p[x]作为采样值，因为p2p[x]一定是为0的
            int nx = p2p[x];
            res[0] = nx / n;
            res[1] = nx % n;
        }
        else {
            res[0] = x / n;
            res[1] = x % n;
        }
        //将x与total进行互换
        if(p2p.find(total) != p2p.end()) {  //如果p2p[total]已经有值，证明total位置已经为1，那么得将x与p2p[total]位置互换
            p2p[x] = p2p[total];
        }
        else {
            p2p[x] = total;
        }
        return res;
    }
    
    void reset() {
        total = m*n;
        p2p.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
