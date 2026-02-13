#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//TC= O(K*alpha(n*m)); K=no of operations
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DSU dsu(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> ans;
        int count = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (auto &op : operators) {
            int r = op[0];
            int c = op[1];

            // Edge case: cell already processed
            if (visited[r][c] == 1) {
                ans.push_back(count);
                continue;
            }

            visited[r][c] = 1;
            count++; // Assume it's a new standalone island

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] == 1){
                    int node = r * m + c;
                    int neighbor = nr * m + nc;
                    
                    if (dsu.find(node) != dsu.find(neighbor)) {
                        count--; // Merged two islands, total count decreases
                        dsu.Union(node,neighbor);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
