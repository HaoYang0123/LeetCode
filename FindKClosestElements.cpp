class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int ori_k=k;
        if (arr.size() == 0) return res;
        int left = 0, right = arr.size() - 1, mid = 0;
        while(left<=right){
            mid=(left+right)>>1;
            //cout<<mid<<endl;
            if(arr[mid] == x) break;
            if(arr[mid] > x) right = mid-1;
            else left = mid+1;
        }
        //cout<<mid<<"\t"<<arr[mid]<<endl;
        int start = 0, end = 0;
        int m1 = mid-1, m2=mid, m3=mid+1;
        int mIndex=m2, mValue=abs(x-arr[m2]);
        --k;
        if(m1>=0) {
            int c = abs(x-arr[m1]);
            if(c<mValue) {
                mValue=c;
                mIndex=m1;
            }
        }
        if(m3<arr.size()) {
            int c = abs(x-arr[m3]);
            if(c<mValue) {
                mValue=c;
                mIndex=m3;
            }
        }
        start=mIndex;
        end=mIndex;
        while(k) {
            int mValue=INT_MAX;
            int mIndex=-1;
            if(start-1>=0) {
                int c = abs(x-arr[start-1]);
                if(c<mValue) {
                    mValue=c;
                    mIndex=start-1;
                }
            }
            if(end+1<arr.size()) {
                int c = abs(x-arr[end+1]);
                if(c<mValue) {
                    mValue=c;
                    mIndex=end+1;
                }
            }
            if(mIndex==start-1) --start;
            else ++end;
            //cout<<k<<'\t'<<start<<'\t'<<end<<endl;
            --k;
        }
        res.resize(ori_k);
        for(int i=start;i<=end;++i) res[i-start]=arr[i];
        return res;
    }
};
