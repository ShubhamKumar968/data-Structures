

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {

        int m = grid.size();
        int n = grid[0].size();

        // dp[row][col][k] = minimum distance to reach (row, col) using exactly k obstacles
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(K + 1, INT_MAX)));

        // {distance, row, col, obstaclesUsed}
        using State = tuple<int, int, int, int>;

        priority_queue<State,vector<State>,greater<State>> pq;

        int startK = grid[0][0];

        if (startK > K) return -1;

        dp[0][0][startK] = 0;
        pq.push({0, 0, 0, startK});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!pq.empty()) {

            auto [dist, x, y, k] = pq.top();
            pq.pop();

            // Destination
            if (x == m - 1 && y == n - 1) return dist;

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                // Valid position
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

                    int nk = k + grid[nx][ny];

                    // Valid obstacle count
                    if (nk <= K) {

                        int newDist = dist + 1;

                        // Relaxation
                        if (newDist < dp[nx][ny][nk]) {

                            dp[nx][ny][nk] = newDist;
                            pq.push({newDist,nx,ny,nk});

                        }
                    }
                }
            }
        }

        return -1;
    }
};
