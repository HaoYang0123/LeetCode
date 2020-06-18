//Leetcode 1482
//自己写的方法，超时了

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        map<int, vector<pair<int,int>>> val2idx; //val2idx[i]记录花开为第i天的所有区间
        for(int i=0;i<n;++i) {
            auto ind = val2idx.find(bloomDay[i]);
            if(ind == val2idx.end()) val2idx[bloomDay[i]].push_back(pair<int,int>({i,i}));
            else {
                vector<pair<int,int>> & intervals = ind->second;
                if(intervals.back().second + 1 == i) intervals[intervals.size()-1].second = i;
                else intervals.push_back(pair<int,int>({i,i}));
            }
        }
        //write(val2idx);
        vector<pair<int,int>> bloomed;
        for(auto ind = val2idx.begin(); ind != val2idx.end(); ++ind) {
            if(bloomed.size() == 0) bloomed = ind->second;
            else merge_interval(bloomed, ind->second);
            //cout<<ind->first<<":";
            //write_interval(bloomed);
            if(check_ok(bloomed, m, k)) return ind->first;
        }
        return -1;
    }
    
    bool check_ok(vector<pair<int,int>> & bloomed, int m, int k) {
        int cur_m = 0;
        for(int i = 0; i < bloomed.size(); ++i) {
            cur_m += (bloomed[i].second - bloomed[i].first + 1) / k;
            if(cur_m >= m) return true;
        }
        return false;
    }
    
    void merge_interval(vector<pair<int,int>> & bloomed, vector<pair<int,int>> & cur_bloomed) {
        //将cur_bloomed的区间，合并至bloomed区间中
        bloomed.insert(bloomed.begin(), cur_bloomed.begin(), cur_bloomed.end());
        sort(bloomed.begin(), bloomed.end());
        //合并
        int cur_i = 0;
        for(int i=1;i<bloomed.size();++i) {
            if(bloomed[i].first == bloomed[cur_i].second + 1) bloomed[cur_i].second = bloomed[i].second;
            else {
                ++cur_i;
                bloomed[cur_i] = bloomed[i]; //注意，之前WA，是少了这句，导致merge后面的interval丢失了
            }
        }
        bloomed.resize(cur_i+1);
    }
    
    void write_interval(vector<pair<int,int>> & intervals) {
        for(int i=0;i<intervals.size();++i) cout<<"\t"<<intervals[i].first<<"-"<<intervals[i].second;
        cout<<endl;
    }
    
    void write(map<int, vector<pair<int,int>>> & val2idx) {
        for(auto ind = val2idx.begin(); ind != val2idx.end(); ++ind) {
            cout<<ind->first<<":";
            write_interval(ind->second);
        }
    }
};


//在网上找了一下：二分查找，找到最小的天min和最大的天max，然后取中值mid，如果中值得到的不满足条件，则答案在[mid+1, max]中
//如果满足条件，则答案在[min,mid]中
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * k > bloomDay.size()) return -1; //总的花的数量比m*k要小，则不可能满足条件
        int min_day = INT_MAX, max_day = INT_MIN;
        for(int i=0;i<bloomDay.size();++i) {
            if(bloomDay[i] < min_day) min_day = bloomDay[i];
            if(bloomDay[i] > max_day) max_day = bloomDay[i];
        }
        while(min_day < max_day) {
            int mid = min_day + (max_day - min_day) / 2;
            if(is_ok(bloomDay, mid, m, k)) {
                max_day = mid;
            }
            else min_day = mid+1;
        }
        return min_day;
    }
    
    bool is_ok(vector<int> & bloomDay, int mid, int m, int k) {
        int cnt = 0;
        int cur_m = 0;
        for(int i=0;i<bloomDay.size();++i) {
            if(bloomDay[i] <= mid) ++cnt;
            else {
                cur_m += cnt / k;
                if(cur_m >= m) return true;
                cnt = 0;
            }
        }
        cur_m += cnt / k;
        return cur_m >= m;
    }
};
