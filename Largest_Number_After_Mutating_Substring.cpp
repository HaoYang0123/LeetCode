// Leetcode 1946

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string res = "";
        int change_num = 0;
        for (int i=0; i<num.length(); ++i) {
            int v = (int)(num[i]-'0');
            int cv = change[v];
            //cout<<i<<"\t"<<v<<"\t"<<cv<<endl;
            if(v >= cv) {
                res += num[i];
                if(change_num > 0) {
                    if(v > cv)
                        change_num = -1;
                }
            }
            else if(change_num >= 0) {
                res += (char)(cv + '0');
                change_num += 1;
            }
            else {
                res += num[i];
            }
        }
        return res;
    }
};
