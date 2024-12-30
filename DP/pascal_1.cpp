class Solution {
public:

    int pascal(int i,int j,vector<vector<int>>&dp){
        if(j==0 || j==i) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=pascal(i-1,j-1,dp)+ pascal(i-1,j,dp);
    }

    int soltab(int p,int q){
        if(q==0 || q==p){
            return 1;
        }

        vector<vector<int>>dp(p+1,vector<int>(p+1,0));
        
        for(int i=0;i<=p;i++){
            dp[i][0]=1;
            dp[i][i]=1;
        }

        for(int i=2;i<=p;i++){
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[p][q];
    }


    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>trg;
        vector<vector<int>>dp(numRows+1,vector<int>(numRows+1,-1));
        for(int i=0;i<numRows;i++){
            vector<int>row(i+1);
            for(int j=0;j<i+1;j++){
                row[j]=pascal(i,j,dp);
            }
            trg.push_back(row);
        }

        return trg;

    }
};