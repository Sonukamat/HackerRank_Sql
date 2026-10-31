# Longest Substring with K Uniques

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string  **s**  consisting only lowercase alphabets and an integer  **k**. Your task is to find the  **length** of the  **longest substring**  that contains exactly  **k**  distinct characters.

 **Note :**  If no such substring exists, return  **-1**. 

 **Examples:** 

```
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

```

```
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.

```

```
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T07:00:01.022Z  

```cpp

class Solution {
public:
    int longestKSubstr(string &s, int k) {

        // Store frequency of 26 lowercase characters
        int count[26] = {0};

        // Starting pointer of sliding window
        int start = 0;

        // Count distinct characters
        int distinct = 0;

        // Store maximum substring length
        int ans = -1;

        // Expand window using end pointer
        for (int end = 0; end < s.size(); end++) {

            // Find index of current character
            int index = s[end] - 'a';

            // If character appears for the first time
            if (count[index] == 0) {
                distinct++;
            }

            // Increase character frequency
            count[index]++;

            // Shrink window if distinct characters exceed k
            while (distinct > k) {

                // Find index of starting character
                int leftIndex = s[start] - 'a';

                // Decrease its frequency
                count[leftIndex]--;

                // If frequency becomes zero, remove distinct character
                if (count[leftIndex] == 0) {
                    distinct--;
                }

                // Move start pointer forward
                start++;
            }

            // Update answer only when exactly k distinct characters exist
            if (distinct == k) {
                ans = max(ans, end - start + 1);
            }
        }

        // Return -1 if no valid substring exists
        return ans;
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)