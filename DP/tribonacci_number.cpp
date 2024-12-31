class Solution {
public:
    int sol(int n,vector<int>&dp){
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=sol(n-1,dp)+sol(n-2,dp)+sol(n-3,dp);
    }
    int soltab(int n){
        vector<int>dp(n+1,0);
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }

    int spcopt(int n){
        //vector<int>dp(n+1,0);
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        int prev1=0;
        int prev2=1;
        int prev3=1;
        int curr=0;
        for(int i=3;i<=n;i++){
            curr=prev1+prev2+prev3;
            prev1=prev2;
            prev2=prev3;
            prev3=curr;
        }
        return prev3;
    }

    int tribonacci(int n) {
        //vector<int>dp(n+1,-1);
        //return sol(n,dp);
        return spcopt(n);;
    }
};