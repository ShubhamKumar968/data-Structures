#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
           int n=words.size();
           int m=weights.size();
           string res="";

           for(int i=0;i<n;i++){

               int sum=0;
               string curr=words[i];

               for(int j=0;j<curr.length();j++){
                    int idx= curr[j]- 97;
                    sum+=weights[idx];
               }

               sum=sum%26;
               char temp=('a'+sum);
               res+=  'a' + ('z'-temp);
               
           }
           return res;
    }
};