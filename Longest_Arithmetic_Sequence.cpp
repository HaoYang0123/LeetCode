//Leetcode 1027
//O(N^2)的时间复杂度，枚举i和j，这样距离就是dev=A[j]-A[i]，查看后面是否存在:A[j]+dev,A[j]+2*dev,...,这样的等差数列

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, vector<int>> mm; //mm[i]记录A数组中值为i的索引（按从小到大排列）
        int n=A.size();
        for(int i=0;i<n;++i) mm[A[i]].push_back(i);
        int res=2;
        for(int i=0;i<n-1;++i) {
            for(int j=i+1;j<n;++j) {
                int dev = A[j]-A[i];
                int v = A[j]+dev; //下一个元素为A[j]+dev
                auto ind = mm.find(v);
                bool flag = false;
                int k = -1;
                if(ind != mm.end()) { //mm中找到了，但不一定在j的后面
                    vector<int> vec=ind->second;
                    auto ind2 = upper_bound(vec.begin(),vec.end(), j); //查看在j后面是否存在值为v的元素
                    if(ind2 != vec.end()) {
                        flag = true;
                        k = (*ind2); //如果找到了，需要更新j值，后面找使用k
                    }
                }
                if(!flag) continue; //如果没找到，则继续枚举下一个i和j
                int cur_len = 2;
                while(flag) {
                    ++cur_len;
                    if(cur_len > res) res = cur_len;
                    v += dev; //继续找下下一个元素
                    ind = mm.find(v);
                    flag = false;
                    if(ind != mm.end()) {
                        vector<int> vec=ind->second;
                        auto ind2 = upper_bound(vec.begin(),vec.end(), k); //查看在k后面值为v的元素
                        if(ind2 != vec.end()) {
                            flag = true;
                            k = (*ind2); //仍然找到了，则继续更新k
                        }
                    }
                }
            }
        }
        return res;
    }
};
