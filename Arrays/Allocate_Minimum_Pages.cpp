class Solution {
  public:
    
    int student(vector<int>&arr, long long  pages){
        
        int std = 1; 
        long long  studentPage = 0;
        
        for(int i =0; i<= arr.size()-1; i++){
            
            if(studentPage + arr[i] <= pages){
                
                studentPage += arr[i];
            }
            else{
                std ++;
                studentPage = arr[i];
            }
        }
        return std;
    }
    
    int findPages(vector<int> &arr, int k) {
        
        if( k > arr.size()) return -1;
        
        long long  low = *max_element(arr.begin() , arr.end());
        
        long long  high = 0;
        
        for(int i = 0; i <= arr.size()-1; i++){
            
            high += arr[i];
        }
        

        
        while(low <= high){
            
            long long  mid = (low + high)/2;
            
            int countStudent = student(arr , mid);
            
            if(countStudent > k){
                 
                 low = mid + 1;
            }
            else{
                
                high = mid - 1;
            }
        }
        return low;
        
    }
};