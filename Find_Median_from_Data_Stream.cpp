//Leetcode 295
//使用map来记录数据
//几乎超时

class MedianFinder {
public:
	map<int,int> val2num;
	int count;
	MedianFinder() {
		count = 0;
	}

	void addNum(int num) {
		val2num[num]++;
		count++;
	}

	double findMedian() {
		bool is_odd = count % 2;
		int median_k = count / 2; //median position
		auto start_ind = val2num.begin();
		int low = 0, high = 0;
		while(true) {
			high = low + start_ind->second;
			if(low <= median_k && high >= median_k + is_odd) break;
			start_ind++;
			low = high;
		}
		if(is_odd) return start_ind->first;
		if(high == median_k)
			return ((long long)(start_ind->first)+(long long)((++start_ind)->first)) / 2.0;
		return start_ind->first;
	}
};
