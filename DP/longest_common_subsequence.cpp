       
class Solution {
public:

    int sol(string &text1, string &text2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0 ) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]){
            return dp[ind1][ind2]=1+sol(text1,text2,ind1-1,ind2-1,dp);
        }

        return dp[ind1][ind2]=0+max(sol(text1,text2,ind1-1,ind2,dp),sol(text1,text2,ind1,ind2-1,dp));
    }

    
    int longestCommonSubsequence(string text1, string text2) {
        int p=text1.size();
        int q=text2.size();
        vector<vector<int>>dp(p,vector<int>(q,-1));

        return sol(text1,text2,p-1,q-1,dp);
    }
};