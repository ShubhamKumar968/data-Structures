#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//(1). Perfect Squares:-
class Solution {
public:
    
    int solve(int n,vector<int>&dp){
           
        if(n==0) return 0;//if we reach at end then step=0
        
        if(dp[n] != -1) return dp[n];

        int minCount=INT_MAX;

        for(int i=1;i*i<=n;i++){//We will try to count all possible perfect square less than the given number

            int result= 1+ solve(n-i*i, dp);

            minCount=min(minCount,result);
        }
        return dp[n]= minCount;
    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }

};

//(2).Ugly Numbers:- {it can be only solved using bottom up}

/*
    We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then

    k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:

    k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);
        //t[i] = ith Ugly number;
        //we will reutrn t[n] = nth ugly number
        
        t[1] = 1; //1st Ugly number
        
        int i2; //i2th Ugly number
        int i3; //i3rd Ugly number
        int i5; //i5th Ugly number
        
        //initially i2th, i3rd and i5th Ugly number point to 1 i.e. first ugly number
        i2 = i3 = i5 = 1;
        
        for(int i = 2; i<=n; i++) {
            int i2th_ugly = t[i2] * 2;
            
            int i3rd_ugly = t[i3] * 3;
            
            int i5th_ugly = t[i5] * 5;
            
            t[i] = min({i2th_ugly, i3rd_ugly, i5th_ugly});
            
            if(t[i] == i2th_ugly)
                i2++;
            
            if(t[i] == i3rd_ugly)
                i3++;
            
            if(t[i] == i5th_ugly)
                i5++;
        }
        
        return t[n];
    }
};