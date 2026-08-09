#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) find second largest element

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int largest=arr[0];
        int secondLargest=-1;
        
        for(auto &x: arr){
            
            if(x >largest){
                secondLargest=largest;
                largest=x;
            }else if(x>secondLargest && x < largest){
                secondLargest=x;
            }
        }
        
        return secondLargest;
    }
};

//(2) check if array is sorted and rotated

class Solution {
public:
    bool check(vector<int>& nums) {

        int cnt=0;
        int n=nums.size();
        if(nums[n-1]>nums[0]) cnt++;

        for(int i=0;i+1<n;i++){
            if(nums[i]>nums[i+1]) cnt++;
        }
        return cnt<=1;
    }
};

//(3) rotate array in right (clockwise) by 1 place

//method-01: Brute force

class Solution {
  public:
    void rotate(vector<int> &arr) {
        
        int k=1;
        int n = arr.size();
        if (n <= 1) return;
        
        k = k % n; // Handle cases where k >= n
        vector<int> temp(n);
        
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = arr[i];
        }
        
        arr = temp;
    }
};

//Method-02: optimal

 void rotate(vector<int> &arr) {
        
        int k=1;
        int n = arr.size();
        if (n <= 1) return;
        
        k = k % n; // Handle k >= n
        if (k == 0) return;
        
        // Step 1: Reverse all elements
        reverse(arr.begin(), arr.end());
        
        // Step 2: Reverse first k elements
        reverse(arr.begin(), arr.begin() + k);
        
        // Step 3: Reverse the remaining n - k elements
        reverse(arr.begin() + k, arr.end());
}

//Method-03: Logical

class Solution {
  public:
    void rotate(vector<int> &arr) {
        
        int n = arr.size();
        if (n <= 1) return; // Edge case: empty or 1-element array
        
        int last = arr[n - 1]; // Save the last element
        
        // Shift elements one position to the right
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        
        arr[0] = last; // Place last element at index 0
    }
};

//(4) left rotate array by k place

//Method-01: Modulus

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if (n <= 1) return;
        
        d = d % n; // Handle cases where d >= n
        if (d == 0) return;
        
        vector<int> temp(n);
        
        // Element that belongs at index i comes from (i + d) % n
        for (int i = 0; i < n; i++) {
            temp[i] = arr[(i + d) % n];
        }
        
        arr = temp;
    }
};

//Method-02 : Optimal

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if (n <= 1) return;
        
        d = d % n; // Handle d >= n
        if (d == 0) return;
        
        // Step 1: Reverse first d elements
        reverse(arr.begin(), arr.begin() + d);
        
        // Step 2: Reverse remaining n - d elements
        reverse(arr.begin() + d, arr.end());
        
        // Step 3: Reverse the whole array
        reverse(arr.begin(), arr.end());
    }
};
