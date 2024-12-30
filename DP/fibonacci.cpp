class Solution {
public:
    int soldp(int n,vector<int>&dp) {
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=soldp(n-1,dp)+soldp(n-2,dp);
    }

    int soltab(int n){
        vector<int>dp(n+1,0);
        if(n==0 || n==1) return n;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int spcopt(int n){
        if(n==0 || n==1) return n;

        int prev=0;
        int curr=1;
        int next=0;
        for(int i=2;i<=n;i++){
            next=prev+curr;
            prev=curr;
            curr=next;
        }
        return curr;
    }
    int fib(int n){
        //vector<int>dp(n+1,-1);
        return spcopt(n);
    }
};