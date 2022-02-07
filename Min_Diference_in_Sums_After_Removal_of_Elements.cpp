// Leetcode 2163
//数组有3*n个元素，删除n个元素后，剩下的2*n个元素，前n个元素最小，后n个元素最大，这样保证前n个求和减后n个求和，得到的结果是最小的
//那么相当于找从n-1至2n-1中，前缀的最小n个元素
//同理，找从n至2n中，后缀的最大n个元素

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        multiset<int> left, right;
        int n = nums.size() / 3;
        vector<long long> dp1(3*n, 0), dp2(3*n, 0);  
        //dp1[i]表示nums[0...i]中选择n个最小的数，dp2[i]表示nums[i...(3*n-1)]中选择n个最大的数
        long long cur_sum = 0;
        for(int i=0; i<n; ++i) {
            left.insert(nums[i]);
            cur_sum += nums[i];
        }
        dp1[n-1] = cur_sum;
        for(int i=n; i<2*n; ++i) {
            auto idx = left.end();
            --idx;
            int cur_max = *idx;
            if(nums[i] >= cur_max) {
                dp1[i] = cur_sum;
                continue;  //如果比当前数left中最大的数还大，那么不插进来
            }
            //否则，需要更新left（因为left是存储的n个最小的数）
            left.insert(nums[i]);
            left.erase(idx);
            cur_sum += (nums[i] - cur_max);
            dp1[i] = cur_sum;
        }
        cur_sum = 0;
        for(int i=2*n; i<3*n; ++i) {
            right.insert(nums[i]);
            cur_sum += nums[i];
        }
        dp2[2*n] = cur_sum;
        for(int i=2*n-1; i>=n; --i) {
            auto idx = right.begin();  //right是找n个最大的数，idx则是当前right中最小的值
            int cur_min = *idx;
            if(nums[i] <= cur_min) {
                dp2[i] = cur_sum;
                continue;  //如果比当前数right中最小的数还小，那么不插进来
            }
            //否则，需要更新right
            right.insert(nums[i]);
            right.erase(idx);
            cur_sum += (nums[i] - cur_min);
            dp2[i] = cur_sum;
        }
        long long res = LLONG_MAX;
        for(int i=n-1; i<=2*n-1; ++i) {
            //cout<<i<<"\t"<<dp1[i]<<"\t"<<dp2[i+1]<<endl;
            res = min(res, dp1[i]-dp2[i+1]);
        }
        return res;
    }
};
