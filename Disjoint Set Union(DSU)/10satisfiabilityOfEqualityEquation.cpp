#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class DSU {
public:
    vector<int> par;
    vector<int> size; // Use size instead of rank for easy area calculation

    DSU(int n) {
       size.resize(n, 1); // Each node starts as an island of size 1
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
        if (size[x_par] < size[y_par]) {
            par[x_par] = y_par;
            size[y_par] += size[x_par];
        } else {
            par[y_par] = x_par;
            size[x_par] += size[y_par];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
       DSU dsu(26);
       for(auto &s:equations){
            
            if(s[1]=='='){//'a==b' equal to wala case
                 dsu.Union(s[0]-'a', s[3]-'a');
            }
       }
       //find != wala case and check validity
       for(auto &s:equations){
            
            if(s[1]=='!'){//'a!=b' equal to wala case
                 char u=s[0];//a
                 char v=s[3];//b
                 if(dsu.find(u -'a')==dsu.find(v -'a')){//yani dono same group ke honge
                      return false;
                 }
            }
       }
       return true;
    }
};