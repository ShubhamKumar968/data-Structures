#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:

    char  tolower (char ch){
        if(ch>='A'&&ch<='Z'){
             int temp=ch-'A'+'a';
             return temp;
        }else{
             return ch;
        }
    }

    bool isAlphaNumeric(char ch){
          if((ch>='0'&& ch<='9')||(tolower(ch)>='a' && tolower(ch)<='z')){
                return true;
          }
          return false;
    }

    bool isPalindrome(string s) {
        int st=0,e=s.length()-1;
        while(st<e){
           
            if(!isAlphaNumeric(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNumeric(s[e])){
                e--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[e])){
                return false;
            } 
            st++;
            e--;
        }
        return true;   
    }
};