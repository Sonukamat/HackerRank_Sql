# 15-days-of-learning-sql

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Julia conducted a $15$ days of learning SQL contest. The start date of the contest was _March 01, 2016_ and the end date was _March 15, 2016_. 

Write a query to print total number of unique hackers who made at least $1$ submission each day (starting on the first day of the contest), and find the _hacker\_id_ and _name_ of the hacker who made maximum number of submissions each day. If more than one such hacker has a maximum number of submissions, print the lowest *hacker\_id*. The query should print this information for each day of the contest, sorted by the date.

----

**Input Format**

The following tables hold contest data:

- _Hackers:_ The _hacker\_id_ is the id of the hacker, and _name_ is the name of the hacker.<img src="https://s3.amazonaws.com/hr-challenge-images/19597/1458511164-12adec3b8b-ScreenShot2016-03-21at3.26.47AM.png"/>

- _Submissions:_ The _submission\_date_ is the date of the submission, _submission\_id_ is the id of the submission, _hacker\_id_ is the id of the hacker who made the submission, and _score_ is the score of the submission. <img src="https://s3.amazonaws.com/hr-challenge-images/19597/1458511251-0b534030b9-ScreenShot2016-03-21at3.26.56AM.png"/>

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T10:23:36.062Z  

```sql
/*
Enter your query here.
*/
SELECT
    s.submission_date,

    COUNT(DISTINCT CASE
        WHEN s.hacker_id IN (
            SELECT s2.hacker_id
            FROM Submissions s2
            WHERE s2.submission_date <= s.submission_date
            GROUP BY s2.hacker_id
            HAVING COUNT(DISTINCT s2.submission_date)
                   = DATEDIFF(s.submission_date, '2016-03-01') + 1
        )
        THEN s.hacker_id
    END) AS unique_hackers,

    (
        SELECT s3.hacker_id
        FROM Submissions s3
        WHERE s3.submission_date = s.submission_date
        GROUP BY s3.hacker_id
        ORDER BY COUNT(*) DESC, s3.hacker_id ASC
        LIMIT 1
    ) AS hacker_id,

    (
        SELECT h.name
        FROM Hackers h
        JOIN Submissions s4
            ON h.hacker_id = s4.hacker_id
        WHERE s4.submission_date = s.submission_date
        GROUP BY h.hacker_id, h.name
        ORDER BY COUNT(*) DESC, h.hacker_id ASC
        LIMIT 1
    ) AS name

FROM Submissions s
WHERE s.submission_date BETWEEN '2016-03-01' AND '2016-03-15'
GROUP BY s.submission_date
ORDER BY s.submission_date;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/15-days-of-learning-sql/problem)