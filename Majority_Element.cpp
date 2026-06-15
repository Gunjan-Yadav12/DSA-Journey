/*
Problem: Majority Element
Platform: LeetCode
Problem number: 169

Approach:
1. Maintain a candidate and a count.
2. If count becomes 0,
   choose the current element as the new candidate.
3. If the current element matches the candidate,
   increase count.
4. Otherwise, decrease count.
5. After traversing the array, the candidate
   will be the majority element.

Key Idea:
Treat different elements as cancelling
each other's votes.

Since the majority element appears more
than n/2 times, it can never be completely
cancelled out.

Example:

nums = [2,2,1,1,1,2,2]

candidate = 2
count = 1

2 -> count = 2

1 -> count = 1

1 -> count = 0

Choose new candidate:
candidate = 1
count = 1

1 -> count = 2

2 -> count = 1

2 -> count = 0

Choose new candidate:
candidate = 2
count = 1

Answer = 2

Visualization:

2 2 1 1 1 2 2

Pair Cancellation:

2 cancels 1
2 cancels 1

Remaining:

2 1 2 2

Again:

1 cancels 2

Remaining:

2 2

Majority survives.

Pattern:
Moore's Voting Algorithm
Greedy

Time Complexity: O(n)

Space Complexity: O(1)

Why Does It Work?

Majority Element:

frequency > n/2

All other elements combined:

frequency < n/2

Even after maximum cancellation,
the majority element still has
some occurrences left.

Revision:

count = 0

If count == 0:
    candidate = nums[i]

If candidate == nums[i]:
    count++

Else:
    count--

Answer:
candidate
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n  = nums.size();
        int count = 0, result = 0;

        for(int i = 0; i < n; i++){
            if(count == 0){
                result = nums[i];
            }
            if(result == nums[i]){
                count++;
            }
            else count--;
        }
        return result;
    }
};