# Sort Vowels in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a  **0-indexed**  string `s`,  **permute**  `s` to get a new string `t` such that:

- All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
- The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].

Return  *the resulting string*.

The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 

 **Example 1:** 

```
Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.

```

 **Example 2:** 

```
Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists only of letters of the English alphabet in uppercase and lowercase.

## Solution

**Language:** C++  
**Runtime:** 11 ms (beats 77.97%)  
**Memory:** 16.4 MB (beats 50.99%)  
**Submitted:** 2026-10-22T16:49:28.913Z  

```cpp
class Solution {
public:
    string sortVowels(string s) {
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        for(int i=0;i<s.size();i++)
        {
            //lower a e i o u
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
           {
            lower[s[i]-'a']++;
            s[i]='#';
           }

            //upper A E I O U
           else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
           {
            upper[s[i]-'A']++;
            s[i]='#';
           }


        }

        string vowel;
        //upper
        for(int i=0;i<26;i++)
        {
            char c = 'A'+i;
            while(upper[i])
            {
                vowel+=c;
                upper[i]--;
            }
        } 
        //lower
        for(int i=0;i<26;i++)
        {
            char c = 'a'+i;
            while(lower[i])
            {
                vowel+=c;
                lower[i]--;
            }
        } 

        int first =0,second=0; //second point kar raha hai vowel ko

        while(second<vowel.size())
        {
            if(s[first]=='#')
            {
                s[first]=vowel[second];
                second++;
            }
            first++;
        }
        return s;

        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sort-vowels-in-a-string/)