#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//TC= O(2^n) ; Number of Moves= (2^n - 1);

class Solution {
private:
    void solve(int n, int from, int to, int aux, int &moves) {
        // Base case: no disks left to move
        if (n == 0) {
            return;
        }

        // 1. Move top (n - 1) disks from 'from' to 'aux' using 'to' as helper
        solve(n - 1, from, aux, to, moves);

        // 2. Move the nth disk from 'from' to 'to' and record the move
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        moves++;

        // 3. Move (n - 1) disks from 'aux' to 'to' using 'from' as helper
        solve(n - 1, aux, to, from, moves);
    }

public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        int moves = 0;
        solve(n, from, to, aux, moves);
        return moves;
    }
};
    //from=1; aux=2; To=3;
    
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        
        //return solve( n, from, to, aux);
        return (1 << n) - 1;  // 2^n - 1
    }
