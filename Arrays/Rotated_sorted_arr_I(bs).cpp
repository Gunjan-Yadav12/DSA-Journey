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

Return mid

Check which half
is sorted.

------------------

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

------------------

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

Return -1

Why does it work?

In a rotated sorted array,
at least one half is always sorted.

Identify the sorted half.

If the target lies in that half,
search there.

Otherwise, search the other half.

This eliminates half of the
search space in every iteration.

Time: O(log n)

Space: O(1)
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target) return mid;

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
        return -1;
    }
};