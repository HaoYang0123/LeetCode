//Leetcode 1014
//二分查找，最小解肯定是数组中最大元素或者求和除D中的较大值，最大解则是求和。
//然后在最小解与最大解中计算均值，判断均值是不是满足条件，如果满足，那么解在最小解与中值之间；否则，解在中值与最大解之间。

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0, max = 0;
        int n = weights.size();
        for(int i=0;i<n;++i) {
            sum += weights[i];
            if(max<weights[i]) max=weights[i];
        }
        int l=(sum+D-1)/D;
        if(max>l) l=max;
        int r=sum;
        while(l<r) {
            int m=(l+r-1)/2;
            bool ok=true;
            int c=0, cur_c=0;
            for(int i=0;i<n;++i) {
                c+=weights[i];
                if(c>m) {
                    ++cur_c;
                    c=weights[i];
                    if(cur_c>=D) {
                        ok=false;
                        break;
                    }
                }
            }
            ++cur_c;
            if(cur_c>D) ok=false;
            if(ok) r=m;
            else l=m+1;
        }
        return l;
    }
};
