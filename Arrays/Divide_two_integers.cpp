/*
Pattern:
Bit Manipulation
Binary Search on Multiples

Handle Edge Case:

If:

dividend = INT_MIN

and

divisor = -1

Return:

INT_MAX

(Converting would overflow.)

Take absolute values:

a = |dividend|
b = |divisor|

Initialize:

result = 0

While:

a >= b

Find the largest multiple
of divisor using left shift.

temp = b
multiple = 1

While:

(a >= temp << 1)

Double:

temp <<= 1
multiple <<= 1

Subtract:

a -= temp

Add quotient:

result += multiple

Determine Sign:

If dividend and divisor
have opposite signs,

result = -result

Return result.

Why does it work?

Instead of subtracting
the divisor one by one,

keep doubling the divisor
using left shift until it
becomes the largest possible
multiple less than or equal
to the dividend.

Subtract that multiple
and repeat.

This greatly reduces
the number of operations.

Time: O((log n)²)

Space: O(1)
*/



class Solution {
public:
    int divide(int dividend, int divisor) {
           if(dividend == INT_MIN &&  divisor == -1)
           return INT_MAX;
              long a = labs(dividend);
              long b = labs(divisor);
        long result = 0;
        while(a >= b){
            long temp = b;
            int multiple = 1;

            while(a >= (temp << 1)){
                temp <<= 1;
                multiple <<=1;
            }
            a -= temp;
            result += multiple;
        }
        if((divisor < 0) ^ (dividend < 0)){
            result = -result;
        }
        return result ;
    }
};