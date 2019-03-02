//Leetcode 830

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        S += string(1, '*'); //增加标记位
        vector<vector<int>> res;
        int c=1;
        char a=S[0];
        for(int i=1;i<S.length();++i) {
            if(S[i] != a) {
                a=S[i];
                if(c>=3) {
                    vector<int> tmp;
                    tmp.push_back(i-c);
                    tmp.push_back(i-1);
                    res.push_back(tmp);
                }
                c=1;
            }
            else ++c;
        }
        return res;
    }
};
