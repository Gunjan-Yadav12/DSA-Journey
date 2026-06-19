/*
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode

Approach:
1. Use two pointers:
   - left = start of window
   - right = end of window

2. Maintain a Hash Set containing all
   characters currently inside the window.

3. Expand the window by moving right.

4. If the current character already exists
   in the set:
   - Remove characters from the left side
     until the duplicate is removed.

5. Insert the current character into the set.

6. Update the maximum window size.

7. Continue until the entire string
   is processed.

Key Idea:
Maintain a window where every character
is unique.

If a duplicate appears,
shrink the window until it becomes valid again.

Example:

s = "abcabcbb"

Window Progress:

"a"
Length = 1

"ab"
Length = 2

"abc"
Length = 3

"abca"

Duplicate 'a' found

Remove from left:

"bca"

Continue...

Maximum Length = 3

Pattern:
Sliding Window
Hash Set

Time Complexity: O(n)

Space Complexity: O(min(n, charset))

Why O(n)?

Each character:
- enters the window once
- leaves the window once

Therefore total operations
are proportional to n.

Revision:

Expand:
right++

Duplicate Found?

while(set contains currentChar)
{
    remove left character
    left++
}

Insert current character

Update:

maxLength =
max(maxLength,
    right-left+1)
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>Set;
        int count = 0;
        int left = 0;
        for(int right=0; right<s.size(); right++){
            while(Set.count(s[right])){
                Set.erase(s[left]);
                left++;
            }
            Set.insert(s[right]);
            count = max(count,right-left+1);
        }
    return count;
    }
};






class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>Set;
        int count = 0;
        int left = 0;
        for(int right=0; right<s.size(); right++){
            while(Set.count(s[right])){
                Set.erase(s[left]);
                left++;
            }
            Set.insert(s[right]);
            count = max(count,right-left+1);
        }
    return count;
    }
};