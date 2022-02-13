// Leetcode 917
// 两头指针left和right

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.length()-1;
        while(left < right) {
            while(left<right && (s[left] < 'a' || s[left] > 'z') && (s[left] < 'A' || s[left] > 'Z')) ++left;
            while(left<right && (s[right] < 'a' || s[right] > 'z') && (s[right] < 'A' || s[right] > 'Z')) --right;
            if(left < right) {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                ++left;
                --right;
            }
        }
        return s;
    }
};
