#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Using Sorting (Brute force)

 bool areAnagrams(string& s1, string& s2) {
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        return s1==s2;
        
}

//Method-02: Using hash array

bool areAnagrams(string& s1, string& s2) {
        
        vector<int>hash(26,0);
        for(auto &ch:s1){
            hash[ch-'a']++;
        }
        
        for(auto &ch:s2){
            hash[ch-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(hash[i]!=0){
                return false;
            }
        }
        return true;
 }
