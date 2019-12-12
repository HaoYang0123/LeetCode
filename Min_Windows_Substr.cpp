//Leetcode 76
//代码写得有些乱，特别是对于find_len函数，需要找最小和最大位置，应该之前保存一下最好。

//一年前写的代码：
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

//重新写了一份，代码思路清楚一些
class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char,int> c2n; //t中各字符出现的次数
		for(int i=0;i<t.length();++i) c2n[t[i]]++;
		int start=0,end=0;
		int res = INT_MAX, res_s=-1, res_e=-1;
		while(end<s.length()) {
			auto ind = c2n.find(s[end]);
			if(ind == c2n.end()) {
				++end;
				continue;
			}
			--c2n[s[end]];
			++end;
			bool flag = is_ok(c2n);
			if(flag) { //当前成功了，则需要调整start
				while(start<end) {
					auto ind2 = c2n.find(s[start]);
					if(ind2 == c2n.end()) {
						++start;
						continue;
					}
					++c2n[s[start]];
					++start;
					if(!is_ok(c2n)) break; //只有当start字符使得c2n不满足要求时退出
				}
				int cur_len = end-start; //当前的[start-1,end-1]为满足要求的子字符串
				if(res > cur_len) {
					res = cur_len;
					res_s = start-1;
					res_e = end-1;
				}
			}
		}
		if(res == INT_MAX) return "";
		return s.substr(res_s, (res_e - res_s + 1));
	}
	
	inline bool is_ok(unordered_map<char,int> & c2n) {
		for(auto ind = c2n.begin(); ind != c2n.end(); ++ind) {
			if(ind->second > 0) return false;
		}
		return true;
	}
};
