/*
Pattern:
Two Pointers
In-Place Array Modification

Initialize:

i = 0

Traverse array:

j = 1 to n-1

If:

nums[j] != nums[i]

A new unique element is found.

Place it at:

nums[i + 1] = nums[j]

Move:

i++

Continue until end of array.

Answer:

i + 1

Why does it work?

Since the array is already sorted,
all duplicate elements are adjacent.

The slow pointer (i) keeps track
of the last unique element.

The fast pointer (j) searches
for the next unique element.

Whenever a new unique element is found,
place it immediately after the last
unique element.

Time: O(n)

Space: O(1)
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for(int j=1; j<n;j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};