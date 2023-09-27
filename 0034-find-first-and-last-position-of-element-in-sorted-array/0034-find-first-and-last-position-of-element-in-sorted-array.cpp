class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s =0;
        int e = nums.size() - 1;
        bool first = false;

        while(s <= e){
            if(nums[s] == target){
                first = true;
                break;
            }
            else{
                s++;
            }
        }
        bool last = false;
        while(s <= e){
            if(nums[e] == target){
                last = true;
                break;
            }
            else{
                e--;
            }
        }
        if(first,last){
            return {s,e};
        }
        else return {-1,-1};
    }
};