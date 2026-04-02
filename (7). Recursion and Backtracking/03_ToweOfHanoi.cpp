#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//TC= O(2^n) ; Number of Moves= (2^n - 1);

class Solution {
  public:
    
    int solve(int n, int from, int to, int aux){
        
        //Step-0: Base Case;
        if(n==0) return 0;
        if(n==1){
            
            cout<< " move disk " << n << " from rod "<< from << " to rod " << to << endl;
            return 1;
        } 
        
        int stepCount=0;
        
        //Step-1: Move (n-1) disk from From_rod  to Auxilary_rod via To_rod
        stepCount+=solve(n-1, from, aux, to);
        //Step-2:Move nth disk from From_rod to To_rod
        cout<< " move disk " << n << " from rod "<< from << " to rod " << to << endl;
        stepCount++;
        //Step-3:Move (n-1) disk from Auxilary_rod to To_rod via From_rod
        stepCount+=solve(n-1, aux, to, from);
        
        return stepCount;
    }
    
    //from=1; aux=2; To=3;
    
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        
        //return solve( n, from, to, aux);
        return (1 << n) - 1;  // 2^n - 1
    }
};