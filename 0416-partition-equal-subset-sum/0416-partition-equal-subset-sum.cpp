class Solution {
public:
    bool func(int ind,int target,vector<int>& nums,vector<vector<int> >&dp){
        if(target == 0) return true;
        if(ind == 0){
            if(nums[0] == target){
                return true;
            }
            else return false;
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        bool notTake = func(ind-1,target,nums,dp);
        bool take = false;
        if(target >= nums[ind]){
            take += func(ind-1, target - nums[ind], nums,dp);
        }

        return dp[ind][target] = notTake | take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        
        for(int i = 0; i < n; i++){
            totSum += nums[i];
        }
        if(totSum % 2 != 0) return false;
        int target = totSum/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        return func(n-1,target,nums,dp);
    }
};