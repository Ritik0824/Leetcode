class Solution {
public:
int dp[1001][1001];
    int solve(string &s,string &t,int ind1,int ind2)
    {
        if(ind2==0) return 1; // we have find the string t so return 1 for this way
        if(ind1==0) return 0; // string s has been completely checked no string t found so return 0
        if(dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        if(s[ind1-1]==t[ind2-1])
        {
            return dp[ind1][ind2]= solve(s,t,ind1-1,ind2-1)+solve(s,t,ind1-1,ind2);
         // take this index or not if taken then move both indexes and look for next
        }
        else
        {
            return dp[ind1][ind2]= solve(s,t,ind1-1,ind2);
        // cant take this index so move for next in string s
        }
    }  

   
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,s.size(),t.size());
    }
};