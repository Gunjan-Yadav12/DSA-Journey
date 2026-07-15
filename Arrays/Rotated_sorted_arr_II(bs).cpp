/*
Pattern:
Binary Search

Initialize:

low = 0
high = n - 1

While:

low <= high

Find middle:

mid = low + (high - low) / 2

If:

nums[mid] == target

Return true

--------------------------------

Handle Duplicates:

If:

nums[low] == nums[mid]

AND

nums[mid] == nums[high]

Cannot determine
which half is sorted.

Shrink search space:

low++

high--

Continue

--------------------------------

Left Half Sorted:

nums[low] <= nums[mid]

If:

target lies between

nums[low]

and

nums[mid]

Search Left:

high = mid - 1

Else:

Search Right:

low = mid + 1

--------------------------------

Right Half Sorted:

Otherwise

If:

target lies between

nums[mid]

and

nums[high]

Search Right:

low = mid + 1

Else:

Search Left:

high = mid - 1

If target is not found:

Return false

Why does it work?

Without duplicates,
one half is always
clearly sorted.

With duplicates like:

[1,1,1,3,1]

both halves may appear
sorted.

When:

nums[low] == nums[mid] == nums[high]

we cannot decide which
half is sorted.

So we shrink the search
space by moving both
pointers inward and
continue the binary search.

Time:

Average: O(log n)

Worst Case: O(n)
(due to many duplicates)

Space: O(1)
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target) return true;
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }

            //left sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            //right sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};