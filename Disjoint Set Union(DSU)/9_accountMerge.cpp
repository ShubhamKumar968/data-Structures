#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class DSU {
public:
    vector<int> par;
    vector<int> sz; // Use size instead of rank for easy area calculation

    DSU(int n) {
        sz.resize(n, 1); // Each node starts as an island of size 1
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void Union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);
        if (x_par == y_par) return;

        // Union by Size
        if (sz[x_par] < sz[y_par]) {
            par[x_par] = y_par;
            sz[y_par] += sz[x_par];
        } else {
            par[y_par] = x_par;
            sz[x_par] += sz[y_par];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;
        int id = 0;

        // Step 1: Assign unique IDs to emails and map them to the account name
        // TC: O(N * K * L), where L is the average length of an email string (for hashing)
        // SC: O(N * K * L) to store emails in the map
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                if (emailToId.find(email) == emailToId.end()) {
                    emailToId[email] = id++;
                    emailToName[email] = name;
                }
            }
        }

        // Step 2: Use DSU to union all emails in the same account
        // TC: O(N * K * alpha(NK))
        // SC: O(NK) for DSU parent and size arrays
        DSU dsu(id);
        for (auto& acc : accounts) {
            string firstEmail = acc[1];
            for (int i = 2; i < acc.size(); i++) {
                dsu.Union(emailToId[firstEmail], emailToId[acc[i]]);
            }
        }

        // Step 3: Group emails by their root parent
        // Root ID -> List of emails belonging to that component
        // TC: O(N * K * alpha(NK))
        // SC: O(N * K) to store grouped strings
        unordered_map<int, vector<string>> components;
        for (auto it = emailToId.begin(); it != emailToId.end(); it++) {
            string email = it->first;
            int root = dsu.find(it->second);
            components[root].push_back(email);
        }

        // Step 4: Format the output (sort emails and add the name)
        // TC: O(NK * log(NK)) for sorting merged lists
        // SC: O(NK) for the final result vector
        vector<vector<string>> merged;
        for (auto& it : components) {
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end()); // Sorting as per requirement
            
            vector<string> row;
            row.push_back(emailToName[emails[0]]); // Prepend name
            row.insert(row.end(), emails.begin(), emails.end());
            merged.push_back(row);
        }

        return merged;
    }
};
// Total: TC=O(N*K*(L +alpha(NK) + log(NK))); SC=O(N* K * L)
