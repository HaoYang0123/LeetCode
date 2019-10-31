//Leetcode 1239
//动态规划，使用dp[str]来记录前面的字符串已经是str，后面还可以接的最长字符串的长度

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> new_arr;
        for(int i=0;i<arr.size();++i) {
            if(check_valide(arr[i])) new_arr.push_back(arr[i]); //去掉当前字符串已经重复的情况
        }
        unordered_map<string, int> dp;
        return dfs(new_arr, dp, 0, "");
    }
    
    int dfs(vector<string> & arr, unordered_map<string, int> & dp, int start, string cur_str) {
        if(start >= arr.size()) return 0;
        auto ind = dp.find(cur_str);
        if(ind != dp.end()) return ind->second;
        int res = 0;
        for(int i = start; i < arr.size(); ++i) {
            if(is_ok(cur_str, arr[i])) {
                res = max(res, int(dfs(arr, dp, i+1, cur_str+arr[i])+arr[i].length()));
            }
        }
        dp[cur_str] = res;
        return res;
    }
    
    bool is_ok(string & cur_str, string new_str) {
        vector<int> cc(26, 0);
        for(int i=0;i<cur_str.length();++i) {
            cc[int(cur_str[i]-'a')] = 1;
        }
        for(int i=0;i<new_str.length();++i) {
            if(cc[int(new_str[i]-'a')] > 0) return false;
        }
        return true;
    }
    
    bool check_valide(string & str) {
        vector<int> cc(26, 0);
        for(int i=0;i<str.length();++i) {
            int ind = int(str[i]-'a');
            if(cc[ind] > 0) return false;
            cc[ind] = 1;
        }
        return true;
    }
};
