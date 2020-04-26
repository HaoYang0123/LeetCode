//Leetcode 1419

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnum = 0, rnum = 0, onum = 0, anum = 0, knum = 0;
        int curMax = 0, res = 0;
        for(int i = 0; i < croakOfFrogs.length(); ++i) {
            if(croakOfFrogs[i] == 'c') {
                ++cnum;
                curMax = max(curMax, cnum);
            }
            else if(croakOfFrogs[i] == 'r') {
                ++rnum;
                if(rnum > cnum) return -1;
            }
            else if(croakOfFrogs[i] == 'o') {
                ++onum;
                if(onum > rnum) return -1;
            }
            else if(croakOfFrogs[i] == 'a') {
                ++anum;
                if(anum > onum) return -1;
            }
            else {
                ++knum;
                if(knum > anum) return -1;
                res = max(res, curMax); //curMax其实是cnum，因为cnum>=rnum>=onum>=anum>=knum
                --cnum; //当前一个frog的k已经输出了，相当于当前frog可以处理后续的字符串了，直接将所有num减1
                --rnum;
                --onum;
                --anum;
                --knum;
                --curMax;
            }
        }
        if(curMax == 0) return res; //注意：得判断curMax=0，也即不能出现cnum>rnum>...>knum情况出现，比如: ccroak这种情况
        return -1;
    }
};
