# Find the Index of the First Occurrence in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

 

 **Example 1:** 

```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

```

 **Example 2:** 

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

```

 

 **Constraints:** 

- 1 <= haystack.length, needle.length <= 104
- haystack and needle consist of only lowercase English characters.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 25.15%)  
**Memory:** 9.5 MB (beats 9.06%)  
**Submitted:** 2026-11-01T12:28:18.227Z  

```cpp

class Solution {
public:

    void lpsfind(vector<int>& lps, string s) {

        int pre = 0, suf = 1;

        while(suf < s.size())
        {
            // Match
            if(s[pre] == s[suf])
            {
                lps[suf] = pre + 1;
                suf++;
                pre++;
            }
            // Not Match
            else
            {
                if(pre == 0)
                {
                    lps[suf] = 0;
                    suf++;
                }
                else
                {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {

        if(needle.empty())
            return 0;

        vector<int> lps(needle.size(), 0);

        lpsfind(lps, needle);

        int first = 0, second = 0;

        while(first < haystack.size() &&
              second < needle.size())
        {
            // Match
            if(haystack[first] == needle[second])
            {
                first++;
                second++;
            }
            // Not Match
            else
            {
                if(second == 0)
                    first++;
                else
                    second = lps[second - 1];
            }
        }

        // Answer exists
        if(second == needle.size())
            return first - second;

        return -1;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)