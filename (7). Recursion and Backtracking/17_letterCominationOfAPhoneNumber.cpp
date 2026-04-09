#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC=O(4^n)
    vector<string>res;
    unordered_map<char, string>mp;

    void solve(string &digits,int idx, int n, string&temp){

        if(idx>=n){
            res.push_back(temp);
            return;
        }

        for (auto &ch : mp[digits[idx]]){

            temp.push_back(ch);//do
            solve(digits,idx+1,n,temp);//explore
            temp.pop_back();//undo
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        
        int n=digits.length();
        int idx=0;
        string temp="";

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        solve(digits,idx,n,temp);
        return res;

    }
};