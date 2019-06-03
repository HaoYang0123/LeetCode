//Leetcode 1054
//O(N)的时间复杂度，对数组按出现次数从高到低排序，然后按0，2，4...，1，3，5...的顺序插入

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> mm;
        map<int, vector<int>> mm2; //key是v出现的次数，value是出现次数为key的所有值
        for(int i=0; i<barcodes.size(); ++i) {
            mm[barcodes[i]]++;
        }
        for(auto ind=mm.begin(); ind != mm.end(); ++ind) {
            int count = ind->second;
            mm2[count].push_back(ind->first);
        }
        int n = barcodes.size();
        vector<int> res(n, 0);
        int i=0;
        for(auto ind=mm2.rbegin();ind != mm2.rend(); ++ind) { //次数按从高到低排序
            vector<int> & v = ind->second;
            for(int j=0; j<v.size(); ++j) {
                int count = ind->first;
                while(count--) {
                    res[i] = v[j];
                    i += 2;
                    if(i >= n) i = 1;
                }
            }
        }
        return res;
    }
};
