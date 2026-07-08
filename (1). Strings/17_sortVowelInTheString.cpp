#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01:

class Solution {
public:
    bool isVowel(char ch) {
        // Convert to lowercase to handle both upper and lower case letters safely
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    string sortVowels(string s) {
        int n=s.length();
        string temp="";

        for(auto &ch:s){
            if(isVowel(ch)){
                temp+=ch;
            }
        }

        sort(temp.begin(),temp.end());

        int j=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=temp[j];
                j++;
            }
        }
        return s;
    }
};

//Method-02 (-> counting sort)


class Solution {
  public:
    bool isVowel(char ch) {
        char lower = tolower(ch);
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }
    
    string sortVowels(string s) {
        int n = s.length();
        
        // Step 1: Count vowel frequencies using an unordered_map (Hash Table)
        unordered_map<char, int> vowelMap;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowelMap[ch]++;
            }
        }
        
        // Vowels defined in strict sorted ASCII order (uppercase first)
        string vowelOrder = "AEIOUaeiou";
        int j = 0; // Pointer to track our position in vowelOrder
        
        // Step 2: Traverse s and replace vowels sequentially using the map data
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                // Find the next vowel in vowelOrder that has a count > 0 in our map
                while (vowelMap[vowelOrder[j]] == 0) {
                    j++;
                }
                
                s[i] = vowelOrder[j];    // Overwrite with the sorted vowel
                vowelMap[vowelOrder[j]]--; // Decrement the frequency count in the map
            }
        }
        
        return s;
    }
};



