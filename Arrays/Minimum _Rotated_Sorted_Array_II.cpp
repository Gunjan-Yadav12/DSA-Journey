/*
Pattern:
Binary Search
Handle Duplicates

Initialize:

low = 0
high = n - 1
ans = INT_MAX

While:

low <= high

Find middle:

mid = low + (high - low) / 2

Update:

ans = min(ans, nums[mid])

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

Left Half Sorted?

nums[low] <= nums[mid]

Yes:

Minimum of this half
is nums[low].

Update:

ans = min(ans, nums[low])

Search Right Half:

low = mid + 1

--------------------------------

Otherwise:

Rotation lies in
the left half.

nums[mid] can be
the minimum.

Update:

ans = min(ans, nums[mid])

Search Left Half:

high = mid - 1

Answer:

ans

Why does it work?

Without duplicates,
one half is always
clearly sorted.

With duplicates like:

[2,2,2,0,1]

or

[1,1,1,1]

we may not know
which half is sorted.

When:

nums[low] == nums[mid] == nums[high]

both halves look identical.

So we shrink the search
space by moving both
pointers inward.

Once duplicates are removed,
the normal binary search
logic applies.

Time:

Average: O(log n)

Worst Case: O(n)
(due to many duplicates)

Space: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high)/2;
            ans = min(ans , nums[mid]);
               
            //narrow down duplicates 
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low ++;
                high --;
                continue;
            }
            //left half sorted 
            else if(nums[low] <= nums[mid]){
                ans = min(ans , nums[low]);
                low = mid + 1;
            }
            //right half sorted
            else{
                ans = min(ans , nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};