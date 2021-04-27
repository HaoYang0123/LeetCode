// Leetcode 1837

class Solution {
public:
    int sumBase(int n, int k) {
        vector<int> all_k;
        all_k.push_back(1);
        while(true) {
            int new_k = all_k.back() * k;
            if(new_k > n) break;
            all_k.push_back(new_k);
        }
        //for(int i=0;i<all_k.size();++i) cout<<all_k[i]<<endl;
        int res = 0;
        int ind = all_k.size()-1;
        while(n > 0) {
            int bit = get_bit(n, all_k[ind]);
            //cout<<n<<"\t"<<all_k[ind]<<"\t"<<bit<<endl;
            res += bit;
            n -= bit * all_k[ind];
            --ind;
        }
        return res;
    }
    
    inline int get_bit(int n, int k) {
        return n / k;
    }
};
