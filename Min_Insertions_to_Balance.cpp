//Leetcode 1541

class Solution {
public:
    int minInsertions(string s) {
        int res = 0, cur_a = 0, cur_c = 0; 
        //cur_a表示有多少个(
        //cur_c表示当前有多少个)，cur_c在程序运行过程中只能是0和1
        for(int i=0;i<s.length();++i) {
            if(s[i] == '(') {
                if(cur_c == 1) { //表示之前有一个)，需要加一个)
                    if(cur_a > 0) { //如果前面已经有一个(，那么只用加一个)，将前面的(，进行抵消
                        ++res;
                        --cur_a;
                    }
                    else res += 2; //前面没有(，那么需要补(和)
                    cur_c = 0;
                }
                ++cur_a;
            }
            else {
                ++cur_c;
                if(cur_c == 2) {
                    if(cur_a > 0) --cur_a; //表示前面有一个(，直接与之前抵消
                    else ++res; //如果前面没有(，则需要加一个(
                    cur_c = 0;
                }
            }
        }
        if(cur_a > 0) //如果最后仍然有n个(，那么需要加2*n个)，注：需要考虑当前还有多少个)(0个或者1个)
            res += 2 * cur_a - cur_c;
        else //假设没有(，那么如果cur_c=0，则不需要追加了；如果cur_c=1，则需要追加两个字符：1个(和1个)
            res += cur_c * 2;
        return res;
    }
};
