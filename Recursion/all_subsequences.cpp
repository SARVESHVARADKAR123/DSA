#include <iostream>
#include<vector>
using namespace std;

void printSubsequences(int ind,vector<int> &A,vector<int> &ds,  int n){ 
    if (ind == n) {
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }


    //non pick condition
    printSubsequences(ind+1,A,ds,n);
    //pick condition
    ds.push_back(A[ind]);
    printSubsequences(ind+1,A,ds,n);
    ds.pop_back();

}


int main(){
    
    vector<int> A = {1,2,3};
    vector<int> ds;

    printSubsequences(0,A,ds,A.size());
    return 0;
}