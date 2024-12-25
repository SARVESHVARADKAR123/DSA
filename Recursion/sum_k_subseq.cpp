#include<iostream>
#include<vector>
using namespace std;


// updated code for only one subsequesce with sum k
bool sumk(int ind,vector<int> &A,vector<int> &ds,int n,int k,int sum){ 
    if(ind==n){
        if(k==sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;

            return true;
        }
        return false;
    }



    //pick condition
    ds.push_back(A[ind]);
    sum+=A[ind];
    if(sumk(ind+1,A,ds,n,k,sum)){
        return true;
    }
    sum-=A[ind];
    ds.pop_back();

    //non pick condition
    if(sumk(ind+1,A,ds,n,k,sum))  return true;

    return false;

}


int main(){
    
    vector<int> A = {1,2,3,3,5};
    vector<int> ds;

    sumk(0,A,ds,A.size(),6,0);
    return 0;
}