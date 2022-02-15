// Leetcode 2170

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> even2num, odd2num;
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            if(i % 2 == 0) even2num[nums[i]]++;
            else odd2num[nums[i]]++;
        }
        int even_num = (n+1)/2;
        int odd_num = n/2;
        int evenfirstV = 0, evenfirstN = 0;
        int evenSecondV = 0, evenSecondN = 0;
        for(auto idx = even2num.begin(); idx != even2num.end(); ++idx) {
            int tmpV = idx->first;
            int tmpN = idx->second;
            if(tmpN >= evenfirstN) {
                evenSecondV = evenfirstV;
                evenSecondN = evenfirstN;
                evenfirstV = tmpV;
                evenfirstN = tmpN;
            }
            else if(tmpN >= evenSecondN) {
                evenSecondV = tmpV;
                evenSecondN = tmpN;
            }
        }
        int oddfirstV = 0, oddfirstN = 0;
        int oddSecondV = 0, oddSecondN = 0;
        for(auto idx = odd2num.begin(); idx != odd2num.end(); ++idx) {
            int tmpV = idx->first;
            int tmpN = idx->second;
            if(tmpN >= oddfirstN) {
                oddSecondV = oddfirstV;
                oddSecondN = oddfirstN;
                oddfirstV = tmpV;
                oddfirstN = tmpN;
            }
            else if(tmpN >= oddSecondN) {
                oddSecondV = tmpV;
                oddSecondN = tmpN;
            }
        }
        int evenOp = even_num - evenfirstN;
        if(evenfirstV != oddfirstV) evenOp += (odd_num - oddfirstN);
        else evenOp += (odd_num - oddSecondN);
        int oddOp = odd_num - oddfirstN;
        if(oddfirstV != evenfirstV) oddOp += (even_num - evenfirstN);
        else oddOp += (even_num - evenSecondN);
        return min(evenOp, oddOp);
    }
};
