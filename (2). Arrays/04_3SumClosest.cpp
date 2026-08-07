class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int res = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < n - 2; i++) {
            
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                if (sum == target) {
                    return sum; // Exact match found
                }

                // Update closest result
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                } 
                // Tie-breaker: If differences are equal, pick the larger sum
                else if (abs(sum - target) == abs(res - target)) {
                    res = max(res, sum);
                }

                // Move two pointers based on sum comparison
                if (sum < target) {
                    j++; // Need a larger sum
                } else {
                    k--; // Need a smaller sum
                }
            }
        }

        return res; // Placed OUTSIDE the for loop
    }
};
