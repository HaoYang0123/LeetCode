//Leetcode 295
//方法1：使用multiset来记录数据，几乎超时

class MedianFinder {
public:
	multiset<int> ss;
	MedianFinder() {
	}

	void addNum(int num) {
		ss.insert(num);
	}

	double findMedian() {
		if(ss.size()==0) return 0.0;
		int median = ss.size() / 2;
		auto ind = ss.begin();
		for(int j=0;j<median;++j) ind++;
		if(ss.size() % 2) return *ind;
		return ((long long)(*ind) + (long long)(*(--ind))) / 2.0;
	}
};

//方法2：同样使用multiset来记录，但是增加一个变量median_index记录当前的中间位置（如果数目是偶数，记录median中的较大值）
class MedianFinder {
public:
	multiset<int> ss;
	multiset<int>::iterator median_index;
	MedianFinder() {
	}

	void addNum(int num) {
		if(ss.size() == 0) { //如果当前没有元素，直接加进去，median_index就是当前加进去的位置
			ss.insert(num);
			median_index = ss.begin();
			return;
		}
		if(ss.size() % 2) { // has odd size
			int median_value = *median_index;
			ss.insert(num);
			if(num >= median_value) ++median_index; //如果当前增加的元素大于等于median_value，则更新median_index【注：等于也需要更新】
		}
		else { // has even size
			int median_value_big = *median_index;
			auto index2 = median_index;
			--index2;
			int median_value_small = *index2;
			if(num < median_value_big && num >= median_value_small) {
				ss.insert(num);
				--median_index;
			}
			else if(num < median_value_small) {
				--median_index;
				ss.insert(num);
			}
			else ss.insert(num);
		}
	}

	double findMedian() {
		if(ss.size() % 2) return *median_index;
		auto index2 = median_index;
		--index2;
		return ((long long)(*median_index) + (long long)(*index2)) / 2.0;
	}
};
