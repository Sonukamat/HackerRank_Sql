# Top Competitors

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Julia just finished conducting a coding contest, and she needs your help assembling the leaderboard! Write a query to print the respective _hacker\_id_ and _name_ of hackers who achieved full scores for *more than one* challenge. Order your output in descending order by the total number of challenges in which the hacker earned a full score. If more than one hacker received full scores in same number of challenges, then sort them by ascending _hacker\_id_.

----

**Input Format**

The following tables contain contest data:

- _Hackers:_ The _hacker\_id_ is the id of the hacker, and _name_ is the name of the hacker. <img src="https://s3.amazonaws.com/hr-challenge-images/19504/1458526776-67667350b4-ScreenShot2016-03-21at7.45.59AM.png"/>

- _Difficulty:_ The _difficult\_level_ is the level of difficulty of the challenge,  and _score_ is the maximum score that can be achieved for a challenge at that difficulty level. <img src="https://s3.amazonaws.com/hr-challenge-images/19504/1458526915-57eb75d9a2-ScreenShot2016-03-21at7.46.09AM.png"/>

- _Challenges:_ The _challenge\_id_ is the id of the challenge, the _hacker\_id_ is the id of the hacker who created the challenge, and _difficulty\_level_ is the level of difficulty of the challenge. <img src="https://s3.amazonaws.com/hr-challenge-images/19504/1458527032-f9ca650442-ScreenShot2016-03-21at7.46.17AM.png"/>

- _Submissions:_ The _submission\_id_ is the id of the submission, _hacker\_id_ is the id of the hacker who made the submission, _challenge\_id_ is the id of the challenge that the submission belongs to, and _score_ is the score of the submission. <img src="https://s3.amazonaws.com/hr-challenge-images/19504/1458527077-298f8e922a-ScreenShot2016-03-21at7.46.29AM.png"/>

----

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T17:43:53.169Z  

```sql
/*
Enter your query here.
*/
SELECT h.hacker_id, h.name
FROM Hackers h
JOIN Submissions s
    ON h.hacker_id = s.hacker_id
JOIN Challenges c
    ON s.challenge_id = c.challenge_id
JOIN Difficulty d
    ON c.difficulty_level = d.difficulty_level
WHERE s.score = d.score
GROUP BY h.hacker_id, h.name
HAVING COUNT(DISTINCT s.challenge_id) > 1
ORDER BY COUNT(DISTINCT s.challenge_id) DESC,
         h.hacker_id ASC;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/full-score/problem)