/*
Pattern:
Binary Search on Answer

Search Space:

0 to x

Goal:

Find the largest integer
whose square is <= x.

Initialize:

low = 0
high = x

While:

low <= high

Find middle:

mid = low + (high - low) / 2

--------------------------------

If:

mid * mid <= x

mid is a possible answer.

Search for a larger value:

low = mid + 1

--------------------------------

Else:

mid is too large.

Search smaller values:

high = mid - 1

--------------------------------

Answer:

high

Why return high?

When the loop ends:

low > high

So:

high = Last Valid Value

low = First Invalid Value

The last valid value is
the integer square root.

Example:

x = 8

Possible values:

0² <= 8 ✓
1² <= 8 ✓
2² <= 8 ✓
3² > 8 ✗

Answer:

2
*/

class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while(low <= high){
            long long  mid = (low + high)/2;

            if(mid * mid <= x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
        
    }
};