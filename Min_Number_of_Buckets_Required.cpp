// Leetcode 2086

class Solution {
public:
    int minimumBuckets(string street) {
        int res = 0;
        for(int i=0; i<street.length(); ++i) {
            if(street[i] == 'H') {
                if((i-1<0 || street[i-1] == 'H') && (i+1>=street.length() || street[i+1] == 'H')) return -1;
                if((i+1 < street.length() && street[i+1] == '.')) { //那么右边一定是.
                    if(i-1<0 || street[i-1]!='B') {  //左边不满足条件那么只能用右边
                        street[i+1] = 'B';
                        ++res;
                    }
                }
                else {  //右边不满足，那么左边一定满足
                    if(street[i-1] != 'B') {
                        ++res;
                        street[i-1] = 'B';
                    }
                }
            }
        }
        //cout<<street<<endl;
        return res;
    }
};
