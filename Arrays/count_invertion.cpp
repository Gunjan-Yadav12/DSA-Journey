/*
Pattern:
Merge Sort
Divide and Conquer

Divide the array
into two halves.

Recursively count
inversions in:

Left Half

Right Half

During Merge:

Compare elements from
both sorted halves.

If:

left <= right

Take left element.

Else:

Take right element.

All remaining elements
in the left half are
greater than the current
right element.

So,

count +=
(mid - left + 1)

Continue merging
both halves.

Answer:

Left Count
+ Right Count
+ Merge Count

Why does it work?

Both halves are already sorted.

If:

nums[left] > nums[right]

then every element from
left to mid is also
greater than nums[right].

Hence all those pairs
form inversions.

Instead of counting one
by one, count them all
at once.

Time: O(n log n)

Space: O(n)
rever*/

class Solution {
public:
    long long int merge(vector<int>& nums, int low , int mid, int high ){
        vector<int>temp;
        int left = low;
        int right = mid + 1;
        long long  count  = 0;
        while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            count += (mid - left + 1);
            right ++;
        }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left ++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right ++;
        }
        for(int i=low ;i<=high;i++){
            nums[i] = temp[i - low];
        }
        return count;
    }
    long long int mergeSort(vector<int>&nums, int low , int high){
        long long count =0;
        if(low >= high) return count;
        int mid = low + (high - low)/2;
        count += mergeSort(nums , low , mid);
        count += mergeSort(nums, mid+1 , high);
        count += merge(nums, low , mid , high);
        return count;
    }
   long long int numberOfInversions(vector<int> nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};