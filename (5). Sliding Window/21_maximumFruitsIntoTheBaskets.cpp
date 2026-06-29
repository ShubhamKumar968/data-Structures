#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//(1) maximum fruits into baskets of atmost 2 types
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n=fruits.size();
        int cnt=0;
        unordered_map<int,int>mp;

        int i=0,j=0;
        while(j<n){

            mp[fruits[j]]++;

            while (mp.size() > 2) {

                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++; // Slide left boundary forward
            } 
            cnt = max(cnt, j - i + 1);
            j++;
        }
        return cnt;
    }
};

//(2)maximum number of vowels in substring of length k;

class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'|| ch=='u';
    }
    int maxVowels(string s, int k) {
        
        int n=s.length();
        int cnt=0;
        int res=0;

        int i=0,j=0;

        while(j<n){
            
            if(isVowel(s[j])){
                cnt++;
            }

            if(j-i+1==k){
                res=max(res,cnt);

                if(isVowel(s[i])){
                    cnt--;
                }

                i++;
            }

            j++;
        }

        return res;
    }
};

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
