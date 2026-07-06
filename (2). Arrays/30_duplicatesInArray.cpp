#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) Find duplicates number in array

//Method-01: Brute force

int findDuplicate(vector<int>& arr) {
        int n=arr.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    return arr[i];
                }
            }
        }

        return -1;
}

//Method-02 Using Hash array or map:

 int findDuplicate(vector<int>& arr) {

        int n=arr.size();
        vector<int>hash(n+1,0);

        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(hash[i]>1) return i;
        }
        
        return -1;
}

//Method-03: By Modifying array


int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]);
            
            // If already negative, this index was visited before
            if (nums[idx] < 0) {
                duplicate = idx;
                break;
            }
            
            // Mark as visited by flipping the sign
            nums[idx] = -nums[idx];
        }
        
        // Restore the array to its original positive state
        for (int &x : nums) {
            x = abs(x);
        }
        
        return duplicate;
}

//Method-04: Optimal Using slow and fast pointer

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Initialize slow (1 step) and fast (2 steps)
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        // Phase 1: Keep moving until slow and fast pointers meet
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // Phase 2: Reset slow to the start to find the cycle entry point
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

//(2) Find All duplicates number in array

//Method-01 : Using map or sorting
vector<int> findDuplicates(vector<int>& arr) {

        vector<int>res;
        int n=arr.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        for(auto &it:mp){
            if(it.second>1){
                res.push_back(it.first);
            }
        }
        
        return res;
}

//Method-02: Using Number as index because nums belong to [1,n] optimal

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {

        vector<int>res;
        int n=arr.size();
       

        for(int i=0;i<n;i++){
            
            int num=abs(arr[i]);
            int idx=num-1;

            if(arr[idx]<0){
                res.push_back(num);
            }else{
                arr[idx] *= -1;
            }
        }
        
        return res;
    }
};

