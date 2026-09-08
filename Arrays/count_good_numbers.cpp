class Solution {
public:
    int MOD = 1e9+7;
    long long goodCount(long long base , long long expo){
        //base case
        if(expo == 0) return 1;

        //recursive call
        long long half = goodCount(base , expo/2);

        //processing
        long long result = (half * half) % MOD;

        if(expo % 2 == 1){
            result = (result * base) % MOD;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        
        long long even_seats = (n + 1)/2;
        long long odd_seats = n/2;

        long long even_ways = goodCount(5 , even_seats);
        long long odd_ways = goodCount(4 , odd_seats);

        return (even_ways * odd_ways) % MOD;
    }
};