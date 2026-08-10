class Solution {
    
  public:
  
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
     
        int m = mat.size();    // Number of rows
        int n = mat[0].size(); // Number of columns
        
        // Initialize boundary pointers
        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;
        
        vector<int> res;
        
        // Loop until boundaries cross each other
        while (srow <= erow && scol <= ecol) {
            
            // 1. Traverse Top row (left to right)
            for (int j = scol; j <= ecol; j++) {
                res.push_back(mat[srow][j]);
            }
            srow++;
            
            // 2. Traverse Right column (top to bottom)
            for (int i = srow; i <= erow; i++) {
                res.push_back(mat[i][ecol]);
            }
            ecol--;
            
            // 3. Traverse Bottom row (right to left)
            for (int j = ecol; j >= scol && srow<=erow; j--) {
                res.push_back(mat[erow][j]);
            }
            erow--;
            
            // 4. Traverse Left column (bottom to top)
            for (int i = erow; i >= srow && scol<=ecol; i--) {
                res.push_back(mat[i][scol]);
            }
            scol++;
            
        }
        return res;
    }
};
