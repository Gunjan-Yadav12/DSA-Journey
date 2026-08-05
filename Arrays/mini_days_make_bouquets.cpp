class Solution {
public:
    bool possibleDays(vector<int>&bloomDay, int day , int m , int k){

        int n = bloomDay.size();
        int count = 0;
        int numOfBouquet = 0;

        for(int i=0;i<n;i++){

            if(bloomDay[i] <= day){
                count ++;
            }
            else{
                numOfBouquet += (count / k);
                count = 0;
            }
        }
        numOfBouquet += (count / k);

        if(numOfBouquet >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low  = *min_element(bloomDay.begin() , bloomDay.end());

        int high = *max_element(bloomDay.begin() , bloomDay.end());
        
        long long val = m * 1ll * k * 1ll;

        if(bloomDay.size() < val ) return -1;

        while(low <= high){

        int mid = (low + high)/2;

        if(possibleDays(bloomDay , mid , m , k) == true){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        }
        return low;
    }
};