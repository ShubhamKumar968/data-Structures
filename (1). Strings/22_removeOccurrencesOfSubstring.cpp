#include<iostream>
using namespace std;
#include<bits/stdc++.h>



//Method-1 Using KMP (optimal)

class Solution {
public:
    void findLps(string& s,vector<int>&lps,int n){
        
        int pre=0;
        int suf=1;
        
        while(suf<n){
            // Case 1: Match found, store length and move both pointers forward
            if(s[pre]==s[suf]){
                
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            // Case 2: Mismatch occurs
            else{
                
                if(pre==0){
                    lps[suf]=0; // No valid prefix match possible for s[suf]
                    suf++;
                }else{
                    pre=lps[pre-1];// Fallback to the previous best prefix match segment
                }
            }
        }
        return;
    }
    string removeOccurrences(string s, string part) {
        
        int n = s.length(), m = part.length();
        
        vector<int> lps(m, 0);
        findLps(part, lps, m);
        
        string res = "";   // Character stack
        vector<int> v;     // Tracks 'j' pointer state for each character in res
        int j = 0;         // Match position inside 'part'
        
        for (char c : s) {
            res.push_back(c);
            
            // Fallback matching using the LPS table
            while (j > 0 && c != part[j]) {
                j = lps[j - 1];
            }
            
            if (c == part[j]) {
                j++;
            }
            
            v.push_back(j);
            
            // Substring match found! Pop 'part' from the stacks
            if (j == m) {
                int len = res.length();
                res.resize(len - m);
                v.resize(len - m);
                
                // Restore match state to the historical snapshot prior to removal
                j = v.empty() ? 0 : v.back();
            }
        }
        
        return res;
    }
};

//Method-2

string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
       return s;
}