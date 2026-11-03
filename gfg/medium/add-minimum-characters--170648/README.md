# Add Minimum Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string  **str**, find the minimum characters to be added at front of the string to make it a palindrome.

 **Example 1:** 

```
Input:
str = ABCD
Output: 3
Explanation: The resultant string 
after adding 3 characters is DCBABCD.
The minimum possible answer is 3.

```

 **Example 2:** 

```
Input:
str = ABA
Output: 0
Explanation: The given string
is already a palindrome.
```

 **Your Task:** 
You don't need to read input or print anything. Your task is to complete the function  **addMinChar()**  which takes the string  **str**  as input parameters and returns the minimum number of characters to be added to make it a palindrome.

 **Expected Time Complexity:**  O(**|** str **|**)
 **Expected Auxiliary Space:**  O(**|** str **|**)

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-03T09:24:47.559Z  

```cpp
class Solution {
  public:
    int addMinChar(string str) {

        // Step 1: Store original length
        int size = str.length();

        // Step 2: Reverse the string
        string rev = str;
        reverse(rev.begin(), rev.end());

        // Step 3: Combine original + separator + reverse
        string s = str + "$" + rev;

        // Step 4: Create LPS array
        int n = s.length();
        vector<int> lps(n, 0);

        int pre = 0;
        int suf = 1;

        // Step 5: Build LPS array using KMP
        while (suf < n) {

            // Characters match
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }

            // Characters do not match
            else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                }
                else {
                    pre = lps[pre - 1];
                }
            }
        }

        // Step 6: Calculate minimum characters to add
        return size - lps[n - 1];
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/add-minimum-characters--170648/1)