/*
Pattern:
String Traversal
Vertical Scanning

Initialize:

ans = ""

Take the first string
as the reference.

Traverse each character
of the first string.

For every character:

Compare it with the
same index in all
other strings.

If:

Current index exceeds
the length of any string

OR

Characters don't match

Return the current prefix.

Otherwise:

Append the character
to the answer.

Continue until all
characters are checked.

Answer:

Longest Common Prefix

Why does it work?

Every string must share
the same character at
the same position to be
part of the common prefix.

The first mismatch
immediately ends the prefix.

Time: O(n × m)

n = Number of strings
m = Length of the shortest prefix checked

Space: O(1)
(excluding the output string)
*/




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty())
            return "";

        string ans = "";

        for (int i = 0; i < strs[0].size(); i++) {

            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {

                if (i >= strs[j].size() || strs[j][i] != ch)
                    return ans;
            }

            ans += ch;
        }

        return ans;
    }
};