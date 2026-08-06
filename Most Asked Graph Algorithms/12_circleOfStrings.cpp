class DSU {
public:
    vector<int> par;
    vector<int> rank;

    DSU(int n) {
        rank.resize(n, 0);
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]); // Path compression
    }

    void Union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);

        if (x_par == y_par) return;

        if (rank[x_par] > rank[y_par]) {
            par[y_par] = x_par;
        } else if (rank[x_par] < rank[y_par]) {
            par[x_par] = y_par;
        } else {
            par[y_par] = x_par;
            rank[x_par]++;
        }
    }
};

class Solution {
public:
    bool isCircle(vector<string> &arr) {
        DSU dsu(26);
        vector<int> inDegree(26, 0);
        vector<int> outDegree(26, 0);
        vector<bool> present(26, false);

        // 1. Build degree counts and unify nodes via DSU
        for (const string &s : arr) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';

            outDegree[u]++;
            inDegree[v]++;
            present[u] = true;
            present[v] = true;

            dsu.Union(u, v);
        }

        // 2. Degree condition check
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] != outDegree[i]) {
                return false;
            }
        }

        // 3. Collect unique representative components using unordered_set
        unordered_set<int> components;
        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                components.insert(dsu.find(i));
            }
        }

        // Exactly 1 component means all characters are part of a single connected graph
        return components.size() == 1;
    }
};
