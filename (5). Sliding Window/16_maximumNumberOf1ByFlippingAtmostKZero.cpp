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
    }
};
        
//Method-2: Optimal

 class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;
        
        int cnt = 0, zero = 0;
        
        while (j < n) {
            // FIX: Check the incoming element at the right pointer 'j'
            if (arr[j] == 0) {
                zero++;
            }
            
            // Shrink the window from the left if we have flipped more than 'k' zeros
            while (zero > k) {
                if (arr[i] == 0) {
                    zero--;
                }
                i++;
            }
            
            // The window from i to j is now guaranteed to have at most 'k' zeros
            cnt = max(cnt, j - i + 1);
            j++;
        }
        
        return cnt;
    }
};
