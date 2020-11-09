//Leetcode 1647

class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for(int i=0;i<s.length();++i) {
            ++cnt[int(s[i]-'a')];
        }
        sort(cnt.rbegin(), cnt.rend()); //从大到小排序
        int res = 0;
        for(int i=1;i<cnt.size();++i) {
            while(cnt[i]>0 && cnt[i]>=cnt[i-1]) {
                --cnt[i];
                ++res;
            }
        }
        return res;
    }
};
