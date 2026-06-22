/*
Pattern:
Two Pointers (Reverse Merge)

Initialize:

left = m - 1
right = n - 1
k = m + n - 1

Compare:

nums1[left]
nums2[right]

Place larger element at:

nums1[k]

Move corresponding pointer.

Continue until one array is exhausted.

If nums2 still has elements:
copy them into nums1.

Answer:
nums1 contains merged sorted array.

Why from the back?

Avoid overwriting valid elements
already present in nums1.

Time: O(m + n)

Space: O(1)
*/







class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int right =  n-1;
        int left = m-1;
        int k = n+m-1;

        while(left >=0 && right >= 0){
            if(nums1[left] > nums2[right]){
                nums1[k--] = nums1[left--];
            }
            else{
                nums1[k--] = nums2[right--];
            }
        }
        while(right >= 0){
            nums1[k--] = nums2[right--];
        }
        while(left >= 0){
            nums1[k--] = nums1[left--];
        }

    }
};