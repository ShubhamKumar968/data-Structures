#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
 /*Whenever a problem asks for count exactly K distinct elements in a subarray (or substring), 
use the “atMost” trick:
exactly K= atMost(K)−atMost(K−1)
reusable pattern for many sliding window problems.  
*/
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if (k == 0) return 0;
        int cnt=0;
        
        unordered_map<int ,int>mp;
        int i=0,j=0;
        while(j<n){
            
            mp[arr[j]]++;
            
            while(mp.size()>k){
                
                mp[arr[i]]--;
                
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                i++;
            }
            
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    
    int exactlyK(vector<int> &arr, int k) {
        // code here
        
        return countAtMostK(arr,k)- countAtMostK(arr,k-1);
    }
};

//(2) for string 

class Solution {
  public:
    int atMost(string&s, int k) {
        // code here
        if (k < 0) return 0;
        vector<int> freq(256, 0);
        int distinct = 0;
        int n=s.size();
        int i=0,j=0;
        int cnt=0;
            
        while (j < n) {
            // If it's a new distinct character
            if (freq[s[j]] == 0) {
                distinct++;
            }
            
            freq[s[j]]++;

            // Shrink window if distinct characters exceed k
            while (distinct > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) {
                    distinct--;
                }
                i++;
            }
            // Number of subarrays ending at j is the window size
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
    
    int countSubstr(string& s, int k) {
        // code here
        int ans=atMost(s,k)-atMost(s,k-1);
        return ans;
    }
};
