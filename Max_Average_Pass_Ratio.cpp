// Leetcode 1792
//时间复杂度O(N^logM), 其 N为extraStudents大小，M为classes数量
//使用优先队列来保存当前最大的提升量
//提升量：add=(x+1)/(y+1)-x/y=(y-x)/(y*(y+1))

struct two_item {
	long long x, y;
	double add;
	two_item(long long x0, long long y0) {
		this->x = x0;
		this->y = y0;
		this->add = (this->y - this->x) * 1.0 / (this->y * (this->y + 1));
	}
	bool operator<(const two_item& a) const {
		if (this->add == a.add) return this->y > a.y;
		return this->add < a.add;
	}
};
class Solution {
public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		priority_queue<two_item> p;
		double res = 0.0;
		int n = classes.size();
		for (int i = 0; i < n; ++i) {
			res += classes[i][0] * 1.0 / classes[i][1];
			p.push(two_item(classes[i][0], classes[i][1]));
		}
		for (int i = 0; i < extraStudents; ++i) {
			const two_item t = p.top();
			p.pop();
			res += t.add;
			p.push(two_item(t.x + 1, t.y + 1));
		}
		return res / n;
	}
};
