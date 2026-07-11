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

Return mid.

If:

nums[mid] < target

Search Right Half:

low = mid + 1

Else:

Search Left Half:

high = mid - 1

If target is not found:

Return -1

Why does it work?

The array is already sorted.

At every step,

compare the target
with the middle element.

Discard the half
where the target
cannot exist.

This reduces the search
space by half after
every iteration.

Time: O(log n)

Space: O(1)
*/



lass Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};