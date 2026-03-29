#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Q.(1) Count Occurrences of anagram
class Solution {
  public:
    int search(string &pat, string &txt) {
        
//Method-1 Bruteforce

        int n=txt.length(), m=pat.length();
        // frequency map of pattern
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++) {
            mp[pat[i]]++;
        }
        
        int cnt = 0;
        
        for (int i = 0; i <= n - m; i++) {
        
            // frequency map of current window
            unordered_map<char, int> window;
            for (int j = i; j < i + m; j++) {
                window[txt[j]]++;
            }
        
            // compare window freq with pattern freq
            if (window == mp) cnt++;
        }
        return cnt; 
        
//Method-02: Optimal (Using Sliding Window)

        int n=txt.length(), m=pat.length();
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            mp[pat[i]]++;
        }
        
        int i=0,j=0;
        int cnt=0, length=mp.size();
        while(j<n){
            
            if(mp.count(txt[j])){
                mp[txt[j]]--;
                if(mp[txt[j]]==0) length--;
            }
            
            if(j-i+1==m){
                
                if(length==0) cnt++;//anagram found
                
                if(mp.count(txt[i])){
                    if(mp[txt[i]] == 0) length++;
                    mp[txt[i]]++;
                }
                
                i++;
            }
            
            j++;
        }
        return cnt;
    }
};

//Q.(2) find all anagrams of given string
    vector<int> findAnagrams(string txt, string pat) {
        int n=txt.size();
        int k=pat.size();
        unordered_map<char,int>mp;
        for(auto ch:pat) mp[ch]++;
        vector<int>ans;
        int i=0,j=0,cnt=mp.size();
        while(j<n){
            if (mp.find(txt[j]) != mp.end()) {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0) cnt--;
            }
            if(j-i+1==k){
                
                if(cnt==0) ans.push_back(i);//anagram found
                
                if(mp.count(txt[i])){
                    if(mp[txt[i]] == 0) cnt++;
                    mp[txt[i]]++;
                }
                
                i++;
            }
            
            j++;
        }
        return ans;
    }

//Q.(3) check both are anagrams of each other
 bool areAnagrams(string& txt, string& pat) {
        // code here
        int n=txt.length(), m=pat.length();
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            mp[pat[i]]++;
        }
        
        int i=0,j=0;
        int length=mp.size();
        while(j<n){
            
            if(mp.count(txt[j])){
                mp[txt[j]]--;
                if(mp[txt[j]]==0) length--;
            }
            
            if(j-i+1==m){
                
                if(length==0) return true;//anagram found
                
                if(mp.count(txt[i])){
                    if(mp[txt[i]] == 0) length++;
                    mp[txt[i]]++;
                }
                
                i++;
            }
            
            j++;
        }
        return false;
    }

//(4).Print all anagrams together
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>ans;
        int n=arr.size();
        // key = sorted string; value = list of original strings having same sorted form
        map<string,vector<string>>mp;
        
        for(string st:arr){
            string s=st;
            // sort the string to create a unique key for anagram group
            sort(s.begin(),s.end());
            mp[s].push_back(st);
        }
        
        // collect all grouped anagrams into result
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }

// Input: arr[] = ["act", "god", "cat", "dog", "tac"]
// Output: [["act", "cat", "tac"], ["god", "dog"]]