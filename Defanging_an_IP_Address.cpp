//Leetcode 1108

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (int i=0;i<address.length();++i) {
            if(address[i] != '.') res += address[i];
            else res += "[.]";
        }
        return res;
    }
};
