class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        // Sum of the first k cards from the left
        int currentSum = 0;
        for (int i = 0; i < k; ++i) {
            currentSum += cardPoints[i];
        }
        
        int maxScore = currentSum;
        
        // Remove 1 card from left and add 1 card from right at each step
        for (int i = 1; i <= k; ++i) {
            currentSum += cardPoints[n - i] - cardPoints[k - i];
            maxScore = max(maxScore, currentSum);
        }
        
        return maxScore;
    }
};