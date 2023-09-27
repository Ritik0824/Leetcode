class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;

        int mid = start + (end-start)/2;
        while(start <= end){
            if(nums[mid] == target){
                ans = mid;
                end = mid-1;
            }

            else if(nums[mid] < target){
                start = mid+1;
            }

            else if(nums[mid] > target){
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
            
    int LastOcc(vector<int>& nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;

        int mid = start + (end-start)/2;
        while(start <= end){
            if(nums[mid] == target){
                ans = mid;
                start = mid+1;
            }

            else if(nums[mid] < target){
                start = mid+1;
            }

            else if(nums[mid] > target){
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int firstIndex = firstOcc(nums,target);
        int lastIndex = LastOcc(nums,target);

        result.push_back(firstIndex);
        result.push_back(lastIndex);
        
        return result;
    }
};