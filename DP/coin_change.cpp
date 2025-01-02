#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int sol(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
        // Base cases
        if (amount == 0) return 0;           // No coins needed for amount 0
        if (ind < 0 || amount < 0) return INT_MAX; // Invalid case
        
        if (dp[ind][amount] != -1) return dp[ind][amount]; // Memoization

        int pick = INT_MAX;
        if (amount >= coins[ind]) {
            int res = sol(coins, ind, amount - coins[ind], dp); // Recursive call for picking
            if (res != INT_MAX) pick = res + 1; // Update pick if valid
        }

        int notpick = sol(coins, ind - 1, amount, dp); // Recursive call for not picking
        
        // Store and return the minimum of pick and notpick
        return dp[ind][amount] = min(pick, notpick);
    }

    int soltab(vector<int>&coins,int amt){
        int n=coins.size();
        vector<vector<int>> dp(coins.size(), vector<int>(amt + 1, INT_MAX)); // Initialize DP table

        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int amount=0;amount<=amt;amount++){
                int pick = INT_MAX;
                if (amount >= coins[ind]) {
                    int res = dp[ind][amount - coins[ind]]; // Recursive call for picking
                    if (res != INT_MAX) pick = res + 1; // Update pick if valid
                }

                int notpick = dp[ind - 1][amount]; // Recursive call for not picking
                
                // Store and return the minimum of pick and notpick
                dp[ind][amount] = min(pick, notpick);
            }
        }

    return (dp[n-1][amt]==INT_MAX)?-1:dp[n-1][amt];
    }


    
    int spcopt(vector<int>&coins,int amt){
        int n=coins.size();
        vector<int>prev(amt+1,INT_MAX);
        vector<int>curr(amt+1,INT_MAX);
        
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0){
                prev[i]=i/coins[0];
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int amount=0;amount<=amt;amount++){
                int pick = INT_MAX;
                if (amount >= coins[ind]) {
                    int res = curr[amount - coins[ind]]; // Recursive call for picking
                    if (res != INT_MAX) pick = res + 1; // Update pick if valid
                }

                int notpick = prev[amount]; // Recursive call for not picking
                
                // Store and return the minimum of pick and notpick
                curr[amount] = min(pick, notpick);
            }
            prev=curr;
        }


        return (prev[amt]==INT_MAX)?-1:prev[amt];

    }
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size()==0) return -1; // Edge case: no coins available
        //vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1)); // Initialize DP table
        int ans = spcopt(coins,amount);
        // If no solution, return -1
        return ans;
    }
};
