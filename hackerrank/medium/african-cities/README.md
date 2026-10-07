# african-cities

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the **CITY** and **COUNTRY** tables, query the names of all cities where the *CONTINENT* is *'Africa'*.	

**Note:** *CITY.CountryCode* and *COUNTRY.Code* are matching key columns.

**Input Format**

The **CITY** and **COUNTRY** tables are described as follows:
<img src="https://s3.amazonaws.com/hr-challenge-images/8137/1449729804-f21d187d0f-CITY.jpg" title="CITY.jpg" />

<img src="https://s3.amazonaws.com/hr-challenge-images/8342/1449769013-e54ce90480-Country.jpg" title="Country.jpg" />

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T17:19:38.169Z  

```sql
SELECT SUM(CITY.POPULATION)
FROM CITY
JOIN COUNTRY
ON CITY.CountryCode =COUNTRY.Code 
WHERE COUNTRY.CONTINENT='Asia';

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/african-cities/problem)