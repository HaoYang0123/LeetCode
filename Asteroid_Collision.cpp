// Leetcode 735

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); ++i) {
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else {
                if(st.empty()) st.push(asteroids[i]);
                else {
                    bool cur_can_push = false;
                    while(!st.empty()) {
                        int cur = st.top();
                        if(cur < 0) {
                            cur_can_push = true;
                            break;  //因为如果当前是负数，表示前面的肯定也全部是负数（不然，自己要不把所有前面正数击败，要不自己被击败）
                        }
                        else {  //如果是个正数，得判断哪个大
                            if(abs(cur) > abs(asteroids[i])) {
                                cur_can_push = false;
                                break;
                            }
                            else if (abs(cur) < abs(asteroids[i])) {
                                st.pop();
                                cur_can_push = true;
                            }
                            else {
                                st.pop();
                                cur_can_push = false;
                                break;
                            }
                        }
                    }
                    if (cur_can_push) st.push(asteroids[i]);
                }
            }
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
