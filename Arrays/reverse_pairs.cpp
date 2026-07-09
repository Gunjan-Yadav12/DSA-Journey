/*
Pattern:
Merge Sort
Divide and Conquer

Divide the array
into two halves.

Recursively count
reverse pairs in:

Left Half

Right Half

Before Merging:

Count cross reverse pairs.

Condition:

nums[i] > 2 * nums[j]

where:

i is in Left Half

j is in Right Half

Since both halves
are already sorted,

use a pointer:

right = mid + 1

For every element
in the left half:

Move right pointer
while:

nums[i] > 2 * nums[right]

Count:

right - (mid + 1)

After counting,

Merge both sorted halves.

Answer:

Left Count
+ Right Count
+ Cross Pair Count

Why does it work?

Both halves are sorted.

If:

nums[i] > 2 * nums[right]

then every element
before right has already
satisfied the condition.

So we can count all
valid pairs together
instead of checking
every combination.

Time: O(n log n)

Space: O(n)
*/



class Solution {
public:
    void merge(vector<int>& nums , int low , int mid , int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left ++;
            } 
            else{
                temp.push_back(nums[right]);
                right ++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left ++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low; i<=high;i++){
            nums[i] = temp[ i- low];
        }
    }
    int countPairs(vector<int>& nums, int low , int mid , int high){
        int count = 0;
        int right = mid + 1;
        for(int i=low;i<=mid;i++){
            while(right <= high && (long long)nums[i] > 2LL*nums[right]) right ++;
                count =  count + (right - (mid+1));
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int low , int high){
        int  count = 0;
        if(low >= high) return count;
        int mid = (low + high)/2;
        count += mergeSort(nums , low , mid);
        count += mergeSort(nums, mid+1 , high);
        count += countPairs(nums , low , mid , high);
        merge(nums, low , mid , high);

       return count;
    }
    int reversePairs(vector<int>& nums) {
     
       return  mergeSort(nums , 0 , nums.size()-1);
        
    }
};