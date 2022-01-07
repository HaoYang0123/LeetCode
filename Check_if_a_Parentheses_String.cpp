// Leetcode 2116
//贪心算法，可以改变的数量先计算出来，并且可以知道这些可改变的数量，有多少是左、有多少是右，因为最终的左与右是一样多的。
//然后，贪心的将左的数量放在可以改变的前N个位置，最后只要判断当前右括号的数量，是否已经比左括号数量多，如果多，那么则无法满足条件

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int z = 0, y = 0;  //当前记录左、右括号的数量
        int can = 0;  //当前记录可以改变的数量
        for(int i=0; i<s.length(); ++i) {
            if(locked[i] == '1') {  //无法改变此括号
                if(s[i] == '(') ++z;
                else {
                    ++y;
                    if(y > can+z)  //如果当前是右括号，且前面的右括号数量已经比左括号和能够改变的数量要高，就算把所有可改变的作为左括号，也无法满足要求
                        return false;
                }
            }
            else {
                ++can;
                //cout<<i<<"\t"<<can<<endl;
            }
        }
        //cout<<"can\t"<<can<<endl;
        if(can+y < z) return false;
        if((can+y-z) % 2 != 0) return false;
        int addz = (can+y-z) / 2;
        int addy = can - addz;
        //cout<<addz<<"\t"<<addy<<"\t"<<can<<endl;
        for(int i=0;i<s.length();++i) {
            if(locked[i] == '0') {
                if(addz == 0) s[i] = ')';
                else {
                    s[i] = '(';
                    --addz;
                }
            }
        }
        //cout<<s<<endl;
        z = 0;
        y = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '(') ++z;
            else {
                ++y;
                if(y > z) return false;
            }
        }
        return true;
    }
};
