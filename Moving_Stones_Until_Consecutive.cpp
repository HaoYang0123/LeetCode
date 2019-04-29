//Leetcode 1033

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> d(3,0);
		d[0]=a;
		d[1]=b;
		d[2]=c;
		sort(d.begin(), d.end());
		vector<int> res(2,0);
		int minv = 0;
		if(d[1] > d[0]+1) ++minv;
		if(d[2] > d[1]+1) ++minv;
		if(d[1] == d[0]+2) minv = 1; //这两种情况，比如:[1,3,9]，其实只需要一步，直接将9移到2的位置即可
		if(d[2] == d[1]+2) minv = 1;
		int maxv = (d[2]-d[1]-1)+(d[1]-d[0]-1);
		res[0] = minv;
		res[1] = maxv;
		return res;
    }
};
