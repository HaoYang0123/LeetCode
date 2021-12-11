//Leetcode 911
//O(nlogn)时间复杂度
//最近又刷了一遍，真的挺有意思的。

//原来当前时刻只用将当前时刻投票的选举人之前的最大的比较，因为其它人（当前时刻没被投票），之前就没比过之前最大者，那么现在也不用比了
class TopVotedCandidate {
public:
    map<int, int> t2res;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> p2n;
        int max_person = persons[0];
        t2res[times[0]] = max_person;
        p2n[persons[0]]++;
        for(int i=1; i< persons.size(); ++i) {
            p2n[persons[i]]++;
            if(p2n[persons[i]] >= p2n[max_person]) 
                max_person = persons[i];
            t2res[times[i]] = max_person;
        }
    }
    
    int q(int t) {
        auto idx = t2res.upper_bound(t);
        --idx;
        return idx->second;
    }
};

//虽然也AC了，但是当前时刻我居然将所有已经投过票的人中找最大的，其实并不需要，上面的代码注释已经说明
class TopVotedCandidate {
public:
    map<int, int> t2res;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> p2n;
        unordered_map<int, int> p2t;
        for(int i=0; i< persons.size(); ++i) {
            p2n[persons[i]]++;
            p2t[persons[i]] = times[i];
            int max_n = 0, res = -1;
            for(auto idx2 = p2n.begin(); idx2 != p2n.end(); ++idx2) {
                // cout<<times[i]<<"\t"<<idx2->first<<"\t"<<idx2->second<<endl;
                if(idx2->second > max_n) {
                    max_n = idx2->second;
                    res = idx2->first;
                }
                else if(idx2->second == max_n) {
                    int old_t = p2t[res];
                    int new_t = p2t[idx2->first];
                    if(new_t > old_t) res = idx2->first;
                }
            }
            t2res[times[i]] = res;
        }
    }
    
    int q(int t) {
        auto idx = t2res.upper_bound(t);
        --idx;
        return idx->second;
    }
};



//三年前代码

class TopVotedCandidate {
public:
    vector<int> dp;
    vector<int> times;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        this->times = times;
        int n = persons.size();
        dp.resize(n);
        //unordered_map<int,int> person_index;
        vector<int> person_index(n+2,0);
        int max_person = persons[0];
        dp[0] = max_person;
        person_index[max_person] = 1;
        for(int i=1;i<n;++i) {
            int cur_person = persons[i];
            ++person_index[cur_person];
            if(person_index[cur_person] >= person_index[max_person]) {
                max_person = cur_person;
            }
            dp[i] = max_person;
        }
    }
    
    int q(int t) {
        int n = times.size();
        int start = 0, end = n - 1;
        while(start<=end) {
            int mid = (start+end)/2;
            if(times[mid]<=t) start = mid+1;
            else end = mid-1;
        }
        int index = start-1;
        return dp[index];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
