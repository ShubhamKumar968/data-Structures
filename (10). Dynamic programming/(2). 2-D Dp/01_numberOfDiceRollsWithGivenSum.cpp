#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//Method-01: Recursion+ Memoization

    //Recursion-> O(n^k)
    const int mod=1e9+7;
    int t[31][1001];

    int solve(int n, int k, int target){
        
        //when n == 0, you should return 1 only if target == 0.
        if(n==0){
            return target==0;
        }
        //if target == 0 but there are still dice remaining, you cannot count that as a valid way.
        if(target<=0){
            return 0;
        }

        if(t[n][target]!=-1){
            return t[n][target];
        }

        int ans=0;
        for(int i=1;i<=k;i++){
            ans = (ans + solve(n-1,k,target-i)) % mod;
        }

        return t[n][target]=ans%mod;
    }

    int numRollsToTarget(int n, int k, int target) {

        memset(t,-1,sizeof(t));
        return solve(n,k,target);

    }
};


//Method-02: Bottom Up

    int bottomUp(int n, int k, int target){

        //dp[i][j]->number of ways to obtain sum==j if we have i dices.
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        dp[0][0]=1;//if sum==0 and dice==0 then 1 ways is possible;

        //initialization

        //(1). if we have 0 dices then sum can't be more than 0 dp[0][j]=0;
       
        //(2). if we have more than 1 dices then sum can't be 0 dp[i][0]=0;;
       
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int ways = 0; // FIXED: Resets to 0 for every unique subproblem cell!
                for(int face=1;face<=k;face++){
                    if(j-face>=0) ways=(ways+dp[i-1][j-face])%MOD;
                }
                dp[i][j]=ways;
            }
        }
        return (dp[n][target])%MOD;
    }

    int numRollsToTarget(int n, int k, int target) {

        memset(t,-1,sizeof(t));
        //return solve(n,k,target);
        return bottomUp(n,k,target);
    }
};
