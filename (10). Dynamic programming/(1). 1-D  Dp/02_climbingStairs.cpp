#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Recursion-> O(2^n); Memo/bottomUp ->O(n)
class Solution {
  //TopDown:- hum bade value se chhote value ki taraf jate hai, solution find karne ke liye
  //BottomUp:- hum chhote value se bade value ke taraf jaate hai;
  public:
    //Method-01: Recursion + TopDown(approach-1) {uppar chadhkar}
    
    int t[41];//only one variable is changing (1-D dp)
    int solve(int n, int idx){
        
        if(idx==n){
            return 1;
        }
        if(idx>n) {
            return 0;
        }
        
        if(t[idx] !=-1){
            return t[idx];
        }
        
        
        int oneStep=solve(n,idx+1);
        int twoStep=solve(n,idx+2);
        
        return t[idx]=(oneStep+twoStep);
    }
    
    //Method-01: Recursion + TopDown(approach-2) {niche utarkar}
    int memo[41];
    int solveMemo(int n){
        
        if(n==0){
            return 1;
        }
        if(n < 0) {
            return 0;
        }
        
        if(t[n] !=-1){
            return t[n];
        }
        
        
        int oneStep=solveMemo(n-1);
        int twoStep=solveMemo(n-2);
        
        return t[n]=(oneStep+twoStep);
    }
    
    //Method-02: Bottom up

    int bottomUp(int n) {
        //dp[i] = number of ways to REACH step i
        vector<int> dp(n + 1);
    
        dp[0] = 1;  // important {Ways to reach stair 0 = 1 (do nothing);empty way}
        if(n >= 1) dp[1] = 1; // ways to reach first stair = 1(1-step)
    
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    
        return dp[n];
    }
    
    //Method-03: space optimization

    int spaceOptimize(int n) {
        
        if(n <= 1) return 1;
        // dp[i] keval previous ke 2 hi value par depend kar raha hai;
        int prev2 = 1, prev1 = 1;
        int curr;
        for(int i = 2; i <= n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
    
        return curr;
    }
    
    int countWays(int n) {
        // your code here
        memset(t,-1,sizeof(t));
        memset(memo,-1,sizeof(memo));
        //return solve(n,0);
        //return buttomUp(n);
        //return solveMemo(n);
        return spaceOptimize(n);
    }
};