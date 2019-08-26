//Leetcode 1170

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size(), m=words.size();
        vector<int> res(n,0);
        vector<int> www(m, 0);
        for(int i=0;i<m;++i) {
            www[i] = f(words[i]);
            //cout<<www[i]<<endl;
        }
        sort(www.begin(), www.end());
        for(int i=0;i<n;++i) {
            int x = f(queries[i]);
            int ind = upper_bound(www.begin(), www.end(), x) - www.begin(); //第一个>x的索引，ind就是<=x的个数
            res[i] = (words.size()-ind); //>x的个数
        }
        return res;
    }
    
    int f(const string & str) {
        map<char, int> aa;
        for(int i=0;i<str.length();++i) {
            aa[str[i]]++;
        }
        return aa.begin()->second;
    }
};
