//Leetcode 1079
//比如AAAABBBCC，得到的是[4,3,2]数组
//在数组中枚举所有的排列组合，比如从[4,3,2]中抽取一个子集[3,2,2]（即3个A、2个B、2个C）
//可以得到其排列的数目为((3+2+2)!/3!2!2!)
//最终的解为枚举所有的可能子集[i,j,k](i<=4,j<=3,k<=2)对应的排列情况
//这里，有个小trick（当然这里是否使用这个trick不影响AC），即子集(1,2,1)与子集(2,1,1)的排列数目是一样的
//所以可以将子集从小到大排列(1,1,2)，得到key=112，进行哈希
//同时，为了加速n!的计算，事先将1!,2!,3!,4!,5!,6!,7!记录下来

class Solution {
public:
    int res;
    vector<int> mat;
    int numTilePossibilities(string tiles) {
        //初始化n!的值。1-7
        mat.push_back(1); //0!=1
        for(int i=1;i<=7;++i) {
            mat.push_back(mat.back()*i);
            //cout<<i<<"\t"<<mat.back()<<endl;
        }
        unordered_map<char, int> mm;
        for(int i=0;i<tiles.size(); ++i) {
            mm[tiles[i]]++;
        }
        vector<int> data;
        for(auto it=mm.begin();it!=mm.end();++it) data.push_back(it->second);
        //sort(data.begin(), data.end()); //比如：AAABBC，那么有[1,2,3]
        //for(int i=0;i<data.size();++i) cout<<data[i]<<endl;
        unordered_map<int, int> dp; //dp表示不同值（比如：[1,2,0]得到的key是120）对应的排列数量
        res = 0;
        vector<int> cur;
        dfs(data, 0, cur, dp);
        return res;
    }
    
    void dfs(vector<int> & data, int index, vector<int> & cur, unordered_map<int, int> & dp) {
        if(index == data.size()) {
            int key = get_key(cur);
            if(key==0) return;
            if(dp.find(key) != dp.end()) res += dp[key];
            else {
                dp[key] = get_per_num(cur);
                res += dp[key];
            }
            return;
        }
        for(int i=0;i<=data[index];++i) {
            vector<int> new_v = cur;
            new_v.push_back(i);
            dfs(data, index+1, new_v, dp);
        }
    }
    
    int get_per_num(vector<int> & cur) {
        int sum = 0, n = cur.size();
        int fm = 1;
        for(int i=0;i<n;++i) {
            sum += cur[i];
            fm *= mat[cur[i]];
        }
        int fz = mat[sum];
        return fz / fm;
    }
    
    int get_key(vector<int> & cur) {
        sort(cur.begin(), cur.end());
        int key=0;
        for(int i=0;i<cur.size();++i) {
            key=key*10+cur[i];
        }
        return key;
    }
};
