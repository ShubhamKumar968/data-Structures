#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//TC=O(max(m,n))
class Solution {
public:
    //string temp =str.substr(start_index, length);
    //string temp(m - n, '0');
    string addBinary(string a, string b) {

        int m=a.length(),n=b.length();
        int sum=0;
        int carry=0;
        string res="";
        int i=m-1,j=n-1;

        while(i>=0 || j>=0){

            sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            res.push_back((sum%2==0)?'0' :'1');
            carry= (sum>1) ? 1: 0;// carry=sum/2
        }
        if(carry==1) res.push_back('1');

        reverse(res.begin(),res.end());
        return res;
    }
};

//Input: a = "11", b = "1"
//Output: "100"