//Leetcode 1653

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> a_num(n, 0), b_num(n, 0);
        //a_num[i]记录从i至末尾的a的数量
        //b_num[i]记录从起始至i的b的数量
        int cur_b = 0, cur_a = 0;
        for(int i=0; i<n; ++i) {
            if(s[i] == 'b') ++cur_b;
            b_num[i] = cur_b;
        }
        for(int i=n-1; i>=0; --i) {
            if(s[i] == 'a') ++cur_a;
            a_num[i] = cur_a;
        }
        int res = INT_MAX;
        for(int i=0; i<n; ++i) {
            if(s[i] == 'b') { //如果当前是b，那么将这个b作为第1个起始的b(也即位置i前面全是a，i后面全是b)
                int left_b = 0, right_a = 0; //所以要去掉的就是i前面的b和i后面的a
                if(i-1 >= 0) left_b = b_num[i-1]; //i前面的b的数量就是b_num[i-1]
                if(i+1 < n) right_a = a_num[i+1]; //i后面的a的数量就是a_num[i+1]
                int c = left_b + right_a;
                res = min(res, c);
            }
        }
        res = min(res, b_num[n-1]); //当然还有一种情况就是将所有b删除的情况，需要考虑
        return res;
    }
};
