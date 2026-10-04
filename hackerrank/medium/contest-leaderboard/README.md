# contest-leaderboard

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You did such a great job helping Julia with her last coding contest challenge that she wants you to work on this one, too! 

The total score of a hacker is the sum of their maximum scores for all of the challenges. Write a query to print the _hacker\_id_, _name_, and total score of the hackers ordered by the descending score. If more than one hacker achieved the same total score, then sort the result by ascending _hacker\_id_. Exclude all hackers with a total score of $0$ from your result.


**Input Format**

The following tables contain contest data:

- _Hackers:_ The _hacker\_id_ is the id of the hacker, and _name_ is the name of the hacker. <img src="https://s3.amazonaws.com/hr-challenge-images/19503/1458522826-a9ddd28469-ScreenShot2016-03-21at6.40.27AM.png"/>

- _Submissions:_ The _submission\_id_ is the id of the submission, _hacker\_id_ is the id of the hacker who made the submission, _challenge\_id_ is the id of the challenge for which the submission belongs to, and _score_ is the score of the submission. <img src="https://s3.amazonaws.com/hr-challenge-images/19503/1458523022-771511df90-ScreenShot2016-03-21at6.40.37AM.png"/>

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T10:23:50.871Z  

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

[View on HackerRank](https://www.hackerrank.com/challenges/contest-leaderboard/problem)