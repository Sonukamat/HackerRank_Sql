# weather-observation-station-16

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Query the smallest *Northern Latitude* (*LAT\_N*) from **STATION** that is greater than $38.7780$. Round your answer to $4$ decimal places.

**Input Format**

The **STATION** table is described as follows:

<img src="https://s3.amazonaws.com/hr-challenge-images/9336/1449345840-5f0a551030-Station.jpg" title="Station.jpg" />

where *LAT\_N* is the northern latitude and *LONG\_W* is the western longitude. 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T12:53:39.304Z  

```sql
/*
Enter your query here.
*/
SELECT ROUND(MIN(LAT_N),4)
FROM STATION
WHERE LAT_N > 38.7780;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/weather-observation-station-16/problem)