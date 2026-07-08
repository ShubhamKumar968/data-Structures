#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-1

class Solution {
public:

    bool allCapital(string s){
        for(auto &ch:s){
            if(ch<'A' || ch>'Z'){
                return false;
            }
        }
        return true;
    }


    bool allSmall(string s){
        for(auto &ch:s){
            if(ch<'a' || ch>'z'){
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(string s) {

        if(allCapital(s) || allSmall(s) || allSmall(s.substr(1)) ){
            return true;
        }
        
        return false;
    }
};

//Method-2

class Solution {
public:

    
    bool detectCapitalUse(string s) {
        int n=s.length();
        int countCapitals=0;

        for(auto &ch:s){
            if(ch>='A' && ch<='Z'){
                countCapitals++;
            }
            
        }
        
       if (countCapitals == 0 || countCapitals == n || (countCapitals == 1 && s[0] >= 'A' && s[0] <= 'Z')) {
            return true;
        }
        return false;
    }
};