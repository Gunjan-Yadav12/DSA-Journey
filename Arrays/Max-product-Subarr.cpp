/*
Pattern:
Prefix Product + Suffix Product

Initialize:

prefix = 1
suffix = 1
maxProduct = INT_MIN

Traverse array:

prefix *= nums[i]
suffix *= nums[n-i-1]

Update:

maxProduct =
max(maxProduct,
    max(prefix, suffix))

If prefix becomes 0:
reset prefix = 1

If suffix becomes 0:
reset suffix = 1

Answer:
maxProduct

Why Prefix + Suffix?

Negative numbers can flip
the sign of the product.

The maximum product may start
after a negative number or end
before a negative number.

Scanning from both directions
handles both cases.

Why reset on 0?

Any product containing 0
becomes 0.

Start a fresh subarray after 0.

Time: O(n)

Space: O(1))
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1 ,  suffix = 1;
        int maxSubArr = INT_MIN;

        for(int i=0;i<n;i++){

            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];

            maxSubArr = max(maxSubArr , max (prefix , suffix));
        }
        return maxSubArr;
    }
};
