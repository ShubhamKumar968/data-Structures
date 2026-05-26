#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    //one transaction means 1 buy + 1 Sell
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int minBuys=prices[0];
        int maxProfit=0;
        for(int i=1;i<n;i++){
            maxProfit=max(maxProfit, prices[i]-minBuys);
            minBuys=min(minBuys,prices[i]);
        }
        
        return maxProfit;
    }
};
