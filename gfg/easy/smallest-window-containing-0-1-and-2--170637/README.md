# Smallest Window With 0, 1 and 2

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string  **s**  consisting only of the characters ' **0'**, ' **1'**  and ' **2'**, determine the length of the smallest substring that contains all three characters at least once.

If no such substring exists, return  **-1**.

 **Examples :** 

```
Input: s = "10212"
Output: 3
Explanation: The substring "102" is the shortest substring that contains all three characters '0', '1', and '2', so the answer is 3.
```

```
Input: s = "12121"
Output: -1
Explanation: The character '0' is not present in the string, so no substring can contain all three characters '0', '1', and '2'. Hence, the answer is -1.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T06:52:26.627Z  

```cpp

class Solution {
public:
    int smallestSubstring(string &s) {

        // Frequency of characters 0, 1 and 2
        int count[3] = {0};

        int start = 0;
        int ans = INT_MAX;

        // Expand the sliding window
        for (int end = 0; end < s.size(); end++) {

            // Include current character
            count[s[end] - '0']++;

            // Shrink window while all three characters exist
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {

                // Update minimum window length
                ans = min(ans, end - start + 1);

                // Remove the starting character
                count[s[start] - '0']--;

                // Move start forward
                start++;
            }
        }

        // Return -1 if no valid substring exists
        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1)