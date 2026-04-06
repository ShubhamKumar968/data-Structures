#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//(1). Substring -> Order matters + contiguous
//(2). Subsequence -> Only order matters(no contiguous)
//(3). Subset -> neither order nor contiguous required
//Note:- powerset, subset, subsequence are same(only in subset empty subset inclded)


//(1) find subsets in case of all unique elements
class Solution {
  public:
    //SC=O(n + n*2^n);TC=O(n*2^n) ; n=length of array; (n*2^n -> To store all subset of length n)
    vector<vector<int>>res;
    void solve(vector<int>& arr,int idx, vector<int>&subset){
         
        if(idx>=arr.size()){
            res.push_back(subset);
            return;
        }
        
       
        
        //Step-01:Take the current element
        subset.push_back(arr[idx]);
        solve(arr,idx+1,subset);
        
        //step-02: Not take the current element
        subset.pop_back();
        solve(arr,idx+1,subset);
        
        return;
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int>subset;//TO store subset
        
        solve(arr,0,subset);
        
        return res;
    }
};

//(2) find subsets in case of duplicates elements

class Solution {
  public:
    vector<vector<int>>res;
    void solve(vector<int>& arr,int idx, vector<int>&subset){
         
        if(idx>=arr.size()){
            res.push_back(subset);
            return;
        }
        
       
        
        //Step-01:include the current element
        
        subset.push_back(arr[idx]);
        solve(arr,idx+1,subset);
        
        //step-02: // Exclude nums[i] and skip duplicates
        
        subset.pop_back();
        
        int j=idx+1;
        while (j < arr.size() && arr[j] == arr[idx]) {
                j++;//skip duplicates
        }
        solve(arr,j,subset);
        
        return;
    }
    
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        vector<int>subset;//TO store subset
        sort(arr.begin(), arr.end()); // Important for handling duplicates
        solve(arr,0,subset);
        
        return res;
    }
};

//(3) find powerset or subsequences of given string
class Solution {
  public:
    vector<string>res;
    void solve(string s, int idx, string temp){
        
        if(idx>=s.length()){
            res.push_back(temp);
            //cout<<temp<<" ";
            return;
        }
        
        //step-1: We will include current character
        temp.push_back(s[idx]);
        solve(s,idx+1,temp);
        
        //step-2: We will exclude current character
        temp.pop_back();
        solve(s,idx+1,temp);
        
        return;
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        string temp="";
        solve(s,0,temp);
        
        sort(res.begin(), res.end());
        
        return res;
    }
};

//Note:- All {possible/Permutations/Combinations/Subsets etc} => Backtracking(Do,Explore,Undo)