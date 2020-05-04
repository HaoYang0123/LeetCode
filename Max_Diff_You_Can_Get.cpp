//Leetcode 1432

class Solution {
public:
    int maxDiff(int num) {
        vector<int> digits;
        while(num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        //for(int i=0;i<digits.size();++i) cout<<digits[i]<<"\t";
        //cout<<endl;
        //cout<<get_max(digits)<<endl;
        //cout<<get_min(digits)<<endl;
        return get_max(digits) - get_min(digits);
    }
    
    inline int get_max(vector<int> & digits) {
    //从左往右找到第1个不等于9的数字a，将所有等于a的替换为9
        int ind = -1;
        for(int i=0;i<digits.size();++i) {
            if(digits[i] != 9) {
                ind = i;
                break;
            }
        }
        int res = 0;
        int need_update = -1;
        if(ind != -1) need_update = digits[ind];
        for(int i=0;i<digits.size();++i) {
            int v = digits[i];
            if(v == need_update) v = 9;
            res = res*10 + v;
        }
        return res;
    }
    
    inline int get_min(vector<int> & digits) {
    //如果第1个数字不等于1，则直接将所有等于第1个数字的替换为1
    //否则，左往右找第1个不等于0且不等于1的数字a，将所有等于a的替换为0
        if(digits[0] != 1) {
            int need_update = digits[0];
            int res = 0;
            for(int i=0;i<digits.size();++i) {
                int v = digits[i];
                if(v == need_update) v = 1;
                res = res*10 + v;
            }
            return res;
        }
        int ind = -1;
        for(int i=0;i<digits.size();++i) {
            if(digits[i] != 0 && digits[i] != 1) {
                ind = i;
                break;
            }
        }
        int res = 0;
        int need_update = -1;
        if(ind != -1) need_update = digits[ind];
        for(int i=0;i<digits.size();++i) {
            int v = digits[i];
            if(v == need_update) v = 0;
            res = res*10 + v;
        }
        return res;
    }
};
