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
