/*
Problem: Rearrange Array Elements by Sign
Platform: LeetCode
problem number: 2149

Approach:
1. Create a new array of the same size.
2. Maintain:
   - posIndex = 0 (even positions)
   - negIndex = 1 (odd positions)
3. Traverse the original array:
   - If the number is positive,
     place it at posIndex and move posIndex by 2.
   - If the number is negative,
     place it at negIndex and move negIndex by 2.
4. Return the rearranged array.

Key Idea:
The answer must look like:

Positive, Negative,
Positive, Negative,
Positive, Negative...

Since:
- Positive numbers belong at even indices.
- Negative numbers belong at odd indices.

We can directly place each number
in its correct position.

Example:

nums = [3,1,-2,-5,2,-4]

Initial:

ans = [_,_,_,_,_,_]

posIndex = 0
negIndex = 1

Place 3:

[3,_,_,_,_,_]

posIndex = 2

Place 1:

[3,_,1,_,_,_]

posIndex = 4

Place -2:

[3,-2,1,_,_,_]

negIndex = 3

Place -5:

[3,-2,1,-5,_,_]

negIndex = 5

Place 2:

[3,-2,1,-5,2,_]

Place -4:

[3,-2,1,-5,2,-4]

Answer:
[3,-2,1,-5,2,-4]

Pattern:
Array Manipulation
Simulation

Time Complexity: O(n)

Space Complexity: O(n)

Why Even and Odd Indices?

Required pattern:

Index:
0 1 2 3 4 5

Sign:
+ - + - + -

Even indices:
Positive

Odd indices:
Negative

This allows direct placement
without extra checks.

Revision:

Positive:
ans[posIndex] = num
posIndex += 2

Negative:
ans[negIndex] = num
negIndex += 2

Return ans
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans (n , 0);
        int posIndex = 0;
        int negIndex = 1;

        for(int  i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex +=2;
            }
        }
        return ans;
    }
};