class Solution {
public:
    int func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        //Base case
        if(ind >= arr.size()) return 0;
        if(target == 0) return 1;

        if(dp[ind][target] != -1) return dp[ind][target];
        //Transition
        int take = 0;
        if(arr[ind] <= target){
            take = func(ind,target - arr[ind],arr,dp);
        }
        int notTake = func(ind+1,target, arr,dp);

        return dp[ind][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));

        return func(0,amount,coins,dp);
    }
};