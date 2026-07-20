/*
Pattern:
Binary Search on Answer
Power Checking

Goal:

Find an integer x such that:

xⁿ = m

Search Space:

0 to m

--------------------------------

Helper Function:

function(mid, n, m)

Calculate:

midⁿ

But stop early if:

midⁿ > m

Return:

1 → midⁿ == m

2 → midⁿ > m

0 → midⁿ < m

--------------------------------

Binary Search:

low = 0
high = m

Find:

mid

Check:

midⁿ

--------------------------------

If:

midⁿ == m

Return mid

--------------------------------

If:

midⁿ < m

mid is too small.

Search Right:

low = mid + 1

--------------------------------

If:

midⁿ > m

mid is too large.

Search Left:

high = mid - 1

--------------------------------

If no exact root exists:

Return -1

Why does it work?

For positive values of mid:

As mid increases,

midⁿ also increases.

So the answer follows
a sorted/monotonic pattern:

midⁿ < m
      ↓
midⁿ = m
      ↓
midⁿ > m

Binary search finds the exact
value efficiently.

Time: O(log m × n)

Space: O(1)
*/
class Solution {
  public:
  
    int function(int mid , int n , int m){
        
        long long ans = 1;
        
        for(int i = 1; i<= n; i++){
            
            ans = ans * mid;
            
            if(ans > m) return 2;
        }
        if(ans == m) return 1;
        return 0;
    }
    
    int nthRoot(int n, int m) {
        
        int low = 0; int high = m;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            int midN = function(mid , n , m);
            
            if(midN == 1) return mid;
            
            else if( midN == 0){
                low = mid + 1;
            }
            else{
                 high = mid - 1;
            }
        }
        return -1;
    }
};