/*
Pattern:
Binary Search

Floor:

Find the largest element

<= x

Initialize:

low = 0
high = n - 1
ans = -1

While:

low <= high

mid = low + (high - low) / 2

If:

nums[mid] <= x

Store possible floor:

ans = nums[mid]

Search Right Half:

low = mid + 1

Else:

Search Left Half:

high = mid - 1

--------------------------------

Ceil:

Find the smallest element

>= x

Initialize:

low = 0
high = n - 1
ans = -1

While:

low <= high

mid = low + (high - low) / 2

If:

nums[mid] >= x

Store possible ceil:

ans = nums[mid]

Search Left Half:

high = mid - 1

Else:

Search Right Half:

low = mid + 1

Answer:

{Floor, Ceil}

Why does it work?

Floor:

Whenever an element is
<= x, it can be the answer.

But there might be a larger
valid element on the right,
so continue searching right.

Ceil:

Whenever an element is
>= x, it can be the answer.

But there might be a smaller
valid element on the left,
so continue searching left.

Time: O(log n)

Space: O(1)
*/


class Solution {
public:
    int floor(vector<int>&nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] <= x){
                ans = nums[mid];
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    int ceil(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] >= x){
                ans = nums[mid];
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        
        int Floor = floor(nums , x);
        int Ceil = ceil(nums , x);

        return {Floor , Ceil};

    }
};