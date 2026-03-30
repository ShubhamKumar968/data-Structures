#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1) Print number 1 to n
class Solution {
  public:
    void printNos(int n) {
        // Code here
        if(n<=0) return;
        
        printNos(n-1);
        cout<<n<<" ";
    }
};

//(2)Print Pattern in forward and then in backward
class Solution {
  public:
  
    void solve(int n,vector<int>&ans){
        
        if(n<=0){
            ans.push_back(n);
            return;
        }
        
        ans.push_back(n);
        solve(n-5,ans);
        ans.push_back(n);
        
    }
    vector<int> pattern(int n) {
        // code here
        vector<int>ans;
        solve(n,ans);
        return ans;
    }
};

//(3)sum of dgit of given number
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

//(4)Reverse a string
class Solution {
  public:
    void solve(string& s, string& res, int i){
        //Base Case
        if(i>=s.length()){
            return;
        }
        solve(s,res,i+1);
        res+=s[i];
        
    }
    
    string revStr(string s) {
        // code here
        string res="";
        solve(s,res,0);
        return res;
    }
};

//(5)Factorial of a number
class Solution {
  public:
    int factorial(int n) {
        // code here
        if(n<=1) return n;
        
        int res=n*factorial(n-1);
        return res;
    }
};

//(6)Power of 2

int powerOf2(int n){
    if(n==0) return 1;
    if(n==1) return 2;

    return 2*powerOf2(n-1);

}

//(7) power of number and its reverse
class Solution {
  public:
    
    int exponent(int a, int b){
        
        if(b==0) return 1;
        if(b==1) return a;
        
        int res= exponent(a,b/2);
        
        if(b%2==0) return (res*res);
        else return (a*res*res);
    }
    
    int reverse(int n){
        
        int rev=0;
        while(n>0){
            rev = rev * 10 + n % 10;
            n/=10;
        }
        return rev;
    }
    
    int reverseExponentiation(int n) {
        // code here
        int rev=reverse(n);
        
        return exponent(n,rev);
    }
};

//(8) Reverse an array

class Solution {
  public:
    void reverse1(vector<int> &arr, int idx,int n){
        
        if(idx>= n/2) return;
        swap(arr[idx], arr[n-1-idx]);
        
        return reverse1(arr,idx+1, n);
    }
    //using 2 pointer
    void reverse2(vector<int> &arr, int st,int end){
        
        if(st>= end) return;
        swap(arr[st], arr[end]);
        
        return reverse2(arr,st+1, end-1);
    }
    
    void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        //return reverse1(arr,0, n);
        return reverse2(arr,0,n-1);
    }
};

//(9) Check Palimdrome 

class Solution {
  public:
  
    int reverse(int n){
        
        int rev=0;
        while(n>0){
            rev=rev*10  + n%10;
            n/=10;
        }
        return rev;
    }
    bool solve2(string s, int st, int end){
        
        if(st>=end) return true;
        
        if(s[st] != s[end]) return false;
        
        return solve2(s, st+1, end-1);
    }
    
    bool isPalindrome(int n) {
        // code here.
       
//Method-01 (Using reverse)
       
       int rev= reverse(n);
       return (n==rev) ? true : false;
       
//Method-02 (Using Recursion)
       string s=to_string(n);
       return solve2(s,0,s.length()-1);
    }
};

//(10) Sum of array elements
class Solution {
  public:
    int solve(vector<int>& arr, int idx,int n){
        
        if(idx>= n) return 0;
        return arr[idx] + solve(arr,idx+1,n);
    }
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        return solve( arr, 0, arr.size() );
    }
};

//(11). Sum of first N natural numbers

int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}

//(12) Check if array is Sorted 
class Solution {
  public:
  
    bool solve(vector<int>& arr,int idx, int n){
        
        if (idx == n - 1) return true;  // reached end, sorted

        if (arr[idx] > arr[idx + 1]) return false; // check current pair

        return solve(arr, idx + 1, n); 
    }
    
    bool isSorted(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==0 || n==1) return true;
        
        
        return solve(arr,0,n);
    }
};

//(13) sort an array
class Solution {
  public:
    void insert(vector<int> &arr, int ele){
        
        if( arr.empty() || arr.back() <= ele){
            arr.push_back(ele);
            return;
        }
        
        int val=arr.back();
        arr.pop_back();
        
        insert(arr,ele);
        arr.push_back(val);
        
        return;
    }
    
    void sortArr(vector<int> &arr) {
       
       if(arr.size()==0){
           return;
       }
       
       int ele=arr.back();
       arr.pop_back();
       
       sortArr(arr);
       insert(arr,ele);
       
       return;
    }
};

//(14). Linear search in an array
class Solution {
  public:
    int solve(vector<int>& arr, int x, int idx, int n){
        
        if(idx>=n){
            return -1;
        }
        
        if(arr[idx]==x) return idx;
        
        solve(arr,x,idx+1,n);
    }
    
    int search(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        return solve(arr,x, 0,n);
    }
};

//(15) Binary search in sorted array.

class Solution {
  public:
    int solve(vector<int> &arr, int k,int st,int end){
        
        if(st>end){
            return -1;
        }
        
        int mid=st+ (end-st)/2;
      
        if(arr[mid]==k){
            
            int left = solve(arr, k, st, mid - 1);// move left for first occurrence
            if(left != -1) return left;   // smaller index found
            return mid;                   // current is smallest
        }
        else if(arr[mid]>k){
            return solve(arr,k,st,mid-1);
        }
        else{
            return solve(arr,k,mid+1,end);
        }
        
    }
    int binarysearch(vector<int> &arr, int k) {
        // code here
        return solve(arr,k,0, arr.size()-1);
    }
};