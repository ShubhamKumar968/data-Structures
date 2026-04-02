#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1) count all factors(divisors) of a given number

    //Method-1: Brute force
int countFactors(int n) {
    int count = 0;
    
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            count++;
        }
    }
    
    return count;
}

    //Method-2 Optimal

//Factors come in pairs:  If i divides n, then n/i also divides n

int countFactors(int n) {//O(sqrt(N))

    int count = 0;
    
    for(int i = 1; i * i <= n; i++) {

        if(n % i == 0) {

            if(i == n / i) count += 1;   // perfect square
            else count += 2;   // pair of factors
        }

    }
    
    return count;
}

//(2) Finding GCD (HCF) of 2 numbers

    //Method-1 (Brute force)
int gcd(int a, int b) {
    int ans = 1;
    
    for(int i = 1; i <= min(a, b); i++) {
        if(a % i == 0 && b % i == 0) {
            ans = i;
        }
    }
    
    return ans;
}

    //Method-2 (Using Euclid algorithm)

int gcd(int a, int b) {//O(logN)
    if(b == 0) return a;
    return gcd(b, a % b);
}


//(3) finding LCM of 2 numbers
   
    //LCM(a, b) = (a * b) / GCD(a, b)

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // safe to avoid overflow
}

//(4) check if number is prime or not.

   //Method-01 (Brute force)

bool isPrime(int n){

    if(n<=1) return false;
    for(int i=2;i<=n-1;i++){ //(1 and n to n ka factor hoga hi, uske alave koi divide kare to non-prime hoga)
        if(n%i==0) return false;
    }
    return true;
}

    //Method-02  (Optimal)

bool isPrime(int n){

    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

//(5)find all prime numbers upto n (Sieve of Eratosthenes)
class Solution {
  public:
    vector<int> sieve(int n) {//TC= O(N*loglogN)
        
        // Step 1: Create a boolean array and mark all numbers as prime initially
        vector<bool>isPrime(n+1,true);
        
         // Step 2: 0 and 1 are not prime numbers
        isPrime[0]=false;
        isPrime[1]=false;
        
        // Step 3: Traverse from 2 to √n
        for(int i=2;i*i<=n;i++){
            // Step 4: If current number is prime
            if(isPrime[i]==true){
                
                // Step 5: Mark all multiples of i as non-prime
                for(int j=2; i*j<=n ; j++){
                    isPrime[i*j]=false;
                }
            }
        }
        
         // Step 6: Store all prime numbers in result vector
        vector<int>res;
        for(int i=2;i<=n;i++){
            if(isPrime[i]==true){
                res.push_back(i);
            }
        }
        return res;
    }
};

