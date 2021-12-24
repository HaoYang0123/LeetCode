// Leetcode 2111
// 最长递增子序列，时间复杂度O(N logN)

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int res = 0;
        for(int i=0; i<k; ++i) {
            int len = 0;
            int tmp = get_longest_subarry(arr, i, k, len);
            res += (len-tmp);
        }
        return res;
    }
    
    inline int get_longest_subarry(vector<int> & arr, int start, int k, int & len) {
        //获取最长递增子序列，时间复杂度O(N lgN)
        vector<int> cur;
        for(int i=start; i<arr.size(); i+=k) {
            auto idx = upper_bound(cur.begin(), cur.end(), arr[i]);
            if(idx == cur.end()) {  //cur没找到比arr[i]大的数字，即所有数字，均小于等于arr[i]，那么可以直接将arr[i]加入其中
                cur.push_back(arr[i]);
            }
            else {  //如果找到了第1个数字，比arr[i]大，那么将此数替换为arr[i]（虽然此时cur的顺序不满足arr，但无所谓，因为替换前的cur长度与当前一样）
                *idx = arr[i];
            }
            ++len;
        }
        return cur.size();
    }
};
