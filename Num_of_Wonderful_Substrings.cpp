// Leetcode 1915
//这一题，相当于另外一道题，给定一个int数组，计算所有子数组的求和为0，-1，+1，的子数组的数量

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        int cur_prefix = 0;  //前缀和，用二进制存储，prefix[i+1]是一个int，表示word[0...i]的子字符串
        //此int中的第i位为1，表示对应字符出现了奇数次，比如第0位为1，表示子字符串中'a'出现了奇数次；同理，第i位为0，表示出现了偶数次
        unordered_map<int, int> v2n;  //表示前缀和中v出现的次数
        v2n[0] = 1;
        for(int i=0; i<n; ++i) {
            int idx = int(word[i] - 'a');
            cur_prefix = (cur_prefix ^ (1 << idx));
            v2n[cur_prefix]++;
        }
        //cout<<"size\t"<<v2n.size()<<endl;
        //for(auto idx = v2n.begin(); idx != v2n.end(); ++idx) cout<<"\t"<<idx->first<<"\t"<<idx->second<<endl;
        long long res = 0;
        //下面的第1个for循环，是枚举子字符串，所有字符次数均为偶数的次数
        for(auto idx = v2n.begin(); idx != v2n.end(); ++idx) {
            int prefix_v = idx->first;
            int c1 = idx->second;
            res += get_v(c1);
        }
        //cout<<"res\t"<<res<<endl;
        long long res2 = 0;
        for(auto idx = v2n.begin(); idx != v2n.end(); ++idx) {
            int prefix_v = idx->first;
            int c1 = idx->second;
            int c2 = 0;
            for(int i=0; i<10; ++i) {
                int new_v = (prefix_v ^ (1 << i));
                auto idx2 = v2n.find(new_v);
                if(idx2 == v2n.end()) continue;
                c2 += idx2->second;
            }
            res2 += (c1+0ll) * c2;
            //cout<<"pre\t"<<prefix_v<<"\t"<<c1<<"\t"<<c2<<endl;
        }
        //由于奇数次的，每个会枚举两遍，得/2
        return res+res2/2;
    }
    
    inline long long get_v(int n) {
        return (n+0ll) * (n-1) / 2;  //+0ll是将int转成long long
    }
};
