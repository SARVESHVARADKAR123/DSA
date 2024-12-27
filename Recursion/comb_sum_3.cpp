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


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        for (int i = 0; i < 9; i++) {
            nums[i] = i + 1;
        }
        vector<vector<int>> ans;
        vector<vector<int>> finalans;

        vector<int> ds;
        solution(nums, ans, ds, 0, nums.size(), n);

        for(auto comb:ans){
            if(comb.size()==k){
                finalans.push_back(comb);
            }
        }
        return finalans;
    }
};