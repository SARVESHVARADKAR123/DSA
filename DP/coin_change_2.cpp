class Solution {
public:
    int sol(vector<int>& coins,int amount,int ind, vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(amount<0 || ind<0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick=sol(coins,amount-coins[ind],ind,dp);
        int notpick=sol(coins,amount,ind-1,dp);
        return dp[ind][amount]=pick+notpick;
    }


    int soltab(int amt, vector<int>& coins) {
        int n = coins.size();

        // Use long long for DP table to avoid overflow
        vector<vector<long long>> dp(n + 1, vector<long long>(amt + 1, 0));

        // Base case: There's one way to make amount 0 (use no coins)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int ind = 1; ind <= n; ind++) {
            for (int amount = 0; amount <= amt; amount++) {
                // Pick case: Include the current coin (coins[ind-1])
                long long pick = 0;
                if (amount - coins[ind - 1] >= 0) {
                    pick = dp[ind][amount - coins[ind - 1]]; // Same row for infinite supply
                }
                
                // Not pick case: Exclude the current coin
                long long notpick = dp[ind - 1][amount];

                dp[ind][amount] = pick + notpick;
            }
        }

        return dp[n][amt];
    }

    int spcopt(int amt, vector<int>& coins){
        int n=coins.size();
        // Use long long for DP table to avoid overflow
        //vector<vector<long long>> dp(n + 1, vector<long long>(amt + 1, 0));

        vector<long long>prev(amt + 1, 0);
        vector<long long>curr(amt + 1, 0);

        // Base case: There's one way to make amount 0 (use no coins)
        prev[0]=1;

        // Fill the DP table
        for (int ind = 1; ind <= n; ind++) {
            fill(curr.begin(),curr.end(),0);
            for (int amount = 0; amount <= amt; amount++) {
                // Pick case: Include the current coin (coins[ind-1])
                long long pick = 0;
                if (amount - coins[ind - 1] >= 0) {
                    pick = curr[amount - coins[ind - 1]]; // Same row for infinite supply
                }

                
                
                // Not pick case: Exclude the current coin
                long long notpick = prev[amount];

                if (pick > LONG_LONG_MAX - notpick) {
                    curr[amount] = LONG_LONG_MAX; // Or another suitable sentinel value
                } else {
                    curr[amount] = pick + notpick;
                }
            }
            prev=curr;
        }
        return prev[amt];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (n == 0) return 0;

        return spcopt(amount, coins);
    }
};