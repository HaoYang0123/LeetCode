// Leetcode 1856

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        int left[n], right[n];
        long long sum[n];  //前缀和
        sum[0] = nums[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1]+nums[i];
        }
        stack<pair<int, int> > s1, s2;
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            while (!s1.empty() && (s1.top().first) > nums[i]) {
                cnt += s1.top().second;
                s1.pop();
            }
            s1.push({ nums[i], cnt });
            left[i] = cnt;
        }
        for (int i = n - 1; i >= 0; --i) {
            int cnt = 1;
            while (!s2.empty() && (s2.top().first) >= nums[i]) {
                cnt += s2.top().second;
                s2.pop();
            }

            s2.push({ nums[i], cnt });
            right[i] = cnt;
        }
        //for(int i=0;i<n;++i) {
        //    cout<<left[i]<<'\t'<<right[i]<<endl;
        //}
        long long res =0;
        for(int i=0;i<n;i++){
            int a = i-left[i]+1;
            int b = i+right[i]-1;
            long long subArraySum;
            if(a>0)
                subArraySum = sum[b]-sum[a-1];
            else
                subArraySum = sum[b];
             //cout<<i<<'\t'<<a<<'\t'<<b<<'\t'<<subArraySum<<endl;
            res = max(res, subArraySum*nums[i]);
        }
        return res%1000000007;
    }
};
