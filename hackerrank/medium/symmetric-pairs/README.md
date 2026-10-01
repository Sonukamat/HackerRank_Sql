# Placements

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a table, <em>Functions</em>, containing two columns: <em>X&nbsp;</em>and <em>Y</em>.

<img src="https://s3.amazonaws.com/hr-challenge-images/12892/1443818798-51909e977d-1.png" />

Two pairs <em>(X<sub>1</sub>, Y<sub>1</sub>)</em> and <em>(X<sub>2</sub>, Y<sub>2</sub>)</em> are said to be <em>symmetric</em> <em>pairs</em> if&nbsp;<em>X<sub>1</sub> = Y<sub>2</sub></em> and <em>X<sub>2</sub> = Y<sub>1</sub></em>.

Write a query to output all such <em>symmetric</em> <em>pairs</em> in ascending order by the value of <em>X</em>.  List the rows such that <em>X<sub>1</sub> &le; Y<sub>1</sub></em>.  

__Sample Input__

<img src="https://s3.amazonaws.com/hr-challenge-images/12892/1443818693-b384c24e35-2.png" />

__Sample Output__

    20 20
    20 21
    22 23

**Input Format**

 

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-01T11:27:48.914Z  

```sql
/*
Enter your query here.
*/
SELECT S.NAME
FROM STUDENTS S
JOIN FRIENDS F
    ON S.ID = F.ID
JOIN PACKAGES P1
    ON S.ID = P1.ID
JOIN PACKAGES P2
    ON F.FRIEND_ID = P2.ID
WHERE P2.SALARY > P1.SALARY
ORDER BY P2.SALARY;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/symmetric-pairs/problem)