class Solution {
public:
    int Days(vector<int>& weights ,  int capacity){

        int days = 1;
        int load = 0;

        for(int i=0; i<weights.size(); i++){

            if(load + weights[i] > capacity){

                days = days + 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        int sum = 0;

        for(int i = 0; i<weights.size(); i++){

            sum += weights[i];
        }
        int high = sum;

        while(low <= high){
            int mid = (low + high)/2;

            int numberOfDays = Days(weights , mid);

            if(numberOfDays <= days){
                 high = mid - 1;
            }
            else{
                 low = mid + 1;
            }
        }
        return low;
        
    }
};