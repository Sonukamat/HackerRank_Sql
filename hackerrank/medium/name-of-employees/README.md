# Higher Than 75 Marks

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Write a query that prints a list of employee names (i.e.: the _name_ attribute) from the **Employee** table in alphabetical order.

**Input Format**

The **Employee** table containing employee data for a company is described as follows: 

<img src="https://s3.amazonaws.com/hr-challenge-images/19629/1458557872-4396838885-ScreenShot2016-03-21at4.27.13PM.png"/>

where _employee\_id_ is an employee's ID number, _name_ is their name, _months_ is the total number of months they've been working for the company, and _salary_ is their monthly salary.

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-30T13:46:05.877Z  

```sql
/*
Enter your query here.
*/
SELECT NAME
FROM STUDENTS
WHERE MARKS >75
ORDER BY RIGHT (NAME,3), ID ASC;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/name-of-employees/problem)