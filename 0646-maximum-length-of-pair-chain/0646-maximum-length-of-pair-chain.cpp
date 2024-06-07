class Solution {
public:
    int func(int ind, int prev,vector<vector<int>>& pairs,vector<vector<int>>& dp){
        //Base Case
        if(ind >= pairs.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        //Transition
        
        int len = func(ind+1,prev,pairs,dp);
        if(prev == -1 || pairs[ind][0] > pairs[prev][1]){
            len = max(len,1+func(ind+1,ind,pairs,dp));
        }
    
        return dp[ind][prev+1] = len;
    }


    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(pairs.size()+1,vector<int>(pairs.size()+1,-1));
        return func(0,-1,pairs,dp);
    }
};