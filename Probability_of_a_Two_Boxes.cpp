//Leetcode 1467

class Solution {
public:
    double getProbability(vector<int>& balls) {
        int sum = 0;
        for(int ball : balls) sum += ball;
        long long total = get_combination(sum, sum/2);
        vector<int> pick(balls.size(), 0);
        long long match = dfs(balls, pick, sum/2, 0);
        //cout<<match<<"\t"<<total<<endl;
        return match*1.0/total;
    }
    
    long long dfs(vector<int> & balls, vector<int> & pick, int left, int i) {
        if(left == 0) {
            if(has_same_distinct(balls, pick)) {
                long long res = 1;
                for(int i=0;i<balls.size();++i) {
                    res *= get_combination(balls[i], pick[i]);
                }
                return res;
            }
            return 0;
        }
        if(left < 0 || i >= balls.size()) return 0;
        long long res = 0;
        for(int j=0;j<=balls[i];++j) {
            pick[i]=j;
            res += dfs(balls, pick, left-j, i+1);
        }
        pick[i] = 0; //必须有这一行，回归至最初的状态
        return res;
    }
    
    bool has_same_distinct(vector<int> & balls, vector<int> & pick) {
        int left_n = 0, right_n = 0;
        for(int i=0;i<balls.size();++i) {
            if(pick[i] > 0) ++left_n;
            if(balls[i]-pick[i] > 0) ++right_n;
        }
        return (left_n == right_n);
    }
    
    long long get_combination(int n, int m) {
        long long res = 1;
        for(int i = n, j = 1; j <= m; --i, ++j) {
            res *= i;
            res /= j;
        }
        return res;
    }
};
