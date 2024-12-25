#include<iostream>
#include<vector>
using namespace std;

void sumk(int ind,vector<int> &A,vector<int> &ds,int n,int k,int sum){ 
    if(ind==n){
        if(k==sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    //pick condition
    ds.push_back(A[ind]);
    sum+=A[ind];
    sumk(ind+1,A,ds,n,k,sum);
    sum-=A[ind];
    ds.pop_back();

    //non pick condition
    sumk(ind+1,A,ds,n,k,sum);

}


int main(){
    
    vector<int> A = {1,2,3,3,5};
    vector<int> ds;

    sumk(0,A,ds,A.size(),6,0);
    return 0;
}