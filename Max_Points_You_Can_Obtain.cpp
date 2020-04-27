//Leetcode 1423
//记录前k条和后k条的累积和：left和right
//然后最大的结果res = max(left[i] + right[k-i] for every i)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> left(k, 0), right(k, 0);
        int cur_v = 0;
        for(int i=0;i<k;++i) {
            cur_v += cardPoints[i];
            left[i] = cur_v;
        }
        //cout<<"OOO\t"<<cardPoints.size()-k<<endl;
        cur_v = 0;
        for(int i=cardPoints.size()-1;i>=cardPoints.size()-k && i>=0;--i) {
            //cout<<i<<"\t"<<cardPoints.size()-1-i<<endl;
            cur_v += cardPoints[i];
            right[cardPoints.size()-1-i] = cur_v;
        }
        //cout<<"LLL"<<endl;
        int res = max(right[k-1], left[k-1]);
        //cout<<res<<endl;
        for(int i=0;i<k-1;++i) {
            int tmp = left[i] + right[k-2-i];
            res = max(res, tmp);
        }
        return res;
    }
};
