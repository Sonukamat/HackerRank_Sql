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
**Submitted:** 2026-10-04T09:59:08.348Z  

```sql
/*
Enter your query here.
*/
SELECT
    c.contest_id,
    c.hacker_id,
    c.name,
    COALESCE(SUM(s.total_submissions), 0) AS total_submissions,
    COALESCE(SUM(s.total_accepted_submissions), 0) AS total_accepted_submissions,
    COALESCE(SUM(v.total_views), 0) AS total_views,
    COALESCE(SUM(v.total_unique_views), 0) AS total_unique_views
FROM Contests c
JOIN Colleges co
    ON c.contest_id = co.contest_id
JOIN Challenges ch
    ON co.college_id = ch.college_id

LEFT JOIN (
    SELECT
        challenge_id,
        SUM(total_submissions) AS total_submissions,
        SUM(total_accepted_submissions) AS total_accepted_submissions
    FROM Submission_Stats
    GROUP BY challenge_id
) s
    ON ch.challenge_id = s.challenge_id

LEFT JOIN (
    SELECT
        challenge_id,
        SUM(total_views) AS total_views,
        SUM(total_unique_views) AS total_unique_views
    FROM View_Stats
    GROUP BY challenge_id
) v
    ON ch.challenge_id = v.challenge_id

GROUP BY
    c.contest_id,
    c.hacker_id,
    c.name

HAVING
    total_submissions > 0
    OR total_accepted_submissions > 0
    OR total_views > 0
    OR total_unique_views > 0

ORDER BY c.contest_id;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/15-days-of-learning-sql/problem)