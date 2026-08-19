class Solution {
public:

    //Method-01: Brute force approach

    string res = "";  // Stores the maximum number found so far

    void solve(string& s, int k, int idx, int n) {

        // If no swaps are left OR we have processed all positions, compare the current permutation with the best answer
        if (k == 0 || idx == n) {
            res = max(res, s);
            return;
        }

        // Try putting every character from idx to n-1 at position idx
        for (int i = idx; i < n; i++) {

            // Swap current character with the character at idx
            swap(s[i], s[idx]);

            // If i != idx, one swap is used. Move to the next position.
            solve(s, k - (i != idx), idx + 1, n);

            // Backtrack: restore the original string
            swap(s[i], s[idx]);
        }
    }

    string findMaximumNum(string& s, int k) {

        int n = s.length();

        // Start recursion from the first position
        solve(s, k, 0, n);

        return res;
    }
};

//Method-02: Optimal Approach:

class Solution {
public:

    string res = "";

    void solve(string& s, int k, int idx) {

        if (k == 0 || idx == s.size()) {
            res = max(res, s);
            return;
        }

        // Find maximum digit from idx onwards
        char maxi = s[idx];
        for (int i = idx + 1; i < s.size(); i++) {
            maxi = max(maxi, s[i]);
        }

        // If current digit is already maximum, don't waste a swap. Move to next position.
        if (s[idx] == maxi) {
            solve(s, k, idx + 1);
            return;
        }

        // Try every occurrence of maximum digit
        for (int i = idx + 1; i < s.size(); i++) {

            if (s[i] == maxi) {

                swap(s[idx], s[i]);//Do Changes

                solve(s, k - 1, idx + 1);//Explore

                swap(s[idx], s[i]);// Backtrack
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        solve(s, k, 0);
        return res;
    }
};
