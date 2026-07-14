/*
Pattern:
Binary Search

Handle Edge Cases:

If only one element:

Return 0

If last element >
second last:

Return last index

If first element >
second element:

Return 0

Initialize:

low = 1
high = n - 2

While:

low <= high

Find middle:

mid = low + (high - low) / 2

If:

nums[mid] > nums[mid - 1]

AND

nums[mid] > nums[mid + 1]

Peak found:

Return mid

Else If:

nums[mid] > nums[mid - 1]

You are on an
increasing slope.

Search Right:

low = mid + 1

Else

You are on a
decreasing slope.

Search Left:

high = mid - 1

Answer:

Index of any peak element

Why does it work?

A peak element is always
greater than its neighbors.

If you're on an increasing
slope, a peak must exist
to the right.

If you're on a decreasing
slope, a peak must exist
to the left.

Binary Search eliminates
half of the search space
at every step.

Time: O(log n)

Space: O(1)
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        //manual edge cases
        if(n == 1) return 0;
        if(nums[n-1] > nums[n-2]) return {n-1};
        if(nums[0] > nums[1]) return 0;

        int low = 1;
        int high = n - 2;

        while(low <= high){

            int mid = (low + high)/2;

            if(nums[mid] > nums[mid -1] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(nums[mid] > nums[mid - 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};