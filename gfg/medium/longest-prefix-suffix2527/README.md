# Longest Prefix Suffix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string  **s**, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.
 **Note:**  Prefix and suffix can be overlapping but they should not be equal to the entire string.

 **Examples :** 

```
Input: s = "abab"
Output: 2
Explanation: The string "ab" is the longest prefix and suffix. 
```

```
Input: s = "aabcdaabc"
Output: 4
Explanation: The string "aabc" is the longest prefix and suffix.

```

```
Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest prefix and suffix. 
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-31T06:04:20.517Z  

```cpp

class Solution {
public:
    int getLPSLength(string &s) {

        vector<int> lps(s.size(), 0);

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

        return lps[s.size() - 1];
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1)