#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n=arr.size();
        int l=0,h=n-1;
        int mid=-1;
        
        while(l<=h){
            
            mid=l+(h-l)/2;
            int missing_till_mid = arr[mid]- (mid+1);//Number of missing element till mid
            
            if(missing_till_mid < k ){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        
        return l+k;
        
    }
};