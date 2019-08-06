//Leetcode 1146
//总的时间复杂度是O(MlogN)，M为操作次数，N是数组大小

class SnapshotArray {
public:
	vector<map<int, int>> data; //里面的map表示snap_id对应的值
	int cur_snap;
	SnapshotArray(int length) {
		data.resize(length);
		cur_snap = 0;
		for (int i = 0; i < length; ++i) {
			data[i][cur_snap] = 0;
		}
	}

	void set(int index, int val) {
        if(data[index][cur_snap] != val)
		    data[index][cur_snap] = val;
	}

	int snap() {
		cur_snap++;
		return cur_snap - 1;
	}

	int get(int index, int snap_id) {
        map<int,int> & mm = data[index]; //之前没加引用传递，导致超时。以后得注意，引用传递是传指针，而非引用是Copy
        //找到最后一个小于等于snap_id的key
        auto index2 = mm.upper_bound(snap_id);
        --index2;
        return index2->second;
	}
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
