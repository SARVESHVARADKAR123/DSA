class Solution {
public:

    bool check(vector<int>& nums,int ind,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind<0 || target<0) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];
        return dp[ind][target]=check(nums,ind-1,target-nums[ind],dp) || check(nums,ind-1,target,dp);
    }

    bool soltab(vector<int>& nums,int tar){
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(tar+1,false));

        vector<bool>prev(tar+1,false);
        prev[0]=true;
        if(nums[0]<=tar){
            prev[nums[0]]=true;
        }
        vector<bool>curr(tar+1,false);
        curr[0]=1;

        for(int ind=1;ind<n;ind++){
            
            
            for(int target=0;target<=tar;target++){
                bool pick=(target-nums[ind]>0)?prev[target-nums[ind]]:false;
                bool notpick=prev[target];
                curr[target]=pick||notpick;
            }
            prev=curr;
        }


        return prev[tar];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        //vector<vector<int>>dp(n,vector<int>(target+1,-1));
        //return check(nums,n-1,target,dp);
        return soltab(nums,target);
    }
};