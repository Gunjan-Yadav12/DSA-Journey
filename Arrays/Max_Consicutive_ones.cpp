/*
Pattern:
Array Traversal
Counting

Initialize:

count = 0
maximum = 0

Traverse array:

If current element is 1:

count++

Update:

maximum =
max(maximum, count)

If current element is 0:

Reset:

count = 0

Answer:
maximum

Why does it work?

A streak of consecutive 1's
continues until a 0 is found.

When a 0 appears,
the current streak ends,
so reset the count.

Keep track of the longest
streak seen so far.

Time: O(n)

Space: O(1)
*/




class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maximum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count ++;
                maximum = max(count , maximum);
            }
            else count = 0;
        }
        return maximum;
    }
};