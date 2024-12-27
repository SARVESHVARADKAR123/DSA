class Solution {
  public:
  
  
  
    void solution (vector<int>&arr,vector<int>&ds,int ind,int sum){
        if(ind==arr.size()){
            ds.push_back(sum);
            return;
        }
        
        //picked
        solution(arr,ds,ind+1,sum+arr[ind]);
        //not pick
        solution(arr,ds,ind+1,sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ds;
        solution(arr,ds,0,0);
        return ds;
        
    }
};