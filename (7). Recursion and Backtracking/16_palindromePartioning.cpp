#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<string>>res;
    bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }

    void solve(string s,int idx,int n,vector<string>&curr){
        if(idx==n){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,n,curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>curr;
        int n=s.length();
        solve(s,0,n,curr);
        return res;
    }
    
};