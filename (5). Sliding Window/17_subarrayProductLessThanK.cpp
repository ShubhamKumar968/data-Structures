#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    typedef long long ll;
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n,long long k) {
                                            
//Method-01: Brute force
        int cnt=0;
        for(int i=0;i<n;i++){
            ll prod=1;
            for(int j=i;j<n;j++){
                prod*=arr[j];
                
                if(prod<k){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        return cnt; 
        
//Method-02: Optimal 
        ll cnt=0;
        ll prod=1;
        if(k<=1) return 0;
        int i=0,j=0;
        while(j<n){
            prod*=arr[j];
            
            // shrink when invalid
            while(i<=j && prod >= k){
                prod /= arr[i];
                i++;
            }
            // count all valid subarrays ending at j
            cnt += (j - i + 1);
            
            j++;
        }
        return cnt;
    }
};

/*//Alternative approach using logarithm {log(a*b)=log(a)+log(b)}

        int cnt = 0;
        int i = 0;
        double prod_log = 0;
        for (int j = 0; j < n; j++) {
            prod_log += log(arr[j]);
            
            while (i <= j && prod_log >= log(k)) {
                prod_log -= log(arr[i]);
                i++;
            }
            cnt += (j - i + 1);

        }
        return cnt;
        
*/       
        
