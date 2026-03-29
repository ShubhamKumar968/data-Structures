#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) maximum fruits into baskets of atmost 2 types
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp;
        int i=0,j=0,cnt=0;

        while(j<n){

            mp[fruits[j]]++;
            
            while(mp.size()>2){

                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
               
            }
            if(mp.size()<=2){
                cnt=max(cnt,j-i+1);
            }
            
            j++;
        }
        return cnt;
    }
};

//(2)maximum number of vowels in substring of length k;

    bool isVowel(char &ch){
       return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }

    int maxVowels(string s, int k) {

        int n=s.length();
        int i=0,j=0,maxi=0,cnt=0;

        //lambda is similar to above function
        auto isVowel=[&](char ch){
            return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
        };
        
        while(j<n){
            
            if(isVowel(s[j])){
                cnt++;
            }
            if(j-i+1==k){
                maxi=max(maxi,cnt);
                if(isVowel(s[i])){
                    cnt--;
                   
                }
                 i++;
            }
            j++;
        }
        return maxi;
    }

//(3) frequency of the most frequent element

int maxFrequency(vector<int>& nums, int k) {

        sort(begin(nums),end(nums));


        int n=nums.size();
        int i=0,j=0;
        long currSum=0;
        int res=0;
        
        while(j<n){
            long tar=nums[j];
            currSum+=nums[j];
            while((j-i+1)*tar-currSum>k){
                currSum-=nums[i];
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res; 
}