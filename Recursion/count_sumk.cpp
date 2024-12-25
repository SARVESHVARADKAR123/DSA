
int solution(int ind,vector<int>& arr,int n,vector<vector<int>>&dp,int sum, int k)
{
	if(sum>k) return 0;
	if(ind==n){
		if(sum==k){
			return 1;
		}
		else {
			return 0;
		}
	}
	if(dp[ind][sum]!=-1) return dp[ind][sum];


	
	int l=solution(ind+1,arr,n,dp,sum+arr[ind],k);

	int r=solution(ind+1,arr,n,dp,sum,k);

	return dp[ind][sum]=l+r;
}



int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));

	return solution(0,arr,n,dp,0,k);
}
