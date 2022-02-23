// Leetcode 825
//其中第三个条件，可以忽略不计。因为与第二个条件是一样的，如果满足了条件3，一定满足条件2，不满足条件2，就一定不满足条件3.所以，只需要找到y，同时不满足条件1和条件2即可（因为不满足条件2，就一定不满足条件3）

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        sort(ages.begin(), ages.end());
        for(int i=0; i<ages.size(); ++i) {
            int x = ages[i];
            // y > 0.5*x + 7 && y <= x
            auto idx = upper_bound(ages.begin(), ages.end(), 0.5*x+7); //第1个比此数大的
            auto idx2 = upper_bound(ages.begin(), ages.end(), x); 
            --idx2;
            int num = idx2 - idx;  // + 1需要去掉i（自己不能与自己连接）
            num = max(num, 0);
            //cout<<i<<"\t"<<num<<endl;
            res += num;
        }
        return res;
    }
};
