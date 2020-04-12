//Leetcode 1402
//数组从小到大排序，先计算正数的和，然后找到最后一个负数，找到累加的负数和（取绝对值转成正数）。
//累加的负数和大于正数的和，则break
//即只要从负数和<正数和，累加得到的结果一定是最大的（可以用数学证明）
//sum(i) = s[i]*1+s[i+1]*2+.... ，表示从i至n的“和”
//sum(i-1) = s[i-1]*1+s[i]*2+... = s[i-1]*1+sum(i) + s[i] + s[i+1] + ... = sum(i) + (s[i-1]+s[i]+s[i+1]+...)
//也即只要i-1至n的累加和是正数，那么sum(i-1)>sum(i)

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int pos_sum = 0, neg_index = -1, n = satisfaction.size();
        for(int i=0;i<n;++i) {
            if(satisfaction[i] < 0) neg_index = i;
            else pos_sum += satisfaction[i];
        }
        int start_pos = 0;
        if(neg_index != -1) {
            int neg_sum = 0;
            int i = neg_index;
            for(; i>=0; --i) {
                neg_sum += -satisfaction[i];
                if(neg_sum > pos_sum) break;
            }
            start_pos = i + 1;
        }
        //cout<<start_pos<<"\t"<< pos_sum<<endl;
        int res = 0;
        for(int i=start_pos; i < n; ++i) res += (satisfaction[i] * (i-start_pos+1));
        return res;
    }
};
