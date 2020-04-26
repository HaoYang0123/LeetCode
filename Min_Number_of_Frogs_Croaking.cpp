class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnum = 0, rnum = 0, onum = 0, anum = 0, knum = 0;
        int res = 0;
        for(int i = 0; i < croakOfFrogs.length(); ++i) {
            if(croakOfFrogs[i] == 'c') {
                ++cnum;
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
                res = max(res, cnum); //由于cnum>=rnum>=onum>=anum>=knum，所以当前需要的frog数量就是cnum
                --cnum; //当前一个frog的k已经输出了，相当于当前frog可以处理后续的字符串了，直接将所有num减1
                --rnum;
                --onum;
                --anum;
                --knum;
            }
        }
        if(cnum == 0) return res;
        return -1;
    }
};
