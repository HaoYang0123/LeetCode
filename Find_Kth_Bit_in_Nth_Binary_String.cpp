//Leetcode 1545

class Solution {
public:
    vector<long long> n_len;
    char findKthBit(int n, int k) {
        n_len.push_back(0);
        n_len.push_back(1); //n_len[i]表示S_i的长度
        long long cur = 1;
        for(int i=2;i<=n;++i) {
            cur = 2*cur + 1;
            n_len.push_back(cur);
        }
        //for(int i=0;i<=n;++i) cout<<i<<"\t"<<n_len[i]<<endl; 
        return dfs(n, k-1);
    }
    
    char dfs(int n, int k) {
        //cout<<"---"<<n<<"\t"<<k<<endl;
        if(n == 1) return '0';
        long long ll = n_len[n];
        if(ll/2 == k) return '1';
        if(ll/2>k) return dfs(n - 1, k);
        char rev_c = dfs(n - 1, ll - k - 1);
        //cout<<"++++"<<n<<"\t"<<rev_c<<endl;
        if(rev_c == '1') return '0';
        return '1';
    }
};
