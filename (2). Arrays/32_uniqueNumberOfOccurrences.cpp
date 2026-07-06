#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01:

bool uniqueOccurrences(vector<int>& arr) {
    // Step 1: Count the frequency of each element
    unordered_map<int, int> mp;
    for (auto &x : arr) {
        mp[x]++;
    }

    // Step 2: Insert frequencies into a set to filter duplicates
    unordered_set<int> st;
    for (auto &it : mp) {
        st.insert(it.second);
    }

    // Step 3: If unique frequency count equals total distinct elements, frequencies are unique
    return st.size() == mp.size();
}

//Method-02:

bool uniqueOccurrences(vector<int>& arr) {
    
    // Step 1: Initialize frequency array of size 2001 (handles range -1000 to 1000)
    vector<int> freq(2001, 0);
    for (int x : arr) {
        freq[x + 1000]++; // Offset by 1000 to map negative numbers to positive indices
    }

    // Step 2: Sort the frequencies to bring identical counts next to each other
    sort(freq.begin(), freq.end());

    // Step 3: Check for duplicate non-zero frequencies
    for (int i = 1; i < 2001; i++) {
        // If a frequency exists and matches the adjacent one, occurrences are not unique
        if (freq[i] > 0 && freq[i] == freq[i - 1]) {
            return false;
        }
    }

    return true;
}