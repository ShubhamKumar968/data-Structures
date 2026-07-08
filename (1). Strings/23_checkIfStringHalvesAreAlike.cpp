#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='A'|| ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||
             ch=='u'||ch=='U') return 1;
       return 0;
    }

    bool halvesAreAlike(string s) {
        
        int n=s.length();
        int leftCount = 0, rightCount = 0; // Tracks found vowels on both sides
        int mid = n / 2;                   // Center splitting line of the sentence text
        int i = 0, j = mid;                // Left/Right tracking pointers

        while (i < mid && j < n) {
            if (isVowel(s[i])) leftCount++;
            if (isVowel(s[j])) rightCount++;
            i++, j++;
        }

        return leftCount == rightCount; // True if both side frequencies balance perfectly
    }
};