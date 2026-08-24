class Solution {
  public:
    int upperBound(vector<int>& arr , int x){
        
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(x < arr[mid]){
                
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int countSmallNumber(vector<vector<int>>& mat , int n , int m , int x){
        
        int count = 0;
        
        for(int i = 0; i <= n-1; i++){
            
            count += upperBound(mat[i] , x);
        }
        return count;
    }
    
    int median(vector<vector<int>> &mat) {
       int n = mat.size();
       int m = mat[0].size();
       
       int low = INT_MAX;
       int high = INT_MIN;
       
       for(int i = 0; i <= n-1; i++){
           
           low = min(low , mat[i][0]);
           high = max(high , mat[i][m-1]);
       }
       
       int req = (n*m)/2;
       
       while(low <= high){
           
           int mid = (low + high)/2;
           
           int smallerValue = countSmallNumber(mat , n  , m , mid);
           
           if(smallerValue <= req){
               low = mid + 1;
           }
           else{
               high = mid - 1;
           }
       }
       return low;
    }
};
