class Solution {
public:
    int arrayCounting(vector<int>& nums , int units){
        int count = 1 , arrayCount = 0;
        
        for(int i = 0; i <= nums.size()-1; i++){

            if(arrayCount + nums[i] <= units){
                arrayCount += nums[i];
            }
            else{
                count ++;
                arrayCount = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums , int k){
        if(k > nums.size()) return -1;
        long long low = *max_element(nums.begin() , nums.end());
        long long high = 0;

        for(int i = 0; i<= nums.size()-1; i++){
            high += nums[i];
        }

        while(low <= high){

            long long mid = (low + high)/2;

            long long noOfSplits = arrayCounting(nums , mid);

            if(noOfSplits > k){

                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    
};