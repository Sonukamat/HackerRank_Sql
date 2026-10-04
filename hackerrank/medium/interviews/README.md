# interviews

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Samantha interviews many candidates from different colleges using coding challenges and contests. Write a query to print the _contest\_id_, _hacker\_id_, _name_, and the sums of _total\_submissions_, _total\_accepted\_submissions_, _total\_views_, and _total\_unique\_views_ for each contest sorted by _contest\_id_. Exclude the contest from the result if all four sums are $0$.

**Note:** A specific contest can be used to screen candidates at more than one college, but each college only holds $1$ screening contest.

----

**Input Format**

The following tables hold interview data:

- _Contests:_ The _contest\_id_ is the id of the contest, _hacker\_id_ is the id of the hacker who created the contest, and _name_ is the name of the hacker. <img src="https://s3.amazonaws.com/hr-challenge-images/19596/1458517426-e017c3460e-ScreenShot2016-03-21at4.57.47AM.png"/>

- _Colleges:_ The _college\_id_ is the id of the college, and _contest\_id_ is the id of the contest that Samantha used to screen the candidates. <img src="https://s3.amazonaws.com/hr-challenge-images/19596/1458517503-fd4aa63111-ScreenShot2016-03-21at4.57.56AM.png"/>

- _Challenges:_ The _challenge\_id_ is the id of the challenge that belongs to one of the contests whose contest_id Samantha forgot, and _college\_id_ is the id of the college where the challenge was given to candidates. <img src="https://s3.amazonaws.com/hr-challenge-images/19596/1458517661-a642f750ce-ScreenShot2016-03-21at4.58.04AM.png"/>

- _View\_Stats:_ The _challenge\_id_ is the id of the challenge, _total\_views_ is the number of times the challenge was viewed by candidates, and _total\_unique\_views_ is the number of times the challenge was viewed by unique candidates. <img src="https://s3.amazonaws.com/hr-challenge-images/19596/1458517983-b4302286a8-ScreenShot2016-03-21at4.58.15AM.png"/>

- _Submission\_Stats:_ The _challenge\_id_ is the id of the challenge, _total\_submissions_ is the number of submissions for the challenge, and _total\_accepted\_submission_ is the number of submissions that achieved full scores. <img src="https://s3.amazonaws.com/hr-challenge-images/19596/1458518090-80983c916a-ScreenShot2016-03-21at4.58.27AM.png"/>

----

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T09:58:56.020Z  

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

[View on HackerRank](https://www.hackerrank.com/challenges/interviews/problem)