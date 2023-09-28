class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int h = nums.size() - 1;
        for(int i = 0; i < nums.size();i++){
            if(nums[m] % 2 != 0){
                m++;
            }
            else{
                swap(nums[m],nums[l]);
                l++;
                m++;
            }
        }
        return nums;
    }
};