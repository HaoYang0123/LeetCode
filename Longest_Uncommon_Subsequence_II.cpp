// leetcode 522

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        map<int, vector<string>> ss;
        for(int i=0; i<strs.size(); ++i) {
            ss[strs[i].length()].push_back(strs[i]);
        }
        vector<string> big_strs;
        for(auto idx=ss.rbegin(); idx != ss.rend(); ++idx) {  //按长度从大到小排序，来找答案（因为是找最长的答案）
            vector<string> & a = idx->second;
            vector<string> can_str = get_str(a);
            for(int i=0; i<can_str.size(); ++i) {
                if(is_ok(can_str[i], big_strs)) return can_str[i].length();
            }
            big_strs.insert(big_strs.end(), a.begin(), a.end());
        }
        return -1;
    }
    
    inline bool is_substr(string & small, string & big) {
        //判断small是不是big的子子符串
        int i=0, j=0;
        while(i<small.length() && j<big.length()) {
            if(small[i] == big[j]) {
                ++i;
                ++j;
            }
            else ++j;
        }
        return i>=small.length();
    }
    
    inline bool is_ok(string & str, vector<string> & big_strs) {
        //判断str（长度比big_strs要小），是否是big_strs中的子子符串
        for(int i=0; i<big_strs.size(); ++i) {
            if(is_substr(str, big_strs[i])) return false;
        }
        return true;
    }
    
    inline vector<string> get_str(vector<string> & strs) {
        //去掉相同的字符串，因为相同字符串，一定不能作为答案
        unordered_map<string, int> str2num;
        for(int i=0; i<strs.size(); ++i) str2num[strs[i]]++;
        vector<string> res;
        for(auto idx=str2num.begin(); idx!=str2num.end(); ++idx) {
            if(idx->second == 1) res.push_back(idx->first);
        }
        return res;
    }
};
