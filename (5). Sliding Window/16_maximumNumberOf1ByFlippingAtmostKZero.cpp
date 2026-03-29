#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
  
    int maxOnes(vector<int>& arr, int k) {
        // code here
        
//Method-1:  Brute Force
      int n=arr.size();
        int res=0;
        for(int i=0;i<n;i++){
            
            int temp=k;
            int cnt=0;
            
            for(int j=i;j<n;j++){
                
                if (arr[j] == 0) {
                    if (temp > 0) {
                        temp--;   // use a flip
                        cnt++;
                    } else {
                         break;    // can't flip anymore, stop this sequence
                    }
                } else {
                    cnt++;      
                }
            }
            
            res=max(res,cnt);
        }
        return res;        
        
        
//Method-2: Optimal
        int n=arr.size();
        int zero=0,cnt=0;
        int i=0,j=0;
        
        while(j<n){
            
            if(arr[j]==0){
                zero++;
            }
            
            while(i<=j && zero>k){
                if(arr[i]==0){
                    zero--;
                }
                i++;
            }
            
            cnt=max(cnt,j-i+1);
            
           j++;
        }
        
        return cnt;
    }
};
 