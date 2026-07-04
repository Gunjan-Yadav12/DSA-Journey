/*
Pattern:
Greedy
Simulation

Store Roman symbols
in descending order
along with their values.

Initialize:

result = ""

Traverse the Roman
value list.

For each symbol:

While:

num >= value

Append the symbol
to the answer.

Subtract its value
from num.

Continue until
num becomes 0.

Answer:

result

Why does it work?

Always choose the
largest possible Roman
symbol first.

This greedy choice
produces the correct
Roman numeral because
Roman numerals are built
using the largest valid
symbols before smaller ones.

Special cases like:

4  -> IV
9  -> IX
40 -> XL
90 -> XC
400 -> CD
900 -> CM

are included in the list,
so they are handled automatically.

Time: O(1)

Space: O(1)
*/

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string , int>> roman= {
            {"M",1000}, {"CM", 900}, {"D",500}, {"CD",400},
            {"C",100}, {"XC",90}, {"L",50}, {"XL",40},
            {"X",10}, {"IX",9}, {"V",5}, {"IV",4},
            {"I" , 1}
            };
        string result = "";

        for(auto& [symbol ,value]: roman){
            while(num >= value){
                result += symbol;
                num -= value;
            }
        }
         return result;
    }
};