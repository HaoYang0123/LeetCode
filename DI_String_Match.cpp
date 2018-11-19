//Leetcode 942
//先产生结果：[0,1,2,...,n-1]，然后遇到连续的D，则将这个区间内的数字反转。

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res(S.length()+1,0);
        for(int i=0;i<res.size();++i) res[i] = i;
        for(int i=0;i<S.length();++i) {
            if(S[i] == 'D') {
                int start = i, end = i+1;
                while(end < S.length()) {
                    if(S[end]=='D') ++end;
                    else break;
                }
                i = end - 1;
                //cout<<start<<"\t"<<end<<endl;
                for(int j=start;j<(start+end+1)/2;++j) {
                    int tmp = res[j];
                    res[j] = res[end - (j - start)];
                    res[end- (j - start)] = tmp;
                }
            }
        }
        return res;
    }
};
