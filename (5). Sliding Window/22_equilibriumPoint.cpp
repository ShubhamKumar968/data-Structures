class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        
        int n=arr.size();
        int sum=0;
        for(auto &x:arr) sum+=x;
        int preSum=0;
        int suffSum=sum;
        
        for(int i=0;i<n;i++){
            
            suffSum-=arr[i];
            
            if(preSum==suffSum){
                return i;
            }
            
            preSum+=arr[i];
            
        }
        
        return -1;
    }
};