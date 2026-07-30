class Solution {
public:
int maxElement(vector<int>& piles){
    int maxi = INT_MIN;
    int n = piles.size();
    for(int i=0;i<n;i++){
        maxi = max(maxi , piles[i]);
    }
    return maxi;
}
long long  minBanana(vector<int>& piles, int hourly) {

        long long  totalHours = 0;
        int n = piles.size();

        for(int i =0; i<n; i++){
            totalHours += ceil((double)piles[i]/(double)hourly);
        }
        return totalHours;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = maxElement(piles);

        while(low <= high){

            int mid = (low + high)/2;

            long long  totalHours = minBanana(piles , mid);

            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};