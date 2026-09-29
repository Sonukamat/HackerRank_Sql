# Weather Observation Station 4

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Query the two cities in **STATION** with the shortest and longest *CITY* names, as well as their respective lengths (i.e.: number of characters in the name). If there is more than one smallest or largest city, choose the one that comes first when ordered alphabetically.  
The **STATION** table is described as follows:

<img src="https://s3.amazonaws.com/hr-challenge-images/9336/1449345840-5f0a551030-Station.jpg" title="Station.jpg" />

where **LAT\_N** is the northern latitude and **LONG\_W** is the western longitude.


**Input Format**

 

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-29T17:13:27.671Z  

```sql
/*
Enter your query here.
*/
select count(CITY)-count(distinct CITY)
from STATION;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/weather-observation-station-5/problem)