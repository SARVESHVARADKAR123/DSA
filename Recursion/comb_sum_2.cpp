class Solution {
public:
    void solution(vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int ind,int n,int target){
            if(target==0){
                ans.push_back(ds);
                return ;
            }
        

        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            

            ds.push_back(arr[i]);
            solution(arr,ans,ds,i+1,n,target-arr[i]);
            ds.pop_back();
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        solution(candidates,ans,ds,0,candidates.size(),target);
        return ans;
    }
};