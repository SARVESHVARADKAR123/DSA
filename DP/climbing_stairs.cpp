class Solution {
public:
    int sol(int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        int step1=sol(n-1,dp);
        int step2=sol(n-2,dp);

        return dp[n]=step2+step1;

    }

    int soltab(int n){
        vector<int>tab(n+1,0);

        tab[0]=1;
        tab[1]=1;

        for(int i=2;i<=n;i++){
            tab[i]=tab[i-1]+tab[i-2];
        }
        return tab[n];
    } 
    int space_opt(int n){
        int prev1=1;
        int prev2=1;
        int curr;

        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }

    int climbStairs(int n) {
        //vector<int>dp(n+1,-1);
        //return sol(n,dp);
        return soltab(n);
        //return space_opt(n);
    }
};