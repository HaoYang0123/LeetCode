//Leetcode 991
//如果X>=Y，那么X每次减1，最终到达Y，到达Y的步数等于(Y-X)。因为X已经比Y大，如果X乘以2，只会偏离Y更远，显然不是最优解。
//如果X<Y，从Y, Y/2, Y/4, ..., 1，保存从这些值到Y的步数于dp中，步数分别为：0，1，2，...
//对于X，存在两种选择*2，或者-1，如果是-1，那么可以找到当前X在dp中的<=X的最大值
//举个例子: X=12,Y=50
那么我们保存：dp[50]=0, dp[25]=1, dp[13]=3(注：13->26->25->50), dp[7]=5, dp[4]=7, dp[2]=8, dp[1]=9
因为X=12，那么可以在dp中找到<=12的最大值，为7，那么步数等于(12-7)+dp[7]=(12-7)+5=10，(12-7)的步数表示从12减1，直到减到7为止
当然X可以先*2，得到X=24，然后在dp中找到<=24的最大值，为13，那么步数等于1+(24-13)+dp[13]=1+11+3=15，显然比之前的10要大（注这里前面多了1步，是从12开始需要乘以2，多出来的这步）

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X>=Y) return X-Y;
        //vector<int> dp(Y+2, INT_MAX);
        unordered_map<int ,int> dp;
        dp[Y] = 0;
        dp[Y+1] = 1;
        int y = Y;
        while(y > 1) {
            int new_y = (y+1)/2;
            dp[new_y] = dp[y] + 1 + (y % 2);
            //dp[new_y + 1] = min(dp[new_y+1], dp[new_y] + 1);
            y = new_y;
        }
        if(dp.find(X) != dp.end()) return dp[X];
        vector<int> yes_val; //dp中存在值的数据
        for(auto ind=dp.begin();ind!=dp.end();++ind) {
            yes_val.push_back(ind->first);
        }
        sort(yes_val.begin(),yes_val.end());
        //for(int i=0;i<yes_val.size();++i) cout<<yes_val[i]<<"\t"<<dp[yes_val[i]]<<endl;
        int res = INT_MAX;
        int x = X;
        int step = 0;
        while(true) {
            auto ind = upper_bound(yes_val.begin(), yes_val.end(), x); //返回大于x的第一个索引位置
            if(ind == yes_val.begin()) { //yes_val全部大于x，那么直接将x*2
                x *= 2;
                ++step;
            }
            else { //找到第一个大于x的索引位置，ind-1则是最后一个小于等于x的索引位置
                int i = *(ind-1);
                //cout<<i<<"\t"<<x<<"\t"<<step<<endl;
                int new_step = step + dp[i] + (x - i);
                if(new_step < res) res = new_step;
                if(ind == yes_val.end())
                     break; //因为一旦x大于等于目标值，则不能继续往后*2，因为后面*2的解肯定比之前得到的解要大
                x *= 2;
                ++step;
            }
        }
        return res;
    }
};
