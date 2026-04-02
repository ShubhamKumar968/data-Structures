#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  //Best & Avg case => Always pivot found in middle { T(n)= T(n/2) + T(n/2) + n}=>O(n*logn)
  //Worst case => Always pivot found in start { T(n)= T(n-1) + n} => O(n*n)
  public:
  
    //{pivot selection + Partionining + Recursion }
    void quickSort(vector<int>& arr, int low, int high) {
        // Base Case: If the subarray has 0 or 1 element, it's already sorted
        if(low >= high){
            return;
        }
        // Step 1: Partition the array and get pivot's correct index
        int pivotIdx = partition(arr,low,high);
        // Step 2: Recursively sort elements before pivot
        quickSort(arr,low,pivotIdx-1);
        // Step 3: Recursively sort elements after pivot
        quickSort(arr,pivotIdx+1,high);
        
        
    }

    int partition(vector<int>& arr, int low, int high) {
        
        // Step 1: Choose last element as pivot
        int pivot=arr[high];
        // Step 2: Initialize pointer for smaller elements
       // pivotIdx will track position where next smaller element should go
        int pivotIdx= low;
        // Step 3: Traverse array from low to high-1
        for(int i=low; i< high ; i++){
            
            if(arr[i] <= pivot){
                // Place it in correct position (left side)
                swap(arr[i], arr[pivotIdx]);
                // Move pivotIdx forward
                pivotIdx++;
            }
        }
        // Step 4: Place pivot in its correct sorted position
        swap(arr[high], arr[pivotIdx]);
        // Step 5: Return pivot index
        return pivotIdx;
        
    }
};
//Pivot = element around which the array is rearranged
//After partition:

//Left side → elements ≤ pivot
//Right side → elements > pivot
//Pivot → goes to its correct sorted position

