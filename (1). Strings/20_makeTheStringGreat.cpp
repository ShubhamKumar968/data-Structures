#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// 'a' - 32 ='A'

class Solution {
public:
    string makeGood(string s) {

        string res="";
        for(auto& ch:s){
            if(!res.empty() && (res.back()-32==ch || res.back()+32==ch) ){
                //both are capital & small adjacently
                res.pop_back();
            }else{
                res.push_back(ch);
            }
        }
        return res;
    }
};