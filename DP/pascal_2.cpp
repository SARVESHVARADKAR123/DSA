class Solution {
public:

    int pascal(int i,int j,vector<vector<int>>&dp){
        if(j==0 || j==i) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=pascal(i-1,j-1,dp)+ pascal(i-1,j,dp);
    }



    vector<int> getRow(int rowIndex) {
      
        vector<vector<int>>dp(rowIndex+1,vector<int>(rowIndex+1,-1));
        vector<int>row(rowIndex+1);
            for(int j=0;j<rowIndex+1;j++){
                row[j]=pascal(rowIndex,j,dp);
            }


        return row ;       
    }
};