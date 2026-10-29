# what-type-of-triangle

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write a query identifying the *type* of each record in the **TRIANGLES** table using its three side lengths. Output one of the following statements for each record in the table:

- **Equilateral**: It's a triangle with $3$ sides of equal length.
- **Isosceles**: It's a triangle with $2$ sides of equal length.
- **Scalene**: It's a triangle with $3$ sides of differing lengths.
- **Not A Triangle**: The given values of *A*, *B*, and *C* don't form a triangle.

**Input Format**

The **TRIANGLES** table is described as follows:

<img src="https://s3.amazonaws.com/hr-challenge-images/12887/1443815629-ac2a843fb7-1.png" />

Each row in the table denotes the lengths of each of a triangle's three sides.

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T13:03:30.298Z  

```sql
/*
Enter your query here.
*/

SELECT Start_Date, MIN(End_Date)
FROM
    (SELECT Start_Date
     FROM Projects
     WHERE Start_Date NOT IN (
         SELECT End_Date FROM Projects
     )) AS S,
    (SELECT End_Date
     FROM Projects
     WHERE End_Date NOT IN (
         SELECT Start_Date FROM Projects
     )) AS E
WHERE Start_Date < End_Date
GROUP BY Start_Date
ORDER BY DATEDIFF(MIN(End_Date), Start_Date), Start_Date;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/what-type-of-triangle/problem)