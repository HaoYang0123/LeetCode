//Leetcode 1093

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        long long sum=0,mi=INT_MAX,ma=INT_MIN; //一定得使用long long，不然求和int会超过范围
        int mo=-1,mo_count=0;
        vector<int> vv(count.size(),0);
        vv[0] = count[0];
        for(int i=0;i<count.size();++i) {
            sum+=i*count[i];
            if(count[i] > 0) {
                if(mi == INT_MAX) mi = i;
                ma = i;
            }
            if(count[i]>mo_count) {
                mo_count = count[i];
                mo = i;
            }
            if(i>0) vv[i] = vv[i-1] + count[i];
        }
        double mean = sum * 1.0 / vv[count.size()-1];
        double median = -1;
        if(count.size() % 2 == 1) {
            int mind = (vv.back()+1)/2;
            int ind = lower_bound(vv.begin(), vv.end(), mind)-vv.begin();
            median = ind;
        }
        else {
            int mind1 = vv.back()/2;
            int mind2 = mind1+1;
            int ind1 = lower_bound(vv.begin(), vv.end(), mind1)-vv.begin();
            int ind2 = lower_bound(vv.begin(), vv.end(), mind2)-vv.begin();
            //cout<<ind1<<"\t"<<ind2<<endl;
            median = (ind1+ ind2) * 1.0 / 2;
        }
        vector<double> res(5);
        res[0] = mi;
        res[1] = ma;
        res[2] = mean;
        res[3] = median;
        res[4] = mo;
        return res;
    }
};
