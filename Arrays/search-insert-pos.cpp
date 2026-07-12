/*
Pattern:
Binary Search
Lower Bound

Initialize:

low = 0
high = n - 1
ans = n

While:

low <= high

Find middle:

mid = low + (high - low) / 2

If:

nums[mid] >= target

Store possible answer:

ans = mid

Search Left Half:

high = mid - 1

Else:

Search Right Half:

low = mid + 1

Answer:

ans

Why does it work?

We are looking for the
first position where

nums[index] >= target.

If target exists,
its index is returned.

If target doesn't exist,
the first element greater
than target becomes the
correct insertion position.

If every element is
smaller than target,

ans remains n,

meaning insert at the end.

Time: O(log n)

Space: O(1)
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};