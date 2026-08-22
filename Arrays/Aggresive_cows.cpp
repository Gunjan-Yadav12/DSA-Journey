class Solution {
public:
    bool canWePlace(vector<int>&nums , int k , int dist){
        int cowCount = 1 , last = nums[0];
        

        for(int i = 1; i<= nums.size()-1; i++){

            if(nums[i] - last >= dist){
                cowCount ++;
                last = nums[i];
            }
        } 
        if(cowCount >= k) return true;
        else return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
       int n = nums.size();
       sort(nums.begin() , nums.end());
       int low = 0 , high = (nums[n-1] - nums[0]);

       while(low <= high){

        int mid = (low + high)/2;

        if(canWePlace(nums , k , mid) == true){
            low = mid + 1;
        }
        else{
             high = mid - 1;
        }
       }
       return high;

    }
};