//Leetcode 806

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line_num = 1, last_line_width = 0;
        for(int i=0;i<S.length();++i) {
            last_line_width += widths[S[i]-'a'];
            if (last_line_width > 100) {
                line_num++;
                last_line_width = widths[S[i]-'a'];
            }
        }
        vector<int> res;
        res.push_back(line_num);
        res.push_back(last_line_width);
        return res;
    }
};
