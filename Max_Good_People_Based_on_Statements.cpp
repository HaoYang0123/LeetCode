// Leetcode 2151
//枚举所有情况，O(2^n)，n最多是15，2^15=10^5，时间不会超时

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int res = 0, n = statements.size();
        for(int i=1; i<1<<n;++i) {  //0不用枚举了，因为0一定是答案中的一种（res=0），1:00001, 2: 00010, 3: 00011
            bool is_ok = true;  //判断是否有矛盾
            for(int j=0; j<n; ++j) {  //第j个人
                if((i & (1<<j)) == 0) continue;  //如果第j个人是坏人，那么不用查看，因为坏人说的话可以是实话也可以是假话
                //if(i==26) {
                //    cout<<i<<":"<<j<<":"<<(i & (1<<j))<<endl;
                //}
                vector<int> & one_stat = statements[j];  //第j个人是好人，那么他说的全部是实话，检查是这个人对所有其它人（one_stat）否有矛盾情况
                for(int k=0; k<n; ++k) {
                    if(one_stat[k] == 2) continue;  //没评价，则不用判断
                    //if(i==26 && j==1) {
                    //    cout<<"\t"<<k<<"\t"<<(i & (1<<k))<<"\t"<<one_stat[k]<<endl;
                    //}
                    if((i & (1<<k)) == 0 && one_stat[k] == 1) {  //如果i情况中k是坏人，但第j个人（好人）认为k是好人，则有矛盾
                        is_ok = false;
                        break;
                    }
                    if((i & (1<<k)) != 0 && one_stat[k] == 0) {  //同理，如果i情况中k是好人，但第j个人（好人）认为k是坏人，则同样也有矛盾
                        is_ok = false;
                        break;
                    }
                }
                if(!is_ok) break;  //如果已经有了矛盾，则j之后的人就不用再判断了
            }
            if(is_ok) {  //如果i情况，枚举所有人(j)均无矛盾，那么i情况是正确答案
                res = max(res, get_good_num(i));  //get_good_num(i)表示i情况中好人的数量
                //cout<<i<<"\t"<<get_good_num(i)<<endl;
            }
        }
        return res;
    }
    
    inline int get_good_num(int i) {
        int res = 0;
        while(i > 0) {
            if(i % 2 == 1) ++res;
            i /= 2;
        }
        return res;
    }
};
