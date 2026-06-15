/*
Problem: Majority Element II
Platform: LeetCode
Problem number: 229

Approach:
1. Use an extended version of Moore's Voting Algorithm.
2. Since an element must appear more than n/3 times,
   there can be at most 2 such elements.
3. Maintain:
   - candidate1, count1
   - candidate2, count2
4. Traverse the array:
   - If current number matches a candidate,
     increase its count.
   - If a count becomes 0,
     replace that candidate.
   - Otherwise, decrease both counts.
5. After the first pass,
   we get potential candidates.
6. Verify their actual frequencies
   in a second pass.

Key Idea:
For n/3 majority elements,
there can be at most 2 valid answers.

Why?

Suppose there were 3 elements each appearing
more than n/3 times.

Their total frequency would exceed n:

n/3 + n/3 + n/3 > n

which is impossible.

Therefore,
we only need to track 2 candidates.

Example:

nums = [3,2,3]

candidate1 = 3
count1 = 1

candidate2 = 2
count2 = 1

3 again:
count1 = 2

Verification:

3 → frequency = 2
2 → frequency = 1

n = 3

Required:
more than floor(3/3) = 1

Answer:
[3]

Visualization:

Think of cancelling groups
of three different numbers.

Example:

1 2 3 1 2 3 1 1

Cancel:

1 2 3

Remaining:

1 2 3 1 1

Cancel:

1 2 3

Remaining:

1 1

Majority candidate survives.

Pattern:
Moore's Voting Algorithm
Greedy

Time Complexity: O(n)

Space Complexity: O(1)

Why Verification Pass?

The first pass only gives
possible candidates.

It does NOT guarantee that
they occur more than n/3 times.

Therefore, a second pass is needed
to count their actual frequencies.

Revision:

Maintain:

candidate1, count1
candidate2, count2

If matches candidate:
    count++

Else if count == 0:
    replace candidate

Else:
    count1--
    count2--

Second Pass:
Count frequencies

Return candidates
with frequency > n/3
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       int ele1 = INT_MIN , ele2 = INT_MIN;
       int count1 = 0, count2 = 0;

       for(int i =0;i<n;i++){
        if(count1 == 0 && ele2 != nums[i]) {
            count1 = 1;
            ele1 = nums[i];
        }
        else if(count2 == 0 && ele1 != nums[i]){
            count2 = 1;
            ele2 = nums[i];
        }
        else if(ele1 == nums[i]) count1 ++;
        else if(ele2 == nums[i]) count2 ++;
        
        else{
            count1 --;
            count2 --;
        }
       }
       vector<int> ls;
        count1 = 0 , count2 = 0;

       for(int i =0; i< n; i++){
        if(ele1 == nums[i]) count1 ++;
        if(ele2 == nums[i]) count2 ++;
       }
       int mini = (int)(n/3) +1;
       if(count1 >= mini) ls.push_back(ele1);
       if(count2 >= mini) ls.push_back(ele2);
    
       return ls;
    }
        
};