//Leetcode 76
//代码写得有些乱，特别是对于find_len函数，需要找最小和最大位置，应该之前保存一下最好。

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t2; //存储t中各字符出现的次数
        for(int i=0;i<t.length();++i) {
            char c = t[i];
            if(t2.find(c) == t2.end()) t2[c] = 1;
            else t2[c]++;
        }
        int m = t.length();
        unordered_map<char, vector<int>> mm; //存储t2中字符在s中出现的位置信息
        int cur_s = 0;
        int i = 0;
        int res = 0;
        pair<int, int> res2;
        for (;i<s.length();++i) {
            int c = s[i];
            if(t2.find(c) != t2.end()) {
                if(t2[c] > 0) {
                    t2[c]--;
                    ++cur_s;
                    if(cur_s == m) { 
                        mm[c].push_back(i);
                        break;
                    }
                    mm[c].push_back(i);
                }
                else {
                    update_vec(mm[c], i);
                }
            }
        }
        if(i>=s.length()) return "";
        pair<int, int> min_max = find_len(mm);
        res = min_max.second-min_max.first+1;
        res2 = min_max;
        //cout<<res<<endl;
        ++i;
        char target = s[min_max.first];
        for(;i<s.length();++i) {
            int c = s[i];
            if(c == target) {
                update_vec(mm[c], i);
                pair<int, int> min_max = find_len(mm);
                int ll = min_max.second-min_max.first+1;
                if(ll < res) {
                    res = ll;
                    res2 = min_max;
                }
                target = s[min_max.first];
            }
            else if (t2.find(c) != t2.end()) {
                update_vec(mm[c], i);
            }
        }
        string final_res = "";
        for(int i=res2.first; i<= res2.second;++i) final_res += s[i];
        return final_res;
    }
    pair<int, int> find_len(unordered_map<char, vector<int>> & mm) {
        int min=INT_MAX, max=INT_MIN;
        for(auto ind = mm.begin(); ind != mm.end(); ++ind) {
            vector<int> vec = ind->second;
            for(int i=0;i<vec.size();++i) {
                if(vec[i]<min) min=vec[i];
                if(vec[i]>max) max=vec[i];
            }
        }
        return pair<int, int>(min, max);
    }
    void update_vec(vector<int> & vec, int newIndex) {
        int min_ind = -1, min_val = INT_MAX;
        for(int i=0;i<vec.size();++i) {
            if(vec[i] < min_val) {
                min_val = vec[i];
                min_ind = i;
            }
        }
        vec[min_ind] = newIndex;
    }
};
