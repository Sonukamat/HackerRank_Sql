# draw-the-triangle-1

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_P(R)_ represents a pattern drawn by Julia in _R_ rows. The following pattern represents _P(5)_:


    * * * * * 
    * * * * 
    * * * 
    * * 
    *

Write a query to print the pattern _P(20)_.


**Input Format**

 

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T16:41:39.074Z  

```sql
/*
Enter your query here.
*/
with recursive numbers as (
    select 20 as n 
    union all
    select n-1
    from numbers
    where n >1
)
select repeat('* ',n)
from numbers;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/draw-the-triangle-1/problem)