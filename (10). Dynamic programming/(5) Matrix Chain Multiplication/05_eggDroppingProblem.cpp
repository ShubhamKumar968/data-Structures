#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int t[1001][1001];
    // Function to find minimum number of attempts needed in order to find the critical floor
    int solve(int e, int f){
        
        if(e==1){//agar ek(1) egg hai to use bottom se up tak ke saare floor par le jakar dekhenge ki kha break hoga
            return f;
        }
        
        if(f==0 || f==1){
            return f;
        }
        
        if(t[f][e]!=-1) return t[f][e];
        
        int mini=INT_MAX;
        
        
    //Method-01: Using MCM O(e*f*f)->TLE
       
        for(int k=1;k<=f;k++){
    //If you throw an egg from floor k and it breaks, you now have e-1 eggs left, and you only need to check the floors below k
            int broke=solve(e-1,k-1);
    // if egg is not broken from floor k then we have to check remaining (f-k) floor above kth floor with same amount of eggs       
            int unbroke=solve(e,f-k);
            int temp= 1+ max(broke,unbroke);//Worst case attempt
            
            mini=min(mini,temp);//minimum attempt
        }
        
    
    //Method-02: Binary Search optimization replacing the linear O(f) loop -> O(e*f*logf)
        int low = 1, high = f;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // FIX 1: Pass 'mid - 1' instead of 'f - 1'
            int broke = solve(e - 1, mid - 1); 
            int unbroke = solve(e, f - mid);
            
            int temp = 1 + max(broke, unbroke);
            mini = min(mini, temp);
            
            // Adjust search window based on which branch dominates the worst case
            if (broke > unbroke) {
                // The 'broken' side is too high, meaning the critical floor is likely lower down
                high = mid - 1;
            } else {
                // The 'unbroken' side is too high or they are equal, search higher up
                low = mid + 1;
            }
        }
        
        return t[f][e]=mini;
    }
    int eggDrop(int n, int k) {
        // code here
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
};