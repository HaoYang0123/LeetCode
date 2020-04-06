//Leetcode 1399

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> bit2num;
        int max_v = 0;
        for(int i=1;i<=n;++i) {
            int b = get_bit(i);
            bit2num[b]++;
            max_v = max(max_v, bit2num[b]);
        }
        //cout<<"Max_v:\t"<<max_v<<endl;
        int res = 0;
        for(auto ind = bit2num.begin(); ind != bit2num.end(); ++ind) {
            //cout<<ind->first<<"\t"<<ind->second<<endl;
            if(ind->second == max_v) ++res;
        }
        return res;
    }
    
    inline int get_bit(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};
