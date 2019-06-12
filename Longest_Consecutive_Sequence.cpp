//Leetcode 128

//方式1：使用一个unordered_map记录连续的包含key的长度
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map; //map[key]记录连续的包含key的长度
        for(int i = 0; i < nums.size(); ++i) {
            if(map.find(nums[i]) != map.end()) continue;
            auto ind1 = map.find(nums[i] - 1), ind2 = map.find(nums[i] + 1); //判断nums[i]-1与nums[i]+1是否此前出现过
            int left = (ind1 == map.end() ? 0 : ind1->second);
            int right = (ind2 == map.end() ? 0 : ind2->second);
            int sum = left + right + 1; //left表示nums[i]-1的连续的长度，right表示nums[i]+1的连续的长度，1表示nums[i]一个元素
            res = max(res, sum);
            map[nums[i]] = sum; //更新map
            map[nums[i] - left] = sum;
            map[nums[i] + right] = sum;
        }
        return res;
    }
};

//方式2：使用两个set，第一个记录nums存的值，第二个记录是否已经处理过
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s1;
        unordered_set<int> s2;
        int n=nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;++i) s1.insert(nums[i]);
        int res=1;
        for(auto ind = s1.begin();ind != s1.end(); ++ind) { //s1是set，key是从小到大
            if(s2.find(*ind) != s2.end()) continue; //表示已经处理过
            s2.insert(*ind);
            int v = (*ind) + 1; //*ind存在，则判断*ind+1是否存在
            int c_res = 1; //记录从*ind开始的连续的长度，并将处理过的元素记录到s2中
            while(s1.find(v) != s1.end()) {
                s2.insert(v);
                ++c_res;
                ++v;
            }
            res = max(res, c_res);
        }
        return res;
    }
};
