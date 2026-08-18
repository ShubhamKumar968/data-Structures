#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  //Best & Avg case => Always pivot found in middle { T(n)= T(n/2) + T(n/2) + n}=>O(n*logn)
  //Worst case => Always pivot found in start { T(n)= T(n-1) + n} => O(n*n)
  public:
  
    //{pivot selection + Partionining + Recursion }
     void quickSort(vector<int>& arr, int low, int high) {
        // Base case: subarray of size 0 or 1 is already sorted
        if (low >= high) {
            return;
        }

        // Place pivot in its correct sorted position
        int pivotIdx = partition(arr, low, high);

        // Recursively sort elements before and after pivot
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }

    int partition(vector<int>& arr, int low, int high) {
        
        // 1. Pick last element as pivot
        int pivot = arr[high];
        
        // 2. 'pivotIdx' tracks where the next element <= pivot should go
        int pivotIdx = low;

        // 3. Move all elements <= pivot to the left side
        for (int i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                swap(arr[i], arr[pivotIdx]);
                pivotIdx++;
            }
        }

        // 4. Place pivot right after the smaller elements
        swap(arr[high], arr[pivotIdx]);

        return pivotIdx; // Final index of the pivot
    }
};
//Pivot = element around which the array is rearranged
//After partition:

//Left side → elements ≤ pivot
//Right side → elements > pivot
//Pivot → goes to its correct sorted position

