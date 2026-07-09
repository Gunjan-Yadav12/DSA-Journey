/*
Pattern:
Two Pointers

Initialize:

left = 0
right = n - 1
k = n - 1

Compare:

nums[left]²

and

nums[right]²

Place the larger square
at res[k].

If:

left square > right square

Place left square.

left++

Else

Place right square.

right--

Move:

k--

Continue until:

left > right

Answer:

res

Why does it work?

The array is sorted,
but may contain
negative numbers.

The largest square
will always come from
either the leftmost
(large negative)
or the rightmost
(large positive) element.

Compare both ends,
place the larger square
at the end of the result,
and move inward.

Time: O(n)

Space: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i = 0;
        int j = n-1;
        int k = n-1;
        
        while(i<=j){
            int leftsquare = nums[i]*nums[i];
            int rightsquare = nums[j]*nums[j];

            if(leftsquare > rightsquare){
                res[k] = leftsquare;
                i++;
            }
            else{
                res[k] = rightsquare;
                j--;
            }
            k--;
        }
    return res;
    }
};