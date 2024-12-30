#include<climits>
class Solution {
public:
    int sol(vector<int>& prices,int n,int ind,int minprice){
        if(ind==n){
            return 0;
        }

        minprice=min(prices[ind],minprice);

        int profittoday=prices[ind]-minprice;

        int profitfuture=sol(prices,n,ind+1,minprice);

        return max(profittoday,profitfuture);
    }

    int soltab(vector<int>& prices,int n){
        
        int minprice=INT_MAX;
        int maxprofit=0;


       ;
        for(int i=0;i<n;i++){
            minprice=min(prices[i],minprice);
            maxprofit=max(maxprofit,prices[i]-minprice);

        }
        return maxprofit;

    }
    int maxProfit(vector<int>& prices) {
        return soltab(prices,prices.size());
    }
};