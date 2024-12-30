class Solution {
public:
    int solve(vector<int>&cost,int ind,vector<int>&dp){
        if(ind == 0 ){
            return cost[ind];
        }
        if(ind == 1 ){
            return cost[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int step_2=0;
        int step_1=0;
        step_1=cost[ind]+solve(cost,ind-1,dp);
        if(ind>=2){
            step_2=cost[ind]+solve(cost,ind-2,dp);
        }
        return dp[ind]=min(step_1,step_2);
    }

    int solvetab(vector<int>&cost,int n){
        vector<int>dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
            }
        
        return min(dp[n-1],dp[n-2]);
    }

    int spcopt(vector<int>&cost,int n){
        int prev=cost[0];
        int curr=cost[1];
        int next=0;

        for(int i=2;i<n;i++){
            next=cost[i]+min(prev,curr);
            prev=curr;
            curr=next;
        }

        return min(curr,prev);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        //vector<int>dp(cost.size()+1,-1);
        return spcopt(cost,cost.size());
    }
};