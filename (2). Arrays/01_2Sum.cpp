#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:

  //Method-01

int countDistinctPairs(vector<int> &arr, int target) {
        
        unordered_set<int> seen;
        unordered_set<int> used;
    
        int cnt = 0;
    
        for (int x : arr) {
    
            int y = target - x;
    
            if (seen.count(y) && !used.count(x) && !used.count(y)) {
    
                cnt++;
    
                used.insert(x);
                used.insert(y);
            }
    
            seen.insert(x);
        }
    
        return cnt;
    }

//Method-2:

    int countDistinctPairs(vector<int> &arr, int target) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sort to apply 2 pointer
        
        int i = 0, j = n - 1;
        int cnt = 0;
        
        while (i < j) {
            int current_sum = arr[i] + arr[j];
            
            if (current_sum == target) {
                cnt++; // Found a distinct pair!
                
                // Track current values to skip all identical duplicates
                int left_val = arr[i];
                int right_val = arr[j];
                
                // Skip duplicate elements from left
                while (i < j && arr[i] == left_val) {
                    i++;
                }
                // Skip duplicate elements from right
                while (i < j && arr[j] == right_val) {
                    j--;
                }
            } 
            else if (current_sum < target) {
                i++; // Sum is too small, move left pointer rightward
            } 
            else {
                j--; // Sum is too big, move right pointer leftward
            }
        }
        
        return cnt;
    }
};

//Without duplicates

bool twoSum(vector<int>& arr, int target) {
        
       unordered_map<int,int>mp;
       
       for(int i=0;i<arr.size();i++){
           
           if(mp.count(target-arr[i])){
               return true;
           }
           
           mp[arr[i]]++;
       }
       return false;
        
}
