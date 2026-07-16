/*
Pattern:
Binary Search

Initialize:

low = 0
high = n - 1
ans = INT_MAX

While:

low <= high

Find middle:

mid = low + (high - low) / 2

--------------------------------

Left Half Sorted?

arr[low] <= arr[mid]

Yes:

The minimum in this
half is arr[low].

Update:

ans = min(ans, arr[low])

Search Right Half:

low = mid + 1

--------------------------------

Otherwise:

Right half contains
the rotation point.

The minimum could be
arr[mid].

Update:

ans = min(ans, arr[mid])

Search Left Half:

high = mid - 1

Answer:

ans

Why does it work?

In a rotated sorted array,
at least one half is always sorted.

If the left half is sorted,

its smallest element is
arr[low].

Store it as a possible answer
and search the unsorted half,
where the rotation (and possibly
the minimum) exists.

If the left half isn't sorted,

the rotation point lies in
the left half, so arr[mid]
can be the minimum.

Time: O(log n)

Space: O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int  ans = INT_MAX;

        while( low <= high){
            int mid = (low + high)/2;

            if(nums[low] <= nums[mid]){
                ans = min(ans , nums[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans , nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};