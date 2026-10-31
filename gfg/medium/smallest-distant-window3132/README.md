# Smallest Window Length with All

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string  **s,**  your task is to find the length of the smallest window that contains all the characters of the given string at least once.

 **Example:** 

```
Input: s = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of string s.

```

```
Input: s = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of string s.
```

```
Input: s = "geeksforgeeks"
Output: 7
Explanation: There are multiple substring with smallest length that contains all characters of string s, "eksforg" and "ksforge". 
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T05:01:54.225Z  

```cpp

class Solution {
public:
    int findSubString(string& s) {

        vector<int> count(256, 0);
        int first = 0, second = 0;
        int len = s.size(), diff = 0;

        // Calculate total unique characters
        while(first < s.size())
        {
            if(count[s[first]] == 0)
                diff++;

            count[s[first]]++;
            first++;
        }

        // Reset frequency array
        for(int i = 0; i < 256; i++)
            count[i] = 0;

        first = 0;

        // Sliding window
        while(second < s.size())
        {
            // Expand window until all unique characters are present
            while(diff && second < s.size())
            {
                if(count[s[second]] == 0)
                    diff--;

                count[s[second]]++;
                second++;
            }

            // Update minimum length
            if(diff == 0)
                len = min(len, second - first);

            // Shrink window
            while(diff == 0)
            {
                len = min(len, second - first);

                count[s[first]]--;

                if(count[s[first]] == 0)
                    diff++;

                first++;
            }
        }

        return len;
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1)