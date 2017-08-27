//有一群小孩子，每个小孩有个打分。
//分蛋糕，找到最小的蛋糕数目，需要满足以下两个条件：
//1. 每个小孩必须有蛋糕(>=1)
//2. 当前小孩的打分比左右两个邻居要大，则分的蛋糕需要大于左右两个邻居的蛋糕

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1) return n;
        vector<int> cand(n, 1); //初始化每个小孩一个蛋糕
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i - 1]) cand[i] = cand[i - 1] + 1; //如果i的打分比左邻居要大，则比左邻居多分配一个蛋糕
        }
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1]) cand[i] = max(cand[i], cand[i + 1] + 1); //如果i的打分比右邻居要大，则比右邻居多分配一个蛋糕
        }
        int res = 0;
        for(int i = 0; i < n; ++i) res += cand[i];
        return res;
    }
};
