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
