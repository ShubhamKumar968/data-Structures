#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Using 2d- Array

    // Helper to convert 1D cell number (1 to n*n) to 2D matrix coordinates (snake-like pattern)
class Solution {
private:
    pair<int, int> getCoordinate(int n, int val) {
        // 0-indexed row & column from the bottom-left
        int row = (val - 1) / n;
        int col = (val - 1) % n;

        // Flip row for top-down indexing; reverse column on odd rows for zigzag
        return {(n - 1) - row, (row % 2 == 1) ? ((n - 1) - col) : col};
    }

public:
    int minSteps(int n, vector<int>& lad, vector<int>& sn) {
      
        int target = n * n;
        vector<vector<int>> grid(n, vector<int>(n, -1));

        // Populate ladders
        for (int i = 0; i < lad.size(); i += 2) {
            auto [r, c] = getCoordinate(n, lad[i]);
            grid[r][c] = lad[i + 1];
        }

        // Populate snakes
        for (int i = 0; i < sn.size(); i += 2) {
            auto [r, c] = getCoordinate(n, sn[i]);
            grid[r][c] = sn[i + 1];
        }

        // Level-order BFS using standard double while loop
        queue<int> q; // Stores only cell values (no pair needed)
        vector<bool> visited(target + 1, false);

        q.push(1);
        visited[1] = true;

        int steps = 0;

        // Outer loop: traverses level by level
        while (!q.empty()) {
            int sz = q.size();

            // Inner loop: processes all nodes at the current distance level
            while (sz--) {
              
                int curr = q.front();
                q.pop();

                if (curr == target) return steps;

                for (int dice = 1; dice <= 6; ++dice) {
                    int next = curr + dice;
                    if (next > target) break;

                    auto [r, c] = getCoordinate(n, next);
                    int destination = (grid[r][c] != -1) ? grid[r][c] : next;

                    if (!visited[destination]) {
                        visited[destination] = true;
                        q.push(destination);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};


//Method-02: Optimal 

class Solution {
  public:
    
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        
       int target = n * n;

       // 1D board: board[i] stores the destination if cell 'i' is a ladder/snake, else -1
       vector<int> board(target + 1, -1);

       for (int i = 0; i < lad.size(); i += 2) {
           board[lad[i]] = lad[i + 1];
       }

       for (int i = 0; i < sn.size(); i += 2) {
           board[sn[i]] = sn[i + 1];
       }

       // BFS to find the shortest path
       queue<pair<int, int>> q; // {current_cell, steps}
       vector<bool> visited(target + 1, false);

       q.push({1, 0});
       visited[1] = true;

       int ans = -1;
       while (!q.empty()) {
           
           auto [curr, steps] = q.front();
           q.pop();

           if (curr == target) {
               return steps;
           }

           for (int dice = 1; dice <= 6; ++dice) {
               
               int next = curr + dice;
               if (next > target) break;

               // If next cell has a ladder or snake, move to its destination
               int destination = (board[next] != -1) ? board[next] : next;

               if (!visited[destination]) {
                   visited[destination] = true;
                   q.push({destination, steps + 1});
               }
               
           }
       }

       return ans;
    }
};
