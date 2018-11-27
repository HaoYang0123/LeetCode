//Leetcode 911
//O(nlogn)时间复杂度

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
