//Leetcode 804

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string mm[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ss;
        for(int i=0;i<words.size();++i) {
            string tmp = "", w = words[i];
            for(int j=0;j<w.length();++j) {
                tmp += mm[w[j]-'a'];
            }
            ss.insert(tmp);
        }
        return ss.size();
    }
};
