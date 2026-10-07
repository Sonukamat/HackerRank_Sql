/*
Enter your query here.
*/
WITH RECURSIVE nums AS (
    SELECT 2 AS n
    UNION ALL
    SELECT n + 1
    FROM nums
    WHERE n < 1000
)
SELECT GROUP_CONCAT(n SEPARATOR '&')
FROM nums
WHERE n NOT IN (
    SELECT a.n
    FROM nums a
    JOIN nums b
      ON b.n < a.n
     AND a.n % b.n = 0
);
