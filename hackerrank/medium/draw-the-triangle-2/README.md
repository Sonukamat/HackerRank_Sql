# draw-the-triangle-2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_P(R)_ represents a pattern drawn by Julia in _R_ rows. The following pattern represents _P(5)_:

    * 
    * * 
    * * * 
    * * * * 
    * * * * *

Write a query to print the pattern _P(20)_.


**Input Format**

 

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T16:46:51.986Z  

```sql
/*
Enter your query here.
*/
with recursive numbers(n) as
(
    select 1
    union all
    select n+1
    from numbers
    where n<20
)
select repeat('* ',n)
from numbers;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/draw-the-triangle-2/problem)