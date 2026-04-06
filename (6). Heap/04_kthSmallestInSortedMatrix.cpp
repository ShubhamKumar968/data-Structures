#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//Method-01: Optimal{TC=O(klogn); SC=O(n)}
class Solution {
  public:
  
    typedef pair<int,int>p;
    int kthSmallest(vector<vector<int>> &mat, int k) {
       
        int n = mat.size();
         // Min-heap stores {value, {row, col}}
        // Min heap because herre array are already sorted
        priority_queue< pair<int,p>, vector<pair<int,p>>, greater<pair<int,p>> >pq;
        
        // Push first element of each row
        for(int i = 0; i < n; i++){
            pq.push({mat[i][0], {i, 0}});
        }
        
        int ans = 0;
        
        while(!pq.empty() && k--){
            
            auto curr = pq.top();
            pq.pop();
            
            int ele = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            
            ans = ele;
            
            // If there's a next element in the same row, push it
            if(col + 1 < mat[row].size()){
                pq.push({mat[row][col + 1], {row, col + 1}});
            }
        }
        
        return ans;
    }
};
