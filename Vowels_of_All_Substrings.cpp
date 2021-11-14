// Leetcode 2063

class Solution {
public:
    long long countVowels(string word) {
        long long num = (long long)(word.length());
        long long res = 0;
        for(long long i=0; i<num; ++i) {
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                long long left_num = i + 1;
                long long right_num = num - i;
                res += left_num * right_num;
            }
        }
        return res;
    }
};
