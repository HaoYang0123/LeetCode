//Leetcode 1024
//O(N)时间复杂度，使用两个指针a和b，a表示上一区间的右端，b表示当前最远的距离
//如果当前区间比a近，则说明当前区间与之前的区间有overlap可以将当前区间替换原来的区间（即res不变）；
//否则，res++
//比如：例子[0,2],[0,4],[1,5],[2,6],T=6
//提取第一个区间：res=1,a=0,b=2
//判断第二个区间：区间开始处0比a要大，说明res++，并更新a=2，b=4
//判断第三个区间：区间开始处1比a要小，说明当前区间可以替换原始区间（[1,5]直接替换[0,4],res仍然等于2)，并更新b=5
//同理判断第四个区间，区间开始处2与a相等，仍然是替换原始区间（res仍然等于2），最终选择的两个区间为[0,2]（或[0,4]）和[2,6]

bool sort_clip(const vector<int> & a, const vector<int> & b) {
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        sort(clips.begin(), clips.end(), sort_clip);
        int res = 1;
        int a=clips[0][0], b=clips[0][1];
        if(a>0) return -1;
        if(b>=T) return res;
        for(int i=1;i<n;++i) {
            if(clips[i][1]<=b) continue;
            if(clips[i][0]>b) return -1;
            if(clips[i][0]>a) {
                ++res;
                a=b;
                b=max(b, clips[i][1]);
                if(b>=T) return res;
            }
            else {
                b=max(b, clips[i][1]);
                if(b>=T) return res;
            }
        }
        if(b>=T) return res;
        return -1;
    }
};
