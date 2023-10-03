class Solution {
private:
    int func(vector<int>& nums, int mid){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }


public:
    int smallestDivisor(vector<int>& nums, int threshold){
        int n = nums.size();
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());

        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(func(nums,mid) <= threshold){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};