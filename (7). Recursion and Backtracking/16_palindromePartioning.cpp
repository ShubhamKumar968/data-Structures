#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC=O(n*2^n)
    bool isPalindrome(string s, int i, int j){
        
        if(i>=j) return true;
        
        if(s[i] !=s[j]){
            return false;
        }
        
        return isPalindrome(s,i+1,j-1);
    }

    void solve(string &s,int n,int idx,vector<vector<string>>&res,vector<string>&curr){

        if(idx==n){
            res.push_back(curr);
            return;
        }
        
        string temp="";
        for(int i=idx;i<n;i++){
            temp+=s[i];// Building the substring

            if(isPalindrome(s,idx,i)){
                //Take current substring
                curr.push_back(temp);
                //Explore just next substring
                solve(s,n,i+1,res,curr);
                // Backtrack
                curr.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>curr;
        int n=s.length();
        solve(s,n,0,res,curr);
        return res;
    }
};
