# Factorials of Large

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer  **n,**  find its factorial. Return a list of integers denoting the digits that make up the factorial of n.

 **Examples:** 

```
Input: n = 5
Output: [1, 2, 0]
Explanation: 5! = 1 *2* 3 *4* 5 = 120

```

```
Input: n = 10
Output: [3, 6, 2, 8, 8, 0, 0]
Explanation: 10! = 1 *2* 3 *4* 5 *6* 7 *8* 9*10 = 3628800

```

```
Input: n = 1
Output: [1]
Explanation: 1! = 1 
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-24T16:44:43.589Z  

```cpp
class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        vector<int>ans(1,1);
        
        while(n>1)
        {
            int carry =0,res,size=ans.size();
            for(int i=0;i<size;i++)
            {
                res = ans[i]*n+carry;
                ans[i]=res%10;
                carry = res/10;
            }
            while(carry)
            {
                ans.push_back(carry%10);
                carry/=10;
            }
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1)