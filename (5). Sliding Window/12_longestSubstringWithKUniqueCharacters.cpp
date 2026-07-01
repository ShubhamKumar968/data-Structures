#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
    
//Method-01 Brute force
    
        int n=s.length();
        int maxi=-1;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                
                st.insert(s[j]);
                if(st.size()==k){
                    maxi=max(maxi,j-i+1);
                }
                
            }
        }
        return maxi;       
    }

//method-02 Optimal Using sliding window 

       int longestKSubstr(string &s, int k) {
        
        int n = s.length();
        int i = 0, j = 0;
        int maxLen = -1;
        
        // Hash map tracks the frequency of characters inside the active window
        unordered_map<char, int> mp;
        
        while (j < n) {
            
            // 1. Expand phase: Add the incoming character to the window
            mp[s[j]]++;
            
            // 2. Shrink phase: If unique character count exceeds k, slide left boundary
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]); // Physically remove the key to correctly reduce mp.size()
                }
                i++;
            }
            
            // 3. Evaluate phase: Only update max length when window has exactly k distinct chars
            if (mp.size() == k) {
                maxLen = max(maxLen, j - i + 1);
            }
            
            j++; // Keep moving the right pointer
        }
        
        return maxLen; 
    }
};
