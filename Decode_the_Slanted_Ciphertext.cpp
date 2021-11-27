// Leetcode 2075

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;
        string res = "";
        int cur_pos = 0, cur_i = 0, cur_j = 0;
        while(cur_pos < n) {
            res += encodedText[cur_pos];
            cur_i++;
            if(cur_i == rows)  {
                cur_i = 0;
                cur_j++;
                cur_pos = cur_j;
            }
            else {
                cur_pos += cols+1;
            }
        }
        int i = res.length()-1;
        while(i>=0 && res[i] == ' ') --i;
        return res.substr(0, i+1);
    }
};
