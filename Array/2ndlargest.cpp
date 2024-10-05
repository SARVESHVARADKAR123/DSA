vector<int> solve(int n,vector<int>&a){
    if(n<2)
      return {-1,-1};
    int largest=a[0];
    int smallest=a[0];
    int sLargest=INT_MIN;
    int sSmallest=INT_MAX;

    for(int i=1;i<n;i++){
        if(a[i]>largest){
            sLargest=largest;
            largest=a[i];
        }
        else if(a[i]>sLargest && a[i] != largest){
            sLargest=a[i];
        }

        if(a[i]<smallest){
            sSmallest=smallest;
            smallest=a[i];
        }
        else if( a[i]<sSmallest && a[i]!=smallest){
            sSmallest=a[i];
        }
    }
    return {sLargest,sSmallest};
}



vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    return solve(n,a);
}
