//Leetcode 954
//O(n)时间复杂度

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int n=A.size();
        sort(A.begin(), A.end()); //先排序后，那么小数在前，*2的大数在后（注：负数正好相反）
        //for(int i=0;i<n;++i) cout<<A[i]<<"\t";
        //cout<<endl;
        unordered_map<int,int> val_num; //记录每个元素的个数
        for(int i=0;i<A.size();++i) {
            val_num[A[i]]++;
        }
        for(int i=0;i<A.size();++i) {
            int c = A[i];
            //cout<<c<<"\t"<<val_num[c]<<endl;
            if(val_num[c]==0) continue;
            int c2 = c*2;
            if(c < 0) { //对于负数，正好相反
                if(c%2==1) return false;
                c2 = c/2; 
            }
            //cout<<"VV\t"<<val_num[c]<<"\t"<<val_num[c2]<<"\t"<<c2<<endl;
            if(val_num[c2] < val_num[c]) return false;
            val_num[c2] -= val_num[c];
            val_num[c] = 0;
        }
        return true;
    }
};
