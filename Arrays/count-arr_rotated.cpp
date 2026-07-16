/*
Pattern:
Binary Search

Goal:

Find the index of the
minimum element.

The index of the minimum
element equals the number
of rotations.

Initialize:

low = 0
high = n - 1
ans = INT_MAX
index = -1

While:

low <= high

Find middle:

mid = low + (high - low) / 2

--------------------------------

Already Sorted?

nums[low] <= nums[high]

Entire search space
is already sorted.

Minimum is:

nums[low]

Update:

ans = nums[low]

index = low

Break

--------------------------------

Left Half Sorted?

nums[low] <= nums[mid]

Minimum of this half
is nums[low].

Update:

ans = min(ans, nums[low])

index = low (if updated)

Search Right Half:

low = mid + 1

--------------------------------

Otherwise:

Rotation point lies
in the left half.

nums[mid] can be
the minimum.

Update:

ans = min(ans, nums[mid])

index = mid (if updated)

Search Left Half:

high = mid - 1

Answer:

index

Why does it work?

The minimum element is
the point where the array
was rotated.

Its index tells us
how many times the array
has been rotated.

If the current search
space is already sorted,

the first element is
the minimum.

Otherwise,

identify the sorted half,
store its minimum,
and continue searching
the unsorted half where
the rotation point exists.

Time: O(log n)

Space: O(1)
*/
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        int index = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[low] <= nums[high]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                }
                 break;
            }

            else if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }
            else{
                high = mid - 1;
                if(nums[mid] < ans){
                    index = mid;
                    ans = nums[mid];
                }
            }
        }
        return index;
    }
};