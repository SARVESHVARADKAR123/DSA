// approcach 1

class Solution {
public:

    void soln(vector<int>& nums,vector<vector<int>>&ans,vector<int>&ds,vector<bool>& ispick){
        if(ds.size()==nums.size()){
            //add the current permutation to the ans
                ans.push_back(ds);
                return;
            }
        

        for(int i=0;i<nums.size();i++){
            //if the current element is not picked
            if(!ispick[i]){
                //pick the current element
                ispick[i]=true;
                ds.push_back(nums[i]);
                //recursively call the function for the next index
                soln(nums,ans,ds,ispick);
                //backtrack
                ds.pop_back();
                ispick[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> ispick(nums.size(),0);
        soln(nums,ans,ds,ispick);
        return ans;
    }
};


// approach 2

class Solution {
public:

    void soln(vector<int>& nums,vector<vector<int>>&ans,int ind,int n){
        if(ind==nums.size()){
                //add the current permutation to the ans
                ans.push_back(nums);
                return;
            }
        
        for(int i=ind;i<n;i++){
            //swap the current element with the element at index ind
            swap(nums[ind],nums[i]);
            //recursively call the function for the next index
            soln(nums,ans,ind+1,n);
            //backtrack
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        soln(nums,ans,0,nums.size());
        return ans;
    }
};