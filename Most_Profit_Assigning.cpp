//Leetcode 826
//动态规划

int my_cmp(pair<int,int> & a, pair<int,int> & b) {
    return a.first<b.first;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>> diff_pro;
        for(int i=0;i<n;++i) {
            diff_pro.push_back(pair<int,int>(difficulty[i],profit[i]));
        }
        sort(diff_pro.begin(),diff_pro.end(), my_cmp);
        vector<int> dp(n,0);
        unordered_map<int,int> dp2; //使用dp2来更新dp，因为有多个相同的值，需要将相同的值对应的profit设置为其中最大的值
        dp[0]=diff_pro[0].second;
        dp2[diff_pro[0].first] = dp[0];
        for(int i=1;i<n;++i) {
            dp[i]=diff_pro[i].second;
            if(dp[i-1]>dp[i]) dp[i]=dp[i-1];
            if(dp2.find(diff_pro[i].first) == dp2.end())
                dp2[diff_pro[i].first] = dp[i];
            else if(dp2[diff_pro[i].first] < dp[i]){
                dp2[diff_pro[i].first] = dp[i];
            }
        }
        for(int i=0;i<n;++i) {
            dp[i]=dp2[diff_pro[i].first];
        }
        int res=0;
        for(int i=0;i<worker.size();++i) {
            int val=worker[i];
            int start=0,end=n-1;
            int mid=0;
            while(start<=end) {
                mid=(start+end)>>1;
                if(diff_pro[mid].first==val) break;
                else if(diff_pro[mid].first>val) end=mid-1;
                else start=mid+1;
            }
            if(diff_pro[mid].first==val) start=mid;
            else {
                start++;
                if(start>=n) start=n-1;
                while(start>=0 && diff_pro[start].first>val) --start;
            }
            if(start>=0) {
                res+=dp[start];
            }
            //cout<<i<<"\t"<<worker[i]<<"\t"<<start<<"\t"<<dp[start]<<endl;
        }
        return res;
    }
};
