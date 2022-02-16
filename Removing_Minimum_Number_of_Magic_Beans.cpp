// Leetcode 2171

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long res = LLONG_MAX;
        int n = beans.size();
        sort(beans.begin(), beans.end());
        unordered_map<int, int> v2idx;
        vector<long long> prefix_sum(n, 0), suffix_sum(n, 0);
        long long cur_sum = 0;
        for(int i=0; i<n; ++i) {
            cur_sum += beans[i];
            prefix_sum[i] = cur_sum;
            //auto idx = v2idx.find(beans[i]);
            //if(idx == v2idx.end()) v2idx[beans[i]] = i;
        }
        cur_sum = 0;
        for(int i=n-1; i>=0; --i) {
            cur_sum += beans[i];
            suffix_sum[i] = cur_sum;
            v2idx[beans[i]] = i;
        }
        for(auto idx=v2idx.begin(); idx != v2idx.end(); ++idx) {
            int pos = idx->second;
            int val = idx->first;
            long long left = 0, right = 0;
            if(pos - 1 >= 0) left = prefix_sum[pos-1];
            right = suffix_sum[pos];
            long long fin_right = (long long)(n-pos) * val;
            long long tmp = left - fin_right + right;
            //cout<<pos<<"\t"<<val<<"\t"<<left<<"\t"<<right<<"\t"<<fin_right<<endl;
            res = min(res, tmp);
        }
        return res;
    }
};
