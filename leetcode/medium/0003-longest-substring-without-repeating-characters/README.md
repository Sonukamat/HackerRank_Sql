# Longest Substring Without Repeating Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, find the length of the  **longest**   **substring**  without duplicate characters.

 

 **Example 1:** 

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

```

 **Example 2:** 

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

 **Example 3:** 

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

 

 **Constraints:** 

- 0 <= s.length <= 105
- s consists of English letters, digits, symbols and spaces.

## Solution

**Language:** C++  
**Runtime:** 21 ms (beats 72.63%)  
**Memory:** 17.6 MB (beats 98.39%)  
**Submitted:** 2026-10-29T16:57:37.562Z  

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        vector<bool>count(256,0);
        int first =0,second =0,len=0;

        while(second<S.size())
        {
            // Repoting char
            while(count[S[second]])
            {
                count[S[first]]=0;
                first++;
            }
            count[S[second]]=1;
            len = max(len,second-first+1);
            second++;
        }
        return len;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)