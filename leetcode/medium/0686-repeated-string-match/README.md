# Repeated String Match

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two strings `a` and `b`, return  *the minimum number of times you should repeat string* `a` *so that string*  `b`  *is a substring of it*. If it is impossible for `b`​​​​​​ to be a substring of `a` after repeating it, return `-1`.

 **Notice:**  string `"abc"` repeated 0 times is `""`, repeated 1 time is `"abc"` and repeated 2 times is `"abcabc"`.

 

 **Example 1:** 

```
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

```

 **Example 2:** 

```
Input: a = "a", b = "aa"
Output: 2

```

 

 **Constraints:** 

- 1 <= a.length, b.length <= 104
- a and b consist of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 65.36%)  
**Memory:** 10.8 MB (beats 21.59%)  
**Submitted:** 2026-11-03T09:58:40.993Z  

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

    int KMP_MATCH(string haystack, string needle) {

        

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
        return 1;

        return 0;
    }



    int repeatedStringMatch(string a, string b) {

        if(a==b)
        return 1;

        int repeat =1;
        string temp=a;
        while(temp.size()<b.size())
        {
            temp+=a;
            repeat++;
        }
        //KMP pattern search
        if(KMP_MATCH(temp,b)==1)
        return repeat;
        // Temp+a , KMP search
        if(KMP_MATCH(temp+a,b)==1)
        return repeat+1;

        return -1;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/repeated-string-match/)