class Solution {
public:
    bool sol(vector<int>& arr, int target, int ind, vector<vector<int>>& dp) {
        if (target == 0) return true;   // Subset with the required sum found
        if (ind < 0) return false;     // No elements left to consider

        if (dp[ind][target] != -1) return dp[ind][target];  // Use precomputed result

        // Decision: include or exclude the current element
        bool notTake = sol(arr, target, ind - 1, dp);
        bool take = (target >= arr[ind]) ? sol(arr, target - arr[ind], ind - 1, dp) : false;

        return dp[ind][target] = take || notTake;  // Memoize result
    }
    
    bool soltab(vector<int>& arr, int tar){
        int n=arr.size();
        vector<vector<bool>> dp(n, vector<bool>(tar + 1, false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=tar){
            dp[0][arr[0]]=true;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=tar;target++){
                bool notTake =dp[ind-1][target];
                bool take = (target >= arr[ind]) ? dp[ind - 1][target - arr[ind]]: false;

                dp[ind][target] = take || notTake; 
                
            }
        }
        return dp[n-1][tar];
        
    }
    
bool spcopt(vector<int>& arr, int tar){
        int n=arr.size();
       vector<bool>prev(tar+1,false);
       //vector<bool>curr(tar+1,false);
        
        prev[0]=true;
        if(arr[0]<=tar){
            prev[arr[0]]=true;
        }
        
        for(int ind=1;ind<n;ind++){
            vector<bool>curr(tar+1,false);
            curr[0]=true;
            for(int target=1;target<=tar;target++){
                bool notTake =prev[target];
                bool take = (target >= arr[ind]) ? prev[target - arr[ind]]: false;

                curr[target] = take || notTake; 
                
            }
            prev=curr;
        }
        return prev[tar];
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        //vector<vector<int>> dp(n, vector<int>(target + 1, -1));  // Initialize DP table with -1
        return spcopt(arr, target);
    }
};
