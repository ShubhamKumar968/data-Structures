class Solution {
  public:
    typedef pair<int,int> p;
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<p>pq;
        
        int n=points.size();
        
        for(int i=0;i<n;i++){
            
            int x=points[i][0];
            int y=points[i][1];
            
            pq.push({x*x+y*y,i});
            
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<vector<int>>res;
        
        while(!pq.empty()){
            int idx=pq.top().second;
            pq.pop();
            res.push_back(points[idx]);
            
        }
        
        return res;
    }
};
