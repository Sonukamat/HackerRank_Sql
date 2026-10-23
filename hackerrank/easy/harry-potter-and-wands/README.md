# harry-potter-and-wands

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Harry Potter and his friends are at Ollivander's with Ron, finally replacing Charlie's old broken wand. 

Hermione decides the best way to choose is by determining the minimum number of gold galleons needed to buy each *non-evil* wand of high power and age. Write a query to print the _id_, _age_, _coins\_needed_, and _power_ of the wands that Ron's interested in, sorted in order of descending _power_. If more than one wand has same power, sort the result in order of descending _age_.

**Input Format**

The following tables contain data on the wands in Ollivander's inventory:

- _Wands:_ The _id_ is the id of the wand, _code_ is the code of the wand, _coins\_needed_ is the total number of gold galleons needed to buy the wand, and _power_ denotes the quality of the wand (the higher the power, the better the wand is). <img src="https://s3.amazonaws.com/hr-challenge-images/19502/1458538092-b2a8163a74-ScreenShot2016-03-08at12.13.39AM.png"/>

- _Wands\_Property:_ The _code_ is the code of the wand, _age_ is the age of the wand, and _is\_evil_ denotes whether the wand is good for the dark arts. If the value of _is\_evil_ is _0_, it means that the wand is not evil. The mapping between *code* and *age* is one-one, meaning that if there are two pairs, $(code_1,\ age_1)$ and $(code_2,\ age_2)$, then $code_1 \neq code_2$ and $age_1 \neq age_2$.<img src="https://s3.amazonaws.com/hr-challenge-images/19502/1458538221-18c4092b7d-ScreenShot2016-03-08at12.13.53AM.png"/>

----

**Constraints**

 

**Output Format**

## Solution

**Language:** SQL  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-23T17:00:09.904Z  

```sql
/*
Enter your query here.
*/

SELECT w.id, p.age, w.coins_needed, w.power
FROM Wands w
JOIN Wands_Property p
    ON w.code = p.code
JOIN (
    SELECT p.age, w.power, MIN(w.coins_needed) AS min_coins
    FROM Wands w
    JOIN Wands_Property p
        ON w.code = p.code
    WHERE p.is_evil = 0
    GROUP BY p.age, w.power
) AS m
    ON p.age = m.age
    AND w.power = m.power
    AND w.coins_needed = m.min_coins
WHERE p.is_evil = 0
ORDER BY w.power DESC, p.age DESC;

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/harry-potter-and-wands/problem)