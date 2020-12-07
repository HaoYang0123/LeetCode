//Leetcode 1678

class Solution {
public:
    string interpret(string command) {
        int i = 0;
        string res = "";
        for(;i<command.length();) {
            if (command[i] == 'G') {
                res += "G";
                ++i;
            }
            else if(command[i+1] == ')') {
                res += "o";
                i += 2;
            }
            else {
                res += "al";
                i += 4;
            }
        }
        return res;
    }
};
