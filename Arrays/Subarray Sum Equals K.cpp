/*
Problem: Subarray Sum Equals K
Platform: LeetCode

Approach:
1. Maintain a running prefix sum while traversing the array.
2. At each index, check if there exists a previous prefix sum
   equal to (currentPrefix - k).
3. If such a prefix sum exists, then the elements between
   those two positions form a subarray with sum k.
4. Store the frequency of every prefix sum in a hashmap.
5. Add the frequency of (currentPrefix - k) to the answer.

Key Idea:
If:

currentPrefix - previousPrefix = k

then:

previousPrefix = currentPrefix - k

So whenever we find a previously seen
(currentPrefix - k), we have found a valid subarray.

Example:

nums = [1, 1, 1]
k = 2

Prefix Sums:
1, 2, 3

At prefix = 2:
Need (2 - 2) = 0
Found once → count = 1

At prefix = 3:
Need (3 - 2) = 1
Found once → count = 2

Answer = 2

Pattern:
Prefix Sum
Hash Map

Time Complexity: O(n)
Space Complexity: O(n)

Revision:
prefix += nums[i]

Need:
prefix - k

If found in map:
count += frequency

Store:
mp[prefix]++
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        mp[0] = 1;

        int prefix = 0;
        int count = 0;

        for(int nums:nums){
            prefix += nums;

            if(mp.find(prefix - k) != mp.end ()){
                count += mp[prefix - k];
            }
            mp[prefix]++;
        }
        return count;
    }
};