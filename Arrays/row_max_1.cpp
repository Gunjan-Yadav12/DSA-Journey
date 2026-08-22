class Solution {
  public:
    int lowerBound(vector<int>& arr , int m, int x){
        
        
        int low = 0 , high = m - 1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(arr[mid] >= x){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) {
        
    int n = arr.size();
    int m = arr[0].size();
    
    int max_count = 0;
    int index = -1;
    
    for(int i = 0; i<= n - 1; i++){
        int count =  m - lowerBound(arr[i] , m ,1);
        
        if(count > max_count){
            max_count = count;
            index = i;
        }
    }
    return index;
    }
};