//Leetcode 1566

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for(int i=0;i+m*k<=arr.size();++i) {
            bool is_ok0 = true;
            for(int j=i;j<i+m;++j) {
                bool is_ok = true;
                for(int p=1;p<k;++p) {
                    if(arr[j]!=arr[j+p*m]) {
                        is_ok = false;
                        break;
                    }
                }
                if(!is_ok) {
                    is_ok0 = false;
                    break;
                }
            }
            if(is_ok0) return true;
        }
        return false;
    }
};
