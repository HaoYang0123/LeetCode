//Leetcode 821
//两个解法，第一种的时间复杂度是O(NLogK)，其中K是C的位置数目
//先扫描一遍将C的位置记录下来，然后再扫描一遍，找到当前位置与最近的C位置，找这个最近的位置用了upper_bound二分查找（O(LogK))。
//第二种解法的时间复杂度是O(N)，也是两遍扫描
//第一遍：先从左向右扫描，得到当前位置与最近左边C位置的距离；第二遍：从右向左扫描，得到当前位置与最近右边C位置的距离。
//因为任意位置与C最近的只能是最近的左边和最近的右边位置
//==============================第一种思路==============================
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> pos;
        for(int i=0;i<S.length();++i) {
            if(S[i]==C) pos.push_back(i);
        }
        vector<int> res(S.length(), 0);
        for(int i=0;i<S.length();++i) {
            if(S[i]==C) continue;
            auto ind = upper_bound(pos.begin(), pos.end(), i);
            if(ind==pos.begin()) res[i] = (pos[0]-i);
            else if(ind==pos.end()) res[i] = (i-pos[pos.size()-1]);
            else {
                int f = (*ind-i);
                int b = (i-(*(ind-1)));
                res[i] = min(f,b);
            }
        }
        return res;
    }
};

//==============================第二种思路==============================
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int l = S.length();
        vector<int> res(l, INT_MAX);
        int prev = -1, post = -1;
        for(int i=0;i<l;++i) {
            if(S[i]==C) { 
                res[i]=0;
                prev = i;
            }
            else {
                if(prev != -1) {
                    res[i] = (i-prev);
                }
            }
        }
        for(int i=l-1;i>=0;--i) {
            if(S[i]==C) {
                post = i;
            }
            else {
                if(post != -1) {
                    res[i] = min(res[i], post - i);
                }
            }
        }
        return res;
    }
};
