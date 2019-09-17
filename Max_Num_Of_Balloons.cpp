//Leetcode 1189

class Solution {
public:
	int maxNumberOfBalloons(string text) { //balloon
		int a_num=0,b_num=0,l_num=0,o_num=0,n_num=0;
		for(int i=0;i<text.length();++i) {
			if(text[i]=='a') a_num++;
			else if(text[i]=='b') b_num++;
			else if(text[i]=='l') l_num++;
			else if(text[i]=='o') o_num++;
			else if(text[i]=='n') n_num++;
		}
		l_num /= 2;
		o_num /= 2;
		return min(a_num, min(b_num, min(l_num, min(o_num, n_num))));
	}
};
