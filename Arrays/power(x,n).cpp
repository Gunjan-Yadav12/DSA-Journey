/*
Problem: Pow(x, n)
Platform: LeetCode

Approach:
1. Handle negative powers:
   - Convert x to 1/x.
   - Make power positive.

2. Initialize:
   result = 1

3. While power > 0:
   - If power is odd:
       multiply result by x.
   - Square x.
   - Divide power by 2.

4. Return result.

Key Idea:
Use Binary Exponentiation.

Instead of:

x × x × x × x × x × ...

n times

Keep squaring x and process
the bits of n.

Example:

x = 2
n = 10

10 in binary:

1010

2¹ = 2
2² = 4
2⁴ = 16
2⁸ = 256

10 = 8 + 2

Therefore:

2¹⁰

=
2⁸ × 2²

=
256 × 4

=
1024

Pattern:
Binary Exponentiation
Math

Time Complexity:
O(log n)

Space Complexity:
O(1)

Why Use long long?

n can be:

-2147483648

(INT_MIN)

If we do:

n = -n

it overflows.

Example:

INT_MIN = -2147483648

INT_MAX = 2147483647

So:

power = (long long)n

prevents overflow.

Revision:

If n < 0:

x = 1/x
n = -n

While n > 0:

Odd Power:
result *= x

Square Base:
x *= x

Half Power:
n /= 2

Return result
*/









class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        double result = 1;
        if(power < 0){
            x = 1/x;
            power = -power;
        }
        while(power > 0 ){
            if(power % 2 == 1){
                result = result *x;
            }
                x = x*x;
            
            power = power /2;
        }
        return result;
        
    }
};