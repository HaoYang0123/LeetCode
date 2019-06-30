//Leetcode 1103

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int start = 1;
        long long sum = get_sum(start, num_people);
        while(sum <= candies) {
            for(int i=0;i<num_people; ++i) res[i] += (start + i);
            start += num_people;
            candies -= sum;
            sum = get_sum(start, num_people);
        }
        for(int i=0; i<num_people; ++i) {
            int need_candies = (start + i);
            if(candies < need_candies) need_candies = candies;
            res[i] += need_candies;
            candies -= need_candies;
            if(candies <= 0) break;
        }
        return res;
    }
    
    long long get_sum(int start, int num) { //[start, start+num-1]求和
        long long fz = (start + start + num - 1);
        return fz * num/2;
    }
};
