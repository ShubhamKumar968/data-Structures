#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void merge(vector<int> &A, vector<int> &B) {
    
    int m=A.size();// Initial valid elements in A
    int n=B.size();// Initial valid elements in B
    A.resize(m + n);// Resize A to hold both arrays combined
    
    int i=m-1;
    int j=n-1;
    int k=(m+n-1);// Pointer for the absolute end of resized A
    
    while(i>=0 && j>=0 ){// Merge from the back to avoid shifting elements
        
        if(A[i]>B[j]){
            A[k]=A[i];
            i--;
        }else{
            A[k]=B[j];
            j--;
        }
        
        k--;
    }
    
    // If elements remain in B, copy them over
    while(j>=0){
        A[k]=B[j];
        j--;
        k--;
    }
    
    return;
}
