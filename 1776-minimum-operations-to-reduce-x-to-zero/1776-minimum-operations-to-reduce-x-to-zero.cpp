class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max_len = 0;
        int target = sum - x;
        if(target == 0)
            return nums.size();
        
        int start_idx = 0, end_idx = 0, curr_sum = 0;
        for(end_idx = 0; end_idx < nums.size(); end_idx++)
        {
            curr_sum += nums[end_idx];
            
            while((curr_sum > target) && (start_idx <= end_idx))
            {
                curr_sum -= nums[start_idx];
                start_idx++;
            }
            
            if(curr_sum == target)
            {
                max_len = max(max_len, end_idx-start_idx+1);
            }
        }
        
        return max_len ? nums.size() - max_len : -1;
    }
};