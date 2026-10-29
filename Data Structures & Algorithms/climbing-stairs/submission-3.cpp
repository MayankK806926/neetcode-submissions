class Solution {
public:
    // int rec(int n,vector<int>& dp){
    //     if(n <= 1) return 1;
    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = rec(n-1,dp) + rec(n-2,dp);
    // }

    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return rec(n,dp);
        if(n <= 1) return 1;

        int prev = 1,prev2 = 1;
        for(int i=2;i<=n;++i){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
