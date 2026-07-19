/*
Pattern:
Binary Search
Index Parity

Every element appears
exactly twice except one.

In the correct pattern:

Before the single element:

Even Index → First of Pair
Odd Index → Second of Pair

After the single element:

Odd Index → First of Pair
Even Index → Second of Pair

--------------------------------

Handle Edge Cases:

If n == 1:

Return nums[0]

If:

nums[0] != nums[1]

Return nums[0]

If:

nums[n-1] != nums[n-2]

Return nums[n-1]

--------------------------------

Initialize:

low = 1
high = n - 2

While:

low <= high

Find:

mid = low + (high - low) / 2

--------------------------------

Check Single Element:

If:

nums[mid] != nums[mid - 1]

AND

nums[mid] != nums[mid + 1]

Return nums[mid]

--------------------------------

Check Pair Pattern:

If:

mid is odd

AND

nums[mid] == nums[mid - 1]

OR

mid is even

AND

nums[mid] == nums[mid + 1]

The pairing pattern is
still correct.

The single element
must be on the right.

Search Right:

low = mid + 1

--------------------------------

Otherwise:

The pairing pattern
has broken.

The single element
must be on the left.

Search Left:

high = mid - 1

Answer:

The only element that
does not have a pair.

Time: O(log n)

Space: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
    
        //edge cases
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[ n-2]) return nums[n-1];

        int low = 1;
        int high = n - 2;

        while(low <= high){

            int mid = (low + high)/2;

            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            else if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};