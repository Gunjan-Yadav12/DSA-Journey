/*
Problem: Longest Consecutive Sequence
Platform: LeetCode
Problem number: 128

Approach:
1. Insert all numbers into a Hash Set.
2. For each number, check whether it is the
   start of a sequence.
3. A number is a start if (num - 1) does not
   exist in the set.
4. Once a start is found, keep checking
   num + 1, num + 2, num + 3 ...
   until the sequence breaks.
5. Track the maximum sequence length.

Key Idea:
Only start counting from the beginning
of a sequence.

If a number has a predecessor,
it cannot be the start.

Example:

nums = [100, 4, 200, 1, 3, 2]

Set:
{100, 4, 200, 1, 3, 2}

100:
99 not found
Start sequence
Length = 1

4:
3 exists
Not a start

200:
199 not found
Start sequence
Length = 1

1:
0 not found
Start sequence

1 → 2 → 3 → 4

Length = 4

Answer = 4

Pattern:
Hash Set
Sequence Detection

Time Complexity: O(n)
Space Complexity: O(n)

Why O(n)?
Each element is visited at most once
while expanding sequences.

Revision:
1. Put all numbers in a Hash Set.
2. Check only sequence starters.
3. Starter = num - 1 not present.
4. Expand forward.
5. Track maximum length.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1 ;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){ 
        st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it - 1) == st.end()){
                int count = 1;
                int x = it; 
                while(st.find(x+1) != st.end()){
                    count = count + 1;
                    x = x + 1;
                } 
                longest = max(count , longest);
            }

        }
        return longest;

    }
};