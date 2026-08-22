class Solution {
  public:
    
    int student(vector<int>&nums, long long  pages){
        
        int std = 1; 
        long long  studentPage = 0;
        
        for(int i =0; i<= nums.size()-1; i++){
            
            if(studentPage + nums[i] <= pages){
                
                studentPage += nums[i];
            }
            else{
                std ++;
                studentPage = nums[i];
            }
        }
        return std;
    }
    
    int findPages(vector<int> &nums, int m) {
        
        if( m > nums.size()) return -1;
        
        long long  low = *max_element(nums.begin() , nums.end());
        
        long long  high = 0;
        
        for(int i = 0; i <= nums.size()-1; i++){
            
            high += nums[i];
        }
        
        while(low <= high){
            
            long long  mid = (low + high)/2;
            
            int countStudent = student(nums , mid);
            
            if(countStudent > m){
                 
                 low = mid + 1;
            }
            else{
                
                high = mid - 1;
            }
        }
        return low;
        
    }
};