/*
Pattern:
Array Traversal
Greedy

Initialize:

mini = prices[0]
profit = 0

Traverse array:

For each price:

Potential Profit =
currentPrice - mini

Update:

profit =
max(profit, potentialProfit)

Update minimum buying price:

mini =
min(mini, currentPrice)

Answer:
Maximum profit found

Why does it work?

For every day:

Assume we sell today.

Find the cheapest day
to buy before today.

Profit:

sellPrice - buyPrice

Keep track of the best
profit seen so far.

Time: O(n)

Space: O(1)*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;

        for(int i= 1;i<n;i++){

            int cost = (prices[i] - mini);

            profit = max(profit , cost);

            mini = min(mini , prices[i]);

        }
        return profit;
    }
};