// Leetcode 2271

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        map<int, int> tt;
        for(int i=0; i<tiles.size(); ++i) {
            tt[tiles[i][0]] = tiles[i][1];
            if (tiles[i][1]-tiles[i][0]+1 >= carpetLen) return carpetLen;
        }
        int res = 0;
        auto left = tt.begin(), right = tt.begin();
        int cur = 0;
        while(right != tt.end()) {
            int cur_start = left->first;
            int cur_end = right->second;
            int tmp = min(cur_start+carpetLen-1, cur_end);
            cur += tmp - right->first + 1;
            //cout<<"\t"<<left->first<<"->"<<right->first<<endl;
            //cout<<cur<<endl;
            res = max(res, cur);
            if(res >= carpetLen) return res;  //如果是最大值，那么直接返回
            if(cur_end >= cur_start+carpetLen-1) {
                cur -= (left->second-left->first+1);  //将最左边的值删除
                cur -= tmp - right->first + 1;  //由于right没有移动，那么当前cur值已经加过right的贡献值，那么也把right贡献值删除
                //cout<<"del\t"<<cur<<endl;
                ++left;
            }
            else ++right;
        }
        return res;
    }
};
