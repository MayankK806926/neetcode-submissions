class Solution {
public:
    int rec(int ind,vector<int>& cost,vector<int>& dp){
        if(ind >= cost.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        return dp[ind] = cost[ind] + min(rec(ind+1,cost,dp),rec(ind+2,cost,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n,-1);
        // return min(rec(0,cost,dp),rec(1,cost,dp));
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 0;

        for(int i=2;i<=n;++i){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};
