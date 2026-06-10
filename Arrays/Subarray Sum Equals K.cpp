/*
Problem: Subarray Sum Equals K
Platform: LeetCode

Approach:
1. Maintain a running prefix sum while traversing the array.
2. For every prefix sum, calculate:
      prefixSum - k
3. If this value has appeared before,
   then a subarray with sum k exists.
4. Store the frequency of every prefix sum
   in a map.
5. Add the frequency of (prefixSum - k)
   to the answer.

Key Idea:
Suppose:

Current Prefix Sum = P
Previous Prefix Sum = X

If the subarray between them has sum k:

P - X = k

Therefore:

X = P - k

So whenever we find a previously seen
(P - k), we have found a valid subarray.

Example:

nums = [1, 2, 3]
k = 3

Prefix Sums:
1, 3, 6

At prefix = 3:
Need (3 - 3) = 0
Found once → count = 1

At prefix = 6:
Need (6 - 3) = 3
Found once → count = 2

Subarrays:
[1,2]
[3]

Answer = 2

Pattern:
Prefix Sum
Hash Map

Time Complexity: O(n)
Space Complexity: O(n)

Important:
mpp[0] = 1

This represents a prefix sum of 0
before the array starts.

It allows us to count subarrays
that begin from index 0.

Revision:
prefixSum += nums[i]

Need:
prefixSum - k

If found:
count += frequency

Store:
mpp[prefixSum]++
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>mpp;
        int prefixSum = 0;
        int count = 0;
        mpp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            count += mpp[remove];
            mpp[prefixSum] += 1;
        }
        return count;
    }
};