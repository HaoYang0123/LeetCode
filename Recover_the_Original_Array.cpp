// Leetcode 2122
// 用multiset超时了。。。。但思路是正确的

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); ++i) { //枚举所有的k
            if (nums[i] - nums[0] == 0 || (nums[i] - nums[0]) % 2 != 0)
                continue;
            int k = (nums[i] - nums[0]) / 2;
            //cout<<k<<endl;
            multiset<int> curss(nums.begin(), nums.end());
            vector<int> res;
            while(!curss.empty()) {  //接下来，找low和high
                int x = *curss.begin();  //最小的元素是一定是low中元素
                auto y = curss.find(x+2*k);  //对应的high中元素一定是low+2*k
                if(y == curss.end()) break;
                curss.erase(curss.begin());
                curss.erase(y);
                res.push_back(x+k);
            }
            if(res.size() == nums.size()/2) {
                return res;
            }
        }
        return vector<int>();
    }
};
